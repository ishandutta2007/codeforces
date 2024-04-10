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
        ll ans=INF;
        string S;
        cin>>S;
        N=SZ(S);
        a=b=c=0;
        ll e=-1;
        for(ll s=0;s<N;++s){
            while(e+1<N&&min({a,b,c})==0){
                ++e;
                if(S[e]=='1')++a;
                else if(S[e]=='2')++b;
                else ++c;
            }
            if(min({a,b,c})==0)break;
            ans=min(ans,e-s+1);
            if(S[s]=='1')--a;
            else if(S[s]=='2')--b;
            else --c;
        }
        if(ans==INF)ans=0;
        cout<<ans<<'\n';
    }
}