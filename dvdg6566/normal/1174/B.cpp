#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 100100

ll N,a;
vi V;


int main(){
    // freopen("in.txt","r",stdin);
    cin>>N;
    for (int i=1;i<=N;++i){
        cin>>a;
        V.pb(a);
    }
    int p = 1;
    for (int i=1;i<N;++i){
        if (V[i]%2 != V[i-1]%2)p = 0;
    }
    if (p!=1)sort(ALL(V));
    for (auto i : V)cout<<i<<' ';
}