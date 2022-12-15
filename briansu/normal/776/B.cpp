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

ll n;
vector<ll> pm;
bool b[MAXn];
ll cnt=1,ans[MAXn];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i=2;i<MAXn;i++)
    {
        bool k=1;
        for(int j=0;j<SZ(pm)&&pm[j]*pm[j]<=i;j++)if(i%pm[j]==0){k=0;break;}
        b[i]=k;
        if(k)pm.pb(i);
    }
    cin>>n;
    for(int i=2;i<=n+1;i++)
    {
        if(b[i]&&i*2<=n+1){ans[i]=2;cnt=2;}
        else ans[i]=1;
    }
    cout<<cnt<<endl;
    for(int i=2;i<=n+1;i++)cout<<(i==2?"":" ")<<ans[i];
    cout<<endl;
}