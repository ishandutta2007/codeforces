#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
 
#define bit(n) (1<<(n))
#define inf 1100000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
 
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef __int64 LL;
 
#define N 266666
int Q,q;
char cq[N];
int xq[N],yq[N];
int n;
int X[N];
set<int> Y[N];
int d;
int maxyi[2*N];
int maxy[N];
 
int getmax(int i,int j)
{
	if(maxy[i]>=maxy[j]) return i;
	return j;
}
 
int Xfind(int x)
{
	int l=0;
	int r=n;
	while(l+1<r)
	{
		int m=(l+r)/2;
		if(X[m]<=x) l=m; else r=m;
	}
	return l;
}
 
void update(int x)
{
	x=(x+d)/2;
	for(;x>0;x/=2)
		maxyi[x]=getmax(maxyi[2*x],maxyi[2*x+1]);
}
 
int main()
{
	//freopen("in.txt","r",stdin);
	while(scanf("%d",&Q)>0)
	{
		int i;
		for(n=q=0;q<Q;q++)
		{
			char tmp[10];
			scanf("%s %d %d",tmp,&xq[q],&yq[q]);
			cq[q]=tmp[0];
			X[n++]=xq[q];
		}
		sort(X,X+n);
		n=unique(X,X+n)-X;
		for(d=1;d<n;d*=2);
		for(i=0;i<d;i++)
		{
			Y[i].clear();
			maxy[i]=-inf;
		}
		for(i=d;i<2*d;i++) maxyi[i]=i-d;
		for(i=d-1;i>0;i--) maxyi[i]=getmax(maxyi[2*i],maxyi[2*i+1]);
		for(q=0;q<Q;q++)
		{
			int x=Xfind(xq[q]);
			if(cq[q]=='a')
			{
				Y[x].insert(yq[q]);
				if(maxy[x]<yq[q])
				{
					maxy[x]=yq[q];
					update(x);
				}
			}
			if(cq[q]=='r')
			{
				Y[x].erase(Y[x].find(yq[q]));
				if(Y[x].sz==0) maxy[x]=-inf; else
				{
					set<int>::iterator it=Y[x].end();
					--it;
					maxy[x]=*it;
				}
				update(x);
			}
			if(cq[q]=='f')
			{
				int l=x;
				int r=n;
				while(l+1<r)
				{
					int m=(l+r)/2;
					int L=x+1+d;
					int R=m+d;
					int cur=n;
					for(;;)
					{
						if(L%2) cur=getmax(cur,maxyi[L]);
						L=(L+1)/2;
						if(R%2==0) cur=getmax(cur,maxyi[R]);
						R=(R-1)/2;
						if(L>R) break;
					}
					if(maxy[cur]>yq[q]) r=m; else l=m;
				}
				if(r==n) puts("-1"); else
				{
					set<int>::iterator it=Y[r].lower_bound(yq[q]);
					if(*it==yq[q]) ++it;
					printf("%d %d\n",X[r],*it);
				}
			}
		}
	}
	int kkkkkk;
	return 0;
}