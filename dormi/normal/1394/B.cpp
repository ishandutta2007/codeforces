#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e5+1;
__int128 sum[10][10];
__int128 val[MAXN];
vector<pii> matrix[MAXN];
__int128 totsum=0;
ll ans=0;
int n,m,k;
void go(int loc,__int128 cursum){
    if(loc==k+1){
        if(cursum==totsum)ans++;
        return;
    }
    for(int i=1;i<=loc;i++){
        go(loc+1,cursum+sum[loc][i]);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<ll> dis(ll(0), ll(1e18));
    int a,b,w;
    for(int i=1;i<=n;i++){
        val[i]=dis(gen);
        totsum+=val[i];
    }
    for(int i=1;i<=m;i++){
        cin>>a>>b>>w;
        matrix[a].push_back({w,b});
    }
    for(int i=1;i<=n;i++){
        sort(matrix[i].begin(),matrix[i].end());
        for(int j=1;j<=sz(matrix[i]);j++)sum[sz(matrix[i])][j]+=val[matrix[i][j-1].second];
    }
    go(1,0);
    printf("%lli\n",ans);
    return 0;
}