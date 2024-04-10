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
int d[502][502];
int p[103][103];

int dp[100002];

int main()
{
    ios_base::sync_with_stdio(0);

	
    int K;CZ(K);
    FOR(i,100)FOR(j,100) d[i][j]=(i!=j);

		
		int ile=100*99*98/6;
		while(ile!=K)
		{
			int r1=rand()%100;
			int r2=rand()%100;
			if (ile>K && d[r1][r2])
			{
				d[r1][r2]=d[r2][r1]=0;
				FOR(j,100) if (d[r1][j] && d[r2][j]) ile--;
			}
			else if (ile<K && r1!=r2 && d[r1][r2]==0)
			{
				d[r1][r2]=d[r2][r1]=1;
				FOR(j,100) if (d[r1][j] && d[r2][j]) ile++;
			}
			//DBG(ile);
		}
		
	
	printf("%d\n",100);
	FOR(i,100)
	{
		FOR(j,100) printf("%d",d[i][j]);
		puts("");
	}
	return 0;
	
    //REPD(K,100000,1)
    //{
    //{
	//	DBG(K);
	//	int k=K;
    
  

	
    
    
    return 0;
}