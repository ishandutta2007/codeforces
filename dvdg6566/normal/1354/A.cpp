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
const ll MAXN = 501000;
const ll INF = 1e18+10;
const ll MOD = 2012;

ll N,T,K,a,b,c,d,e,f;
ll ans,sum;
ll A[MAXN];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>d;
        a -= b;
        if(a<=0){
            cout<<b<<'\n';
            continue;
        }
        ll ans=b;
        ll grp=c-d;
        if(grp<=0){
            cout<<-1<<'\n';
            continue;
        }
        ans+=(a+grp-1)/grp*c;
        cout<<ans<<'\n';
    }
}