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

ll n,k;
map<ll,ll> st;
ll ans=0;
ll d[MAXn];
vector<ll> t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    //debug(ll(1e9)*ll(1e5)+5);
    REP(i,n)cin>>d[i];
    for(int i=n-1;i>=0;i--)d[i]+=d[i+1];
    t.pb(1);
    if(k==-1)t.pb(-1);
    else if(k!=1)
    {
        ll tmp=k;
        while(abs(k)<=ll(1e9)*ll(1e5)+5)
        {
            t.pb(k);
            k*=tmp;
        }
    }
    REP(i,n)
    {
        if(st.count(d[i]))st[d[i]]++;
        else st[d[i]]=1;
        for(ll &tmp:t)
        {
            if(st.count(d[i+1]+tmp))ans+=st[d[i+1]+tmp];
        }
    }
    cout<<ans<<endl;
}