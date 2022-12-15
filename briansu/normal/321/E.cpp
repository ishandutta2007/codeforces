//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#ifdef brian
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=4e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

inline int getint(){
	char c;
	while((c=getchar())<'0'||c>'9'); return c-'0';
}

int c[MAXn][MAXn], d[MAXn][MAXn];
ll dp[805][MAXn];
int pi[805][MAXn];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    REP1(i,n)REP1(j,n)d[i][j] = getint();
    REP1(i,n)REP1(j,n)d[i][j] += d[i][j-1];
    REP1(i,n)for(int j = i;j <= n;j ++)c[i][j] = c[i][j-1] + d[j][j-1] - d[j][i-1];
    REP1(i,n)dp[0][i] = INF;
    REP1(i, n)pi[0][i] = 1;
    REP1(i, k)pi[i][n+1] = n;
    REP1(i, k)for(int j = n;j >= 1;j --)
    {
        ll mn = INF;
        for(int t = pi[i-1][j];t <= pi[i][j+1];t++)
        {
            ll tmp = dp[i-1][t-1] + c[t][j];
            if(tmp < mn)mn = tmp, pi[i][j] = t;
        }
        dp[i][j] = mn;
    }
    printf("%I64d\n", dp[k][n]);
}