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
const ll MAXn=1e2+5,MAXlg=20;
const ll MOD = 1000000007;

double dp[MAXn][MAXn][MAXn][3];// r s p
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    REP(i,101)REP(j,101)
    {
        REP(k,3)dp[i][j][0][k]=dp[i][0][j][k]=dp[0][i][j][k]=0;
        dp[i][j][0][0]=dp[i][0][j][2]=dp[0][i][j][1]=1;
    }
    for(int i=1;i<=100;i++)for(int j=1;j<=100;j++)for(int k=1;k<=100;k++)
    {
        lf tt=lf((i+j+k)*(i+j+k-1)/2.0);
        lf t=lf(i*(i-1)+j*(j-1)+k*(k-1))/2.0/tt;
        lf r=lf(i*j)/tt;
        lf s=lf(j*k)/tt;
        lf p=lf(i*k)/tt;
        REP(x,3)dp[i][j][k][x]=(r*dp[i][j-1][k][x]+s*dp[i][j][k-1][x]+p*dp[i-1][j][k][x])/(1-t);
    }
    ll a,b,c;
    cin>>a>>b>>c;
    printf("%0.12f %0.12f %0.12f\n",dp[a][b][c][0],dp[a][b][c][1],dp[a][b][c][2]);
}