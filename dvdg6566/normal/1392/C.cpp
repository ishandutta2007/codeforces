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
vi V;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while(T--){
        V.clear();
        cin>>N;
        ll ans=0;
        ll cur=0;
        for(int i=0;i<N;++i){
            cin>>a;
            if(SZ(V) && V.back()>a){
                ans+=(V.back()-a);
            }
            V.pb(a);
        }
        
        // while(SZ(V)){
        //     int t=V.back();V.pop_back();
        //     t+=ans;
        //     if(t<cur){
        //         ans+=(cur-=t);
        //         t=cur;
        //     }
        //     cur=t;
        // }
        cout<<ans<<'\n';
    }
}