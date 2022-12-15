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
#else
#define debug(...)
#endif // brian

const ll INF=ll(1e15);
const ll MAXn=1e6+5,MAXlg=20;
const ll MOD = 1000000007;

ll n,m,k;
ll s,f,t;
ll d[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>s>>f>>t>>n;
    REP(i,n)cin>>d[i];
    ll now=s;
    ll mn=INF,mnt=-1;
    REP(i,n)
    {
        if(now>f-t)break;
        debug(i,now);
        ll tmp=min(d[i]-1,f-t);
        ll tmpt=max(now,tmp);
        if(tmpt-tmp<mn)
        {
            mn=tmpt-tmp;
            mnt=tmp;
        }
        now=max(now,d[i])+t;
    }
    if(now<=f-t)
    {
        mn=0;
        mnt=now;
    }
    if(mnt==-1)mnt=s;
    cout<<mnt<<endl;

}