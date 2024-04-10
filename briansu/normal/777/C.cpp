#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof(i));
#define SZ(A) ((int)A.size())
#define ALL(A) A.begin(),A.end()
#define X first
#define Y second
#define pb push_back
#ifdef brian
#define  debug(...) do{\
    fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename t> void _do(t &&_x){cerr<<_x<<endl;}
template<typename t,typename ...T> void _do(t &&_x,T &&...tail){cerr<<_x<<", ";_do(tail...);}
template<typename _a,typename _b>
ostream& operator <<(ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
#else
#define debug(...)
#define endl '\n'
#endif // brian

const ll INF=ll(1e15);
const ll MAXn=1e5+5,MAXlg=20;
const ll MOD = 1000000007;

ll n,m;
vector<ll> d[MAXn];
vector<ii> p;
ll t[MAXn];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    REP(i,m)d[i].resize(n);
    REP(i,n)REP(j,m)cin>>d[j][i];
    REP(i,m)
    {
        ll s=0;
        REP(j,n)
        {
            if(d[i][j]>=d[i][j-(s!=j)]);
            else
            {
                p.pb(ii(s,j-1));
                s=j;
            }
        }
        p.pb(ii(s,n-1));
    }
    sort(ALL(p));
    ll it=0,mx=0;
    REP(i,n)
    {
        while(it<SZ(p)&&p[it].X==i)mx=max(mx,p[it++].Y);
        t[i]=mx;
    }
    //REP(i,n)debug(i,t[i]);
    ll q;
    cin>>q;
    REP(i,q)
    {
        ll l,r;
        cin>>l>>r;
        l--;r--;
        if(t[l]>=r)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}