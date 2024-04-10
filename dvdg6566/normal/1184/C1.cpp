#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 100100

int N,a,b;
vpi coord;

bool sq(int x){
    ll lx=INF, ux=-INF, ly=INF, uy=-INF;
    for (int j=0;j<4*N+1;++j)if(j!=x){ pi i=coord[j];
        lx=min(lx,i.f);
        ux=max(ux,i.f);
        ly=min(ly,i.s);
        uy=max(uy,i.s);
    }
    if (ux-lx != uy-ly)return 0;
    for (int j=0;j<4*N+1;++j)if(j!=x){ pi i=coord[j];
        if (i.f != lx && i.f != ux && i.s != ly && i.s != uy)return 0;
    }
    return 1;
}

int main(){
    // freopen("in.txt","r",stdin);
    cin>>N;
    for (int i=0;i<4*N+1;++i){
        cin>>a>>b;
        coord.pb(mp(a,b));
    }
    for (int i=0;i<4*N+1;++i){
        if (!sq(i))continue;
        cout<<coord[i].f<<' '<<coord[i].s<<'\n';
    }
}