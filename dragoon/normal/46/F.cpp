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
#include<bitset>
using namespace std;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(X) ((X)>0?(X):(-(X)))
#define S(X) ((X)*(X))
#define D(x1,y1,x2,y2) (sqrt( S((x1)-(x2)) + S((y1)-(y2)) ))
#define D2(x1,y1,x2,y2) ( S((x1)-(x2)) + S((y1)-(y2)) )
#define EPS 1e-8
#define IN(a,b,c) if(a>=b && a<=c)
#define CLEAR(a) memset(a,0,sizeof(a))

typedef pair<int,int> PII;
//typedef long long LL;
//typedef __int64 LL;

//int dr[]={0,-1,-1,-1,0,1,1,1};
//int dc[]={-1,-1,0,1,1,1,0,-1};

struct EDGE
{
	int u,v;
};

EDGE edge[1012];

map<string,int> M;
bitset<1012> B1[1012],B2[1012];
vector<int> V1[1012],V2[1012];
int p1[1012],p2[1012];
char name[30];

int P1(int a)
{
	if(p1[a]==a) return a;
	return p1[a]=P1(p1[a]);
}

int P2(int a)
{
	if(p2[a]==a) return a;
	return p2[a]=P2(p2[a]);
}

int roomno[1012],roomno2[1012];

int main()
{
	int n,m,k,i,j,nk,a,flag,b,rn,id;

	//k=roomno, m=edgeno, n=people
	scanf("%d%d%d",&k,&m,&n);
	for(i=0;i<m;i++)
		scanf("%d%d",&edge[i].u,&edge[i].v);

	for(i=1;i<=k;i++) 
	{
		B1[i].reset();
		B2[i].reset();
		p1[i]=p2[i]=i;
	}

	for(i=1;i<=n;i++)
	{
		scanf("%s%d%d",name,&roomno[i],&nk);
		M[name]=i;
		for(j=0;j<nk;j++)
		{
			scanf("%d",&a);
			a--;
			B1[roomno[i]].set(a,1);
		}
	}

	while(1)
	{
		flag=0;
		for(j=0;j<m;j++)
		{
			a = edge[j].u; b = edge[j].v;

			if(P1(a)==P1(b)) continue;

			a = p1[a]; b = p1[b];

			if(B1[a].test(j) || B1[b].test(j))
			{
				if(a>b) swap(a,b);

				p1[b] = a;
				B1[a] |= B1[b];

				flag=1;
			}
		}

		if(flag==0) break;
	}

	for(i=1;i<=n;i++)
		V1[ P1(roomno[i]) ].push_back(i);
	for(i=1;i<=k;i++)
		if(p1[i]==i)
			sort(V1[i].begin(),V1[i].end());

	for(i=1;i<=k;i++)
		B2[i].reset();

	for(i=1;i<=n;i++)
	{
		scanf("%s%d%d",name,&rn,&nk);
		id = M[name];
		roomno2[id]=rn;
		for(j=0;j<nk;j++)
		{
			scanf("%d",&a);
			a--;
			B2[rn].set(a,1);
		}
	}

	while(1)
	{
		flag=0;
		for(j=0;j<m;j++)
		{
			a = edge[j].u; b = edge[j].v;

			if(P2(a)==P2(b)) continue;

			a = p2[a]; b = p2[b];

			if(B2[a].test(j) || B2[b].test(j))
			{
				if(a>b) swap(a,b);

				p2[b] = a;
				B2[a] |= B2[b];

				flag=1;
			}
		}

		if(flag==0) break;
	}

	for(i=1;i<=n;i++)
		V2[ P2(roomno2[i]) ].push_back(i);
	for(i=1;i<=k;i++)
		if(p2[i]==i)
			sort(V2[i].begin(),V2[i].end());

	flag=1;
	for(i=1;i<=k && flag;i++)
		if( (p1[i]==i && p2[i]!=i) || (p1[i]!=i && p2[i]==i) )
			flag=0;
		else if(p1[i]==i)
		{
			if(V1[i]!=V2[i])
				flag=0;
			if(B1[i]!=B2[i])
				flag=0;
		}

	if(flag) printf("YES\n");
	else printf("NO\n");

	return 0;
}