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
ll g[2*MAXn];
bool d[MAXn];
vector<ll> l[MAXn];
ll fd(ll k){return g[k]=(g[k]==k?k:fd(g[k]));}
void mg(ll a,ll b){g[fd(a)]=fd(b);}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    REP(i,n)cin>>d[i];
    REP(i,m)
    {
        ll k;
        cin>>k;
        REP(j,k)
        {
            ll tmp;
            cin>>tmp;
            l[tmp-1].pb(i);
        }
    }
    REP(i,2*m)g[i]=i;
    //REP(i,2*m)debug(i,g[i]);
    REP(i,n)
    {
        ll a=l[i][0],b=l[i][1];

        if(d[i])
        {
            if(fd(2*a)==fd(2*b+1)||fd(2*a+1)==fd(2*b)){cout<<"NO"<<endl;return 0;}
            mg(2*a,2*b);
            mg(2*a+1,2*b+1);
        }
        else
        {
            if(fd(2*a+1)==fd(2*b+1)||fd(2*a)==fd(2*b)){cout<<"NO"<<endl;return 0;}
            mg(2*a,2*b+1);
            mg(2*a+1,2*b);
        }
        //REP(i,m)debug(i,g[2*i],g[2*i+1]);
    }

    cout<<"YES"<<endl;

}