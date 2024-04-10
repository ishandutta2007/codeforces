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
const ll MAXn=1e6+5,MAXlg=20;
const ll MOD = 1000000007;

bool b[MAXn];
vector<ll> pm;
ll cal(ll k)
{
    ll tmp=k;
    for(ll p:pm)
    {
        if(p>k)break;
        if(k%p==0)
        {
            tmp=tmp/p*(p-1);
            while(k%p==0)k/=p;
        }
    }
    if(k>1)tmp=tmp/k*(k-1);
    return tmp;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,k;
    cin>>n>>k;
    for(int i=2;i<MAXn;i++)
    {
        if(!b[i])pm.pb(i);
        for(int j=0;i*pm[j]<MAXn;j++)
        {
            b[i*pm[j]]=1;
            if(i%pm[j]==0)break;
        }
    }
    if(k%2==0)k--;
    while(n!=1&&k>0)
    {
        n=cal(n);
        k-=2;
    }
    cout<<n%MOD<<endl;
}