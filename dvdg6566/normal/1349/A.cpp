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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(ll i=1;i<=N;++i){
        cin>>a;
        A[i]=a;
    }
    T=200000;
    for(ll i=2;i*i<=T;++i)if(P[i]==0){
        for(ll j=i;j<=T;j+=i){
            P[j]=1;
            V[j].pb(i);
        }
    }
    for(ll i=1;i<=N;++i){
        ll cur=A[i];
        for(auto t:V[cur]){
            ll c=0;
            while(cur%t==0){
                cur/=t;
                ++c;
            }
            X[t].pb(c);
        }
        if(cur>1)X[cur].pb(1);
    }
    ll ans=1;
    // for(int i=1;i<=50;++i)cerr<<SZ(X[i])<<'\n';
    for(ll i=1;i<T;++i)if(SZ(X[i])>=N-1){
        if(SZ(X[i])==N-1)X[i].pb(0);
        sort(ALL(X[i]));
        ll a=X[i][1];
        while(a>0){ans*=i;--a;}
    }
    cout<<ans;
}