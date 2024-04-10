// Problem: B. 3-Coloring
// Contest: Codeforces - Codeforces Round #712 (Div. 1)
// URL: https://codeforces.com/contest/1503/problem/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
#define mp make_pair
signed main()
{
    int n=read();
    int c=read();
    int A,B,C;
    if(c!=1) A=1,B=2,C=3;
    else A=2,B=1,C=3;
    printf("%d %d %d\n",A,1,1);
    fflush(stdout);
    queue<pair<int,int> > qB,qA;
    for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
    if(i+j>2)
    {
    	if((i+j)&1) qB.push(mp(i,j));
    	else qA.push(mp(i,j));
    }
    for(int i=1; i<n*n; i++)
    {
    	int c=read();
    	if(c==A)
    	{
    		if(!qB.empty())
    		{
    			pair<int,int> p=qB.front();
    			qB.pop();
    			printf("%d %d %d\n",B,p.first,p.second);
    		}
    		else
    		{
    			pair<int,int> p=qA.front();
    			qA.pop();
    			printf("%d %d %d\n",C,p.first,p.second);
    		}
    	}
    	else if(c==B)
    	{
    		if(!qA.empty())
    		{
    			pair<int,int> p=qA.front();
    			qA.pop();
    			printf("%d %d %d\n",A,p.first,p.second);
    		}
    		else
    		{
    			pair<int,int> p=qB.front();
    			qB.pop();
    			printf("%d %d %d\n",C,p.first,p.second);
    		}
    	}
    	else
    	{
   		if(!qA.empty())
    		{
    			pair<int,int> p=qA.front();
    			qA.pop();
    			printf("%d %d %d\n",A,p.first,p.second);
    		}
    		else
    		{
    			pair<int,int> p=qB.front();
    			qB.pop();
    			printf("%d %d %d\n",B,p.first,p.second);
    		}
    	}
    	fflush(stdout);
    }
	return 0;
}