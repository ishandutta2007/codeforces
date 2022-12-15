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
const ll MAXn=1e3+5,MAXlg=20;
const ll MOD = 1000000007;

ll n,k,p,x,y;
ll d[MAXn];
vector<ll> ans;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k>>p>>x>>y;
    if(k>0)
    {
        REP(i,k)cin>>d[i];
        sort(d,d+k);
        ll t=lower_bound(d,d+k,y)-d;
        ll tmp=(n-1)/2-t;
        if(tmp<0)
        {
            cout<<-1<<endl;
            return 0;
        }
        REP(i,min(tmp,n-k))ans.pb(1);
    }
    else REP(i,(n-1)/2)ans.pb(1);
    ll kk=ans.size();
    REP(i,n-k-kk)ans.pb(y);
   // for(ll tmp:ans)debug(tmp);
    ll tmp=0;
    REP(i,k)tmp+=d[i];
    REP(i,n-k)tmp+=ans[i];
    if(tmp>x)
    {
        cout<<-1<<endl;
        return 0;
    }
    else REP(i,n-k)cout<<(i==0?"":" ")<<ans[i];
    cout<<endl;
}