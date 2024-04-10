#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const ll mod=1e9+7;
const int MN=5e5+1;
pii dsu[MN];
int mi[MN];
int find(int a) {
    if(a==-1)return -1;
    if (dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
void uni(int a, int b){
    if(a==-1||b==-1)return;
    int ap=find(a),bp=find(b);
    if(ap==bp)return;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[bp].first=ap;
    dsu[ap].second+=dsu[bp].second;
    mi[ap]=min(mi[ap],mi[bp]);
}
int basis[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a;
    vector<int> used;
    for(int i=0;i<MN;i++)basis[i]=-2,dsu[i]={i,1},mi[i]=i;
    for(int i=0;i<n;i++){
        cin>>a;
        pii val={-1,-1};
        if(a==1)cin>>val.first;
        else cin>>val.first>>val.second;
        val.first=find(val.first),val.second=find(val.second);
        if(val.first!=-1)val.first=mi[val.first];
        if(val.second!=-1)val.second=mi[val.second];
        if(val.first<val.second)swap(val.first,val.second);
        if(val.first==val.second)val.first=val.second=-1;
        while(val.first!=-1){
            if(basis[val.first]==-2){
                basis[val.first]=val.second;
                uni(val.first,val.second);
                used.push_back(i);
                break;
            }
            else{
                uni(val.first,basis[val.first]);
                val.first=find(basis[val.first]);
                if(val.first!=-1)val.first=mi[val.first];
                val.second=find(val.second);
                if(val.second!=-1)val.second=mi[val.second];
                if(val.first<val.second)swap(val.first,val.second);
                if(val.first==val.second)val.first=val.second=-1;
            }
        }
    }
    ll ans=1;
    for(int i=1;i<=sz(used);i++){
        ans=ans*ll(2)%mod;
    }
    printf("%lli %d\n",ans,sz(used));
    for(auto x:used)printf("%d ",x+1);
    printf("\n");
    return 0;
}