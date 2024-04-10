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
string a,b;
ll cnt[10];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    cin>>a>>b;
    REP(i,n)cnt[b[i]-'0']++;
    ll ans=0;
    REP(i,n)
    {
        ll k=a[i]-'0';
        bool bl=1;
        for(int j=k;j<=9;j++)
        {
            if(cnt[j])
            {
                cnt[j]--;
                bl=0;
                break;
            }
        }
        if(bl)
        {
            for(int j=0;j<k;j++)
            {
                if(cnt[j])
                {
                    cnt[j]--;
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
    REP(i,n)cnt[b[i]-'0']++;
    ans=0;
    REP(i,n)
    {
        ll k=a[i]-'0';
        bool bl=1;
        for(int j=k+1;j<=9;j++)
        {
            if(cnt[j])
            {
                cnt[j]--;
                bl=0;
                ans++;
                break;
            }
        }
        if(bl)
        {
            for(int j=0;j<=k;j++)
            {
                if(cnt[j])
                {
                    cnt[j]--;
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
}