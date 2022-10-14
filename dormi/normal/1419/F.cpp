#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e3+1;
pll points[MAXN];
vector<pair<ll,pii>> edges;
pii dsu[MAXN];
int n;
int find(int a){
   if(dsu[a].first==a)return a;
   return dsu[a].first=find(dsu[a].first);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
    return true;
}
void reset(){
    for(int i=0;i<n;i++)dsu[i]={i,1};
}
map<ll,vector<pair<ll,int>>> xc,yc;
bool work(ll time){
    reset();
    int cnt=0;
    for(auto x:edges){
        if(x.first>time)break;
        if(uni(x.second.first,x.second.second))cnt++;
    }
    if(cnt==n-1)return 1;
    if(cnt==n-2){
        for(int i=0;i<n;i++) {
            for (int j = 0; j < i; j++) {
                if(find(i)!=find(j)) {
                    if(points[i].first==points[j].first||points[i].second==points[j].second){
                        if((max(abs(points[i].first-points[j].first),abs(points[i].second-points[j].second))+1)/2<=time)return 1;
                    }
                    else if(max(abs(points[i].first-points[j].first),abs(points[i].second-points[j].second))<=time)return 1;
                }
            }
        }
        return 0;
    }
    if(cnt==n-3){
        for(int i=0;i<n;i++) {
            for(auto &&x:xc){
                int r=lower_bound(x.second.begin(),x.second.end(),pair<ll,int>{points[i].second,0})-x.second.begin(),l=r-1;
                if(l>=0&&r<sz(x.second)&&x.second[r].first!=points[i].second){
                    set<int> ps={find(i),find(x.second[l].second),find(x.second[r].second)};
                    if(sz(ps)==3){
                        if(max({abs(x.first-points[i].first),abs(points[i].second-x.second[l].first),abs(x.second[r].first-points[i].second)})<=time)return true;
                    }
                }
            }
            for(auto &&x:yc){
                int r=lower_bound(x.second.begin(),x.second.end(),pair<ll,int>{points[i].first,0})-x.second.begin(),l=r-1;
                if(l>=0&&r<sz(x.second)&&x.second[r].first!=points[i].first){
                    set<int> ps={find(i),find(x.second[l].second),find(x.second[r].second)};
                    if(sz(ps)==3){
                        if(max({abs(x.first-points[i].second),abs(points[i].first-x.second[l].first),abs(x.second[r].first-points[i].first)})<=time)return true;
                    }
                }
            }
        }
        return false;
    }
    else if(cnt==n-4){
        for(auto &&x:xc){
            for(auto &&y:yc){
                int rx=lower_bound(x.second.begin(),x.second.end(),pair<ll,int>{y.first,0})-x.second.begin(),lx=rx-1;
                int ry=lower_bound(y.second.begin(),y.second.end(),pair<ll,int>{x.first,0})-y.second.begin(),ly=ry-1;
                if(lx>=0&&rx<sz(x.second)&&x.second[rx].first!=y.first&&ly>=0&&ry<sz(y.second)){
                    set<int> ps={find(x.second[lx].second),find(x.second[rx].second),find(y.second[ly].second),find(y.second[ry].second)};
                    if(sz(ps)==4){
                        if(max({abs(x.first-y.second[ly].first),abs(x.first-y.second[ry].first),abs(y.first-x.second[lx].first),abs(y.first-x.second[rx].first)})<=time)return true;
                    }
                }
            }
        }
        return false;
    }
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>points[i].first>>points[i].second;
        xc[points[i].first].push_back({points[i].second,i}),yc[points[i].second].push_back({points[i].first,i});
        for(int j=0;j<i;j++){
            if(points[i].first==points[j].first||points[i].second==points[j].second){
                edges.push_back({max(abs(points[i].first-points[j].first),abs(points[i].second-points[j].second)),{i,j}});
            }
        }
    }
    for(auto &&x:xc)sort(x.second.begin(),x.second.end());
    for(auto &&x:yc)sort(x.second.begin(),x.second.end());
    sort(edges.begin(),edges.end());
    ll lo=1,hi=2e9+1,ans=-1;
    while(lo<=hi){
        ll mid=(lo+hi)/2;
        if(work(mid))ans=mid,hi=mid-1;
        else lo=mid+1;
    }
    printf("%lli\n",ans);
    return 0;
}