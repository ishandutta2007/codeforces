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
const ll MAXN = 1001000;
const ll BSIZ= 300;

ll A[MAXN];
ll N,K;
ll B[MAXN];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(ll i=1;i<=N;++i){
        cin>>A[i];
    }
    ll spec=1;
    ll ht=A[1];
    for(ll i=2;i<=N;++i){
        // cerr<<"Insert "<<A[i]<<'\n';
        A[i]-=2;
        ll ext=2;
        ll diff=A[i]-(ht+i-2);
        if(spec!=1)++diff;

        ll ln=diff/i;
        // if(ln>0){
        //     cerr<<"Jump\n";
        // }
        A[i] -= ln*(i-1);
        ht+=ln;
        diff -= ln*i;

        // cerr<<"Htt "<<ht<<' '<<spec<<'\n';
        if(diff>0){
            // cerr<<"D "<<diff<<'\n';

            ll kp=spec;
            spec+=diff;

            if(spec>(i-1)){
                spec-=(i-1);
                --ext;
            }

            if(kp == 1 || (spec <= kp && spec>1) ){
                ++ht;
            }
        }else if(diff<0){
            --ext;
        }

        if(ext==2){
            // cerr<<"Yes\n";
            if(spec==1)++ht;
            ++spec;
        }
        // cerr<<"S "<<spec<<'\n';

        // ll cur=ht;
        // for(ll j=1;j<=i;++j){
        //     if(j!=1&&spec!=j)++cur;
        //     cerr<<cur<<' ';
        // }
        // cerr<<'\n';
    }
    ll cur=ht;
    for(ll j=1;j<=N;++j){
        if(j!=1&&spec!=j)++cur;
        cout<<cur<<' ';
    }
}