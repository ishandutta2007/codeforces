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
const ll MAXn=5e5+5,MAXlg=20;
const ll MOD = 1000000007;

ll n;
ll l[MAXn];
string d[MAXn];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    REP(i,n)cin>>d[i];
    REP(i,n)l[i]=d[i].length();
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<l[i];j++)
        {
            if(j>=l[i+1])
            {
                l[i]=l[i+1];
                break;
            }
            else if(d[i][j]<d[i+1][j])break;
            else if(d[i][j]>d[i+1][j])
            {
                l[i]=j;
                break;
            }
        }

    }
    REP(i,n)
    {
        REP(j,l[i])cout<<d[i][j];
        cout<<endl;
    }
}