#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define f first 
#define s second
#define mp make_pair
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
#define lb lower_bound
#define ub upper_bound

const ll MAXN=5010;

ll xx,N,Q,a,b,c,d,e,K,M;
ll A[MAXN];
ll B[MAXN];

int main(){
    cin>>N;
    for(ll i=1;i<=N;++i)cin>>A[i];
    for(ll i=1;i<=N;++i)cin>>B[i];
    ll ans=0;
    K=0;
    for(ll i=1;i<=N;++i)K+=A[i]*B[i];
    ans=K;
    for(ll pivot=1;pivot<=N;++pivot){
        ll run=0;
        for(ll l=1;l<=N;++l){
            // swapping pivot-l with pivot+l
            a=pivot-l;b=pivot+l;
            if(a<1||b>N)break;
            run-=A[a]*B[a]+A[b]*B[b];
            run+=A[a]*B[b]+A[b]*B[a];
            // cerr<<l<<' '<<run<<'\n';
            ans=max(ans,K+run);
        }
    }
    for(ll pivot=1;pivot<=N;++pivot){
        ll run=0;
        for(ll l=0;l<=N;++l){
            // swapping pivot-l with pivot+l
            a=pivot-l;b=pivot+l+1;
            if(a<1||b>N)break;
            run-=A[a]*B[a]+A[b]*B[b];
            run+=A[a]*B[b]+A[b]*B[a];
            // cerr<<l<<' '<<run<<'\n';
            ans=max(ans,K+run);
        }
    }
    cout<<ans;
}