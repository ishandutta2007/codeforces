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

int a[1000002];
int main()
{
    ios_base::sync_with_stdio(0);
    string s[2];
    int z;cin>>z;
    cin>>s[0]>>s[1];
    int n=s[0].sz;
    int ile[4]={0};
    FOR(i,n)
    {
		ile[(s[0][i]-'0')*2+(s[1][i]-'0')]++;
	}
	int wyn[2]={0};
	int x=0;
	//DBG(vi(ile,ile+4));
	while(ile[0]+ile[1]+ile[2]+ile[3])
	{
		if (ile[3])
		{
			wyn[x]++;
			ile[3]--;
			x^=1;
			continue;
		}
		if (x==0)
		{
			if (ile[2])
			{
				wyn[x]++;
				ile[2]--;
				x^=1;
				continue;
			}
			else if (ile[1])
			{
				ile[1]--;
				x^=1;
				continue;
			}
			else
			{
				ile[0]--;
				x^=1;
				continue;
			}
		}
		else
		{
			if (ile[1])
			{
				wyn[x]++;
				ile[1]--;
				x^=1;
				continue;
			}
			else if (ile[2])
			{
				ile[2]--;
				x^=1;
				continue;
			}
			else
			{
				ile[0]--;
				x^=1;
				continue;
			}
		}
	}
	if (wyn[0]>wyn[1])
	{
		puts("First");
	}
	else if (wyn[0]==wyn[1])
	{
		puts("Draw");
	}
	else puts("Second");
	
    
    return 0;
}