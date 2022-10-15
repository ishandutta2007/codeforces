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
const ll MOD=1e9+7;

ll N,a,b,c,d,e,f,T,E,K;
vi A;
vpi V;
ll qexp(ll a, ll b){
    if(b==0)return 1;
    ll h=qexp(a,b/2);
    h=h*h%MOD;
    if(b%2)h=h*a%MOD;
    return h;
}

void ask(){
    ll cur=0;
    ll ans=0;
    ll w=V.back().f;
    while(SZ(V)){
        ll cnt=V.back().s;
        ll ln=V.back().f;
        ll dif=w-ln;
        // cerr<<"Process "<<ln<<' '<<cnt<<'\n';
        w=ln;
        ll flag=0;
        if(cur){
            if (dif<=30){
                while(dif--){
                    cur*=K;
                    if (cur>N){flag=1;break;}
                }
            }else flag=1;
        }

        if (flag){
            ll h=0;
            for (auto i:V){
                h+=qexp(K,i.f)*i.s%MOD;
                h%=MOD;
            }
            cout<<(ans-h+MOD)%MOD<<'\n';
            return;
        }

        // cerr<<"Current offset "<<cur<<'\n';
        // cerr<<cnt<<'\n';
        V.pop_back();
        if (cnt<=cur){
            cur -= cnt;
            ans=qexp(K,ln)*cur%MOD;
        }else{
            cnt -= cur;
            cnt %= 2;
            if(cnt)ans=qexp(K,ln);
            else ans=0;
            cur=cnt; 
        }
        // cerr<<"Current "<<cur<<' '<<ans<<' '<<'\n';
    }
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while(T--){
        cin>>N>>K;
        V.clear();A.clear();
        for (int i=0;i<N;++i){
            cin>>a;
            A.pb(a);
        }
        if(K==1){
            if(N%2==1)cout<<"1\n";
            else cout<<"0\n";
            continue;
        }
        sort(ALL(A));
        for (auto i:A){
            if(SZ(V)&&V.back().f==i)V.back().s++;
            else V.pb(i,1);
        }
        ask();
        // return 0;
    }
}