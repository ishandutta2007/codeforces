// Problem: D. The Wu
// Contest: Codeforces - Codeforces Round #502 (in memory of Leopoldo Taravilse, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1017/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[103];
int cnt[5003];
int qwq[5003][203];
int f(int x,int y,int len)
{
	int res=0;
	for(int i=0; i<len; i++)
	 if((x&(1ll<<i))==(y&(1ll<<i)))
	  res+=a[i+1];
	  if(res>100) res=101;
	return res;
}
signed main()
{
    int m=read(),n=read(),q=read();
    int tot=1<<m,sum=0;
    for(int i=1; i<=m; i++) a[i]=read();
    char s[23];
    for(int i=1; i<=n; i++)
    {
    	scanf("%s",s);
    	int t=0;
    	for(int j=0; j<m; j++) t+=(1<<j)*(s[j]=='1');
    	cnt[t]++;
    }
    for(int i=0; i<tot; i++) for(int j=0; j<tot; j++)
    qwq[i][f(i,j,m)]+=cnt[j];
    for(int i=0; i<tot; i++) for(int j=1; j<=100; j++) qwq[i][j]+=qwq[i][j-1];
    for(;q--;)
    {
        scanf("%s",s);
    	int t=0;
    	for(int j=0; j<m; j++) t+=(1<<j)*(s[j]=='1');
    	int k=read();
    	printf("%lld\n",qwq[t][k]);
    }
	return 0;
}