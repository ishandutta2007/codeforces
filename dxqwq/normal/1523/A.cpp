// Problem: A. Game of Life
// Contest: Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
char s[1000003];
char  t[1000003];
int b[1000003];
signed main()
{
    for(int T=read();T--;)
    {
    	int n=read(),m=read();
    	scanf("%s",s+1);
    	for(int i=1; i<=n; ++i) t[i]='0';
    	int c=0;
    	for(int i=1; i<=n; ++i) if(s[i]=='1')
    	b[++c]=i;
    	if(c)
    	{
    		for(int i=max(1ll,b[1]-m); i<=b[1]; ++i)
    		t[i]='1';
    		for(int i=b[c]; i<=min(n,b[c]+m); ++i)
    		t[i]='1';
    		for(int i=1; i<c; ++i)
    		{
    			int L=b[i]+m;
    			int R=b[i+1]-m;
    			if(L<R)
    			{
    				for(int j=b[i]; j<=L; ++j) t[j]='1';
    				for(int j=R; j<=b[i+1]; ++j) t[j]='1';
    			}
    			else
    			{
    				if((R-L)%2==0)
    				{
    					for(int j=b[i]; j<=b[i+1]; ++j) t[j]='1';
    					int X=(L+R)>>1;
    					t[X]='0';
    				}
    				else
    				{
    					for(int j=b[i]; j<=b[i+1]; ++j) t[j]='1';
    				}
    			}
    		}
    	}
    	for(int i=1; i<=n; ++i) printf("%c",t[i]);
    	puts("");
    }
	return 0;
}