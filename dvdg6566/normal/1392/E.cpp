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
const ll MAXN = 30;
const ll BSIZ= 300;

ll A[MAXN][MAXN];
ll N;
ll cur;
vpi out;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    cur=(1LL<<(2*N-3));
    for(int tot=3;tot<=2*N;++tot){
        for(int i=1;i<=N;++i){
            int j=tot-i;
            if(j<=0||j>N)continue;
            if(i%2==N%2)A[i][j]=cur;
        }
        cur=(cur>>1);
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j)cout<<A[i][j]<<' ';
        cout<<'\n';
    }
    cout<<flush;
    ll Q,X;
    cin>>Q;

    while(Q--){
        cin>>X;
        out.clear();
        pi cur=mp(1,1);
        ll tx=(1LL<<(2*N-3));
        while(cur.f!=N||cur.s!=N){
            out.pb(cur);
            if(X&tx){
                if(A[cur.f+1][cur.s])++cur.f;
                else ++cur.s;
            }else{
                if(A[cur.f+1][cur.s])++cur.s;
                else ++cur.f;
            }
            tx=tx>>1;
            if(cur.f>N||cur.s>N)assert(0);
        }
        out.pb(cur);
        for(auto i:out){
            cout<<i.f<<' '<<i.s<<'\n';
        }
        cout<<flush;
    }
}