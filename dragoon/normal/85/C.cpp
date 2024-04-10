#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define S(X) ((X)*(X))
#define ABS(X) ((X)>0?(X):(-(X)))

typedef pair<int,int> PII;
typedef __int64 LL;

#define NN 100005

vector<int> V[NN];
int par[NN], val[NN];
double mistake[NN];
int child[NN], tchild[NN];
int lleft[NN], rright[NN];
int depth[NN];
vector<PII> X;
int lbound[NN], rbound[NN];

int main()
{
	int n,i,a, root,x;

	scanf("%d",&n);
	for(i=1;i<=n;i++) 
	{
		scanf("%d%d",&par[i],&val[i]);
		if(par[i]!=-1) 
		{
			child[ par[i] ]++, tchild[ par[i] ]++;
			V[ par[i] ].push_back(i);
		}
		else root = i;
	}

	queue<int> Q;
	for(i=1;i<=n;i++)
	{
		if(child[i]==0)
		{
			lleft[i]=rright[i] = val[i];
			X.push_back( PII(val[i], i));
			Q.push(i);
		}
	}

	sort(X.begin(),X.end());

	while(!Q.empty())
	{
		x = Q.front();
		Q.pop();

		if(par[x]==-1) //root
		{
			break;
		}
		else if( val[par[x]] > val[x] ) //lleft child
		{
			lleft[ par[x] ] = lleft[x];
			tchild[ par[x] ] --;
			if(tchild[par[x]]==0)
				Q.push( par[x] );
		}
		else //right child
		{
			rright[ par[x] ] = rright[x];
			tchild[ par[x] ] --;
			if(tchild[par[x]]==0)
				Q.push( par[x] );
		}
	}

	lbound[root] = -1; rbound[root]=1000000001;
	
	Q.push(root);
	depth[root]=0;
	while(!Q.empty())
	{
		x = Q.front();
		Q.pop();

		if(child[x]==0) continue;

		if( val[ V[x][0] ] > val[V[x][1]] )
			swap( V[x][0], V[x][1] );

		mistake[V[x][0]]=mistake[x]+lleft[V[x][1]];
		mistake[V[x][1]]=mistake[x]+rright[V[x][0]];
		depth[V[x][0]]=depth[x]+1;
		depth[V[x][1]]=depth[x]+1;

		lbound[ V[x][0] ] = lbound[x];
		rbound[ V[x][0] ] = val[x];

		lbound[ V[x][1] ] = val[x];
		rbound[ V[x][1] ] = rbound[x];

		Q.push( V[x][0] );
		Q.push( V[x][1] );
	}

	int sz = X.size();

	int k,id,now,other;

//	for(i=1;i<=n;i++)
//		printf(">>%d %d %d\n",i,depth[i],mistake[i]);

	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%d",&a);
		id = lower_bound(X.begin(), X.end(), PII(a,0)) - X.begin(); //gives >=

		if(id == sz)
		{
			now = X[sz-1].second;
			printf("%.14lf\n",1.*mistake[ now ]/depth[now]);
		}
		else if(id==0)
		{
			now = X[0].second;
			printf("%.14lf\n",1.*mistake[ now ]/depth[now]);
		}
		else
		{
			now = X[id].second;

			if(lbound[now]<=a && a<=rbound[now]);
			else now = X[id-1].second;
/*			if(val[par[now]] > val[now]) // i am lleft
			{
				if(val[par[now]] > a) ;
				else now = X[id+1].second;
			}
			else //i am right
			{
				if(val[par[now]] > a) now = X[id-1].second;
				else ;
			}
*/
			printf("%.14lf\n",1.*mistake[ now ]/depth[now]);
		}

	}


	return 0;
}