#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MOD=998244353;
constexpr int MAXN=200000;
int sources[MAXN],dests[MAXN];
bool active[MAXN];
int cost_add;
int costs[MAXN];
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int tmp;
        cin>>sources[i]>>dests[i]>>tmp;
        active[i]=tmp;
    }
    int total=(sources[n-1]+1)%MOD;
    for(int i=0;i<n;++i){
        int portalidx=lower_bound(sources,sources+i,dests[i])-sources;
        int inc=sources[i]-dests[i];
        if(portalidx!=i){
            inc+=cost_add+costs[portalidx];
        }
        costs[i]=(MOD-cost_add)%MOD;
        cost_add+=inc;
        cost_add%=MOD;
        if(active[i]){
            total+=inc;
            total%=MOD;
        }
        /*cout<<"T"<<i;
        for(int j=0;j<=i;++j){
            cout<<' '<<(cost_add+costs[j])%MOD;
        }
        cout<<endl;*/
    }
    cout<<total<<'\n';
}