#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 200100;
const ll INF = 1e15;
const ll MOD =  998244353;
ll N,M,W,a,b,c,d,e,K,T;
ll A[MAXN];
ll B[MAXN];
ll C[MAXN];
ll P[MAXN];
vi V[MAXN];
vi X[MAXN];

int ask(ll K){
    bool hv=0;
    for(int i=1;i<=N;++i)if(A[i]==K)hv=1;
    if(!hv)return 0;
    if(N==1)return 1;
    for(int i=1;i<N;++i){
        if(A[i]==K&&A[i+1]>=K)return 1;
    }
    for(int i=2;i<=N;++i){
        if(A[i]==K&&A[i-1]>=K)return 1;
    }
    for(int i=1;i<N;++i){
        if(A[i]>=K&&A[i+1]>=K)return 1;
    }
    for(int i=2;i<N;++i){
        if(A[i-1]>=K&&A[i+1]>=K)return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while(T--){
        cin>>N>>K;
        for(int i=1;i<=N;++i)cin>>A[i];
        if(ask(K))cout<<"yes\n";
        else cout<<"no\n";
    }
}