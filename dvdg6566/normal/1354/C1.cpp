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
const ld p =3.1415926535;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while(T--){
        cin>>N;
        N*=2;
        ld x=0;
        ld y=0;
        ld angle=0;
        ld mv=p-p*(N-2)/N;
        // cerr<<mv<<'\n';
        ld minx=0;
        ld maxx=0;
        ld maxy=0;
        ld miny=0;
        for(int i=0;i<N;++i){
            ld mx=sin(angle);
            ld my=cos(angle);
            x+=mx;
            y+=my;
            // if(T!=0)cerr<<x<<' '<<y<<'\n';
            angle+=mv;
            minx=min(minx,x);
            miny=min(miny,y);
            maxx=max(maxx,x);
            maxy=max(maxy,y);
        }
        ld h=max(maxx-minx, maxy-miny);
        // cerr<<h<<'\n';
        printf("%.9lf\n",(double)h);
    }
}