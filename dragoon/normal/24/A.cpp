#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<math.h>
#include<stack>
using namespace std;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(X) ((X) < 0 ? (-(X)) : (X))
#define S(X) ((X)*(X))

typedef pair<int,int> PII;
typedef __int64 LL;

int a[102],b[102],c[102];
int i,n,ans1,ans2;
vector<int> V[102],Vs;
int place[102];
queue<int> Q;
int vis[102];
int u;

int main()
{
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		V[a[i]].push_back( b[i] );
		V[b[i]].push_back( a[i] );
	}

	Vs.push_back(-1);
	Q.push(1);
	vis[1]=1;
	Vs.push_back(1);
	while(!Q.empty())
	{
		u=Q.front();
		Q.pop();

		for(i=0;i<2;i++)
			if(!vis[ V[u][i] ])
			{
				vis[V[u][i]]=1;
				Q.push(V[u][i]);
				Vs.push_back(V[u][i]);
				break;
			}
	}


	for(i=1;i<=n;i++)
		place[Vs[i]] = i;

	ans1=0;
	for(i=1;i<=n;i++)
	{
		if(place[a[i]]==n && place[b[i]]==1) continue;
		else if(place[a[i]]==1 && place[b[i]]==n) ans1+=c[i];
		else if(place[a[i]]+1==place[b[i]]) continue;
		else ans1+=c[i];
	}

	ans2=0;
	for(i=1;i<=n;i++)
	{
		if(place[a[i]]==1 && place[b[i]]==n) continue;
		else if(place[a[i]]==n && place[b[i]]==1) ans2+=c[i];
		else if(place[a[i]]==place[b[i]]+1) continue;
		else ans2+=c[i];
	}

	printf("%d\n",MIN(ans1,ans2));

	return 0;
}