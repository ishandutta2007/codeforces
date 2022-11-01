#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define un(v) v.erase(unique(ALL(v)),v.end())
#define LOLDBG
#ifdef LOLDBG
#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }
#define MOD 1000000007



ll mpow(ll a, ll b)
{
    a=a%MOD;
    ll w=1;
    while(b)
    {
        if (b%2) w=(w*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return w;
}

ll dp[102][102*102];
ll si[100002];
ll npok(int n,int k)
{
	ll w=si[n];
	w=(w*mpow(si[k],MOD-2))%MOD;
	w=(w*mpow(si[n-k],MOD-2))%MOD;
	return w;
}


ll mem[101][102][2];


int main()
{
    ios_base::sync_with_stdio(0);
    si[0]=1;
    REP(i,1,100000) si[i]=(si[i-1]*i)%MOD;
    ll n,m,k;cin>>n>>m>>k;
    dp[0][0]=1;
    int r=m%n;
    ll d=m/n;
    FOR(i,2)FOR(i1,n+1)FOR(i2,n+1) mem[i1][i2][i]=mpow(npok(i1,i2),d+i);
    REP(i,1,n)
    {
		ll pot;
		if (i<=r) pot=1;
		else pot=0;
		FOR(d,k+1)
		{
			FOR(j,min((int)n,d)+1)
			{
				
				dp[i][d]+=(dp[i-1][d-j]*mem[n][j][pot])%MOD;
			}
			dp[i][d]%=MOD;
		}
	}
	cout<<dp[n][k];
    
    return 0;
}