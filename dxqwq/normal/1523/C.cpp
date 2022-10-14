// Problem: C. Compression and Expansion
// Contest: Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//If I can prove that everyone is wrong......
#include<bits/stdc++.h>
using namespace std;
#define int long long
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
int a[1000003];
vector<int> c[1000003];
int f[1000003];
bool vis[1000003];
int stk[1000003],top;
void print()
{
	for(int i=1; i<top; ++i) printf("%lld.",stk[i]);
	printf("%lld\n",stk[top]);
	return ;
}
signed main()
{
    for(int T=read();T--;)
    {
    	top=0;
    	int n=read();
    	int lst=0;
    	for(int i=1; i<=n; ++i) 
    	c[i].clear(),f[i]=0,vis[i]=0;
    	for(int i=1; i<=n; ++i)
    	 a[i]=read(),c[a[i]].push_back(i);
    	 top=0;
    	for(int i=1; i<=n; ++i)
    	{
    		if(a[i]==1) stk[++top]=1;
    		else
    		{
    			while(top&&stk[top]+1!=a[i]) --top;
    			++stk[top];
    		}
    		print();
    	}
    }
	return 0;
}