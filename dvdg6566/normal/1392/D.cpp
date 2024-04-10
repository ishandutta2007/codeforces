#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MOD = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 200010;
const ll BSIZ= 300;

ll A[MAXN];
ll N,T,a,X;
vpi V;
string S;
// int dp[MAXN][2][2];

// int ask(int n,int p1,int p2){
//     if(dp[n][p1][p2] != -1)return dp[n][p1][p2];
//     dp[n][p1][p2]=1e9;
//     for(int i=0;i<2;++i){
//         if(i==p1&&i==p2)continue;
//         int t=ask(n-1,i,p1);
//         if(i!=A[n])++t;
//         dp[n][p1][p2]=min(dp[n][p1][p2],t);
//     }
//     return dp[n][p1][p2];
// }


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while(T--){
        V.clear();
        cin>>N>>S;
        for(int i=1;i<=N;++i)A[i]=0;
        for(int i=1;i<=N;++i)if(S[i-1]=='R'){
            A[i]=1;
        }
        for(int i=1;i<=N;++i){
            if(SZ(V) && V.back().f == A[i])++V.back().s;
            else V.pb(A[i],1);
        }
        if(SZ(V) > 1 && V[0].f == V.back().f){
            V[0].s+=V.back().s;
            V.pop_back();
        }
        int ans=0;

        for(auto i:V)ans+=i.s/3;
        if(SZ(V) == 1){
            ans=(V.back().s+2)/3;
        }
        cout<<ans<<'\n';
        // int ans=1e9;
        // for(int i=0;i<4;++i){
        //     for(int k=0;k<=N;++k){
        //         for(int p=0;p<2;++p)for(int q=0;q<2;++q)dp[k][p][q]=-1;
        //     }
        //     int c1=i&1;
        //     int c2=(i&2)>>1;
        //     int v=0;
        //     if(c1!=A[1])++v;
        //     if(c2!=A[2])++v;
        //     for(int p=0;p<2;++p)for(int q=0;q<2;++q)dp[0][p][q]=1e9;
        //     dp[0][c1][c2]=v;

        //     int x=ask(N,c1,c2);
        //     ans=min(ans,x);
        // }
        // assert(ans!=1e9);
        // cout<<ans<<'\n';
    }
}