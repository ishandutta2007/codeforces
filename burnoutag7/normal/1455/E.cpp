#include<bits/stdc++.h>
using namespace std;

pair<int,int> p[4];
vector<int> h,v;

long long check(const int& vlb,const int& vub,const int& hlb,const int& hub){
    sort(p,p+4);
    long long res=1e18;
    do{
        res=min(res,(long long)abs(vlb-p[0].first)+abs(hlb-p[0].second)+abs(vlb-p[1].first)+abs(hub-p[1].second)+
        abs(vub-p[2].first)+abs(hlb-p[2].second)+abs(vub-p[3].first)+abs(hub-p[3].second));
    }while(next_permutation(p,p+4));
    return res;
}

void mian(){
    h.clear();
    v.clear();
    for(int i=0;i<4;i++){
        cin>>p[i].first>>p[i].second;
        v.emplace_back(p[i].first);
        h.emplace_back(p[i].second);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    sort(h.begin(),h.end());
    h.erase(unique(h.begin(),h.end()),h.end());
    long long ans=1e18;
    for(int vi=0;vi<4;vi++){
        for(int vj=vi;vj<4;vj++){
            for(int hi=0;hi<4;hi++){
                for(int hj=hi;hj<4;hj++){
                    int vlb=v[vi],vub=v[vj],hlb=h[hi],hub=h[hj],len=min(vub-vlb,hub-hlb);
                    ans=min(ans,check(vlb,vlb+len,hlb,hlb+len));
                    ans=min(ans,check(vub-len,vub,hlb,hlb+len));
                    ans=min(ans,check(vlb,vlb+len,hub-len,hub));
                    ans=min(ans,check(vub-len,vub,hub-len,hub));
                }
            }
        }
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}