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
const ll MAXN=500100;
const ll MAXK=17;
const ll INF=1e18;
const ll MOD=998244353;

ll N,a,b,c,d,e,f,T,E,K;
ll A[MAXN];
vi V[MAXN];
vi cur;
ll W[MAXN];
vi out;
vpi S;
ll done[MAXN];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>E;
    for (int i=0;i<E;++i){
        cin>>a>>b;V[a].pb(b);V[b].pb(a);
    }
    for(int i=1;i<=N;++i){
        cin>>a;
        A[i]=a;
        S.pb(a,i);
    }
    sort(ALL(S));
    a=1;
    for (auto i:S){
        int w=i.s;
        int t=i.f;
        for (auto i:V[w])if(done[i]){
            W[A[i]]=1;
        }
        ll cur=1;
        while(W[cur])++cur;
        if (cur!=t){
            cout<<-1;
            return 0;
        }
        for (auto i:V[w])if(A[i]<A[w]){
            W[A[i]]=0;
        }
        out.pb(w);
        done[w]=1;
    }
    // for(int i=1;i<=N;++i)cout<<out[i]<<' ';
    for (auto i:out)cout<<i<<' ';
}