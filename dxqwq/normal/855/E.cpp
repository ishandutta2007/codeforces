#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch && ch<='9')x=x*10+(ch&15),ch=getchar();
    return x*f;
}
int s[2][13][73][1103],f[2][13][73][1103],num[73],cnt;
int dfs(int now,int k,int st,int zero,int flg)
//0
{
	if(!now) if(zero||st) return 0; else return 1;
	if(!flg && f[zero][k][now][st]) return s[zero][k][now][st];
	int sum=0;
	if(flg)
	{
		for(int i=1; i<num[now]; i++) sum+=dfs(now-1,k,st^(1<<i),0,0);
		if(zero) sum+=dfs(now-1,k,0,1,(num[now]==0));
		else sum+=dfs(now-1,k,st^1,0,(num[now]==0));
		if(num[now]!=0) sum+=dfs(now-1,k,st^(1<<num[now]),0,1);
	}
	else
	{
		for(int i=1; i<k; i++) sum+=dfs(now-1,k,st^(1<<i),0,0);
		if(zero) sum+=dfs(now-1,k,0,1,0);
		else sum+=dfs(now-1,k,st^1,0,0);
	}
	if(!flg) 
	{
		f[zero][k][now][st]=1;
		return s[zero][k][now][st]=sum; 
	}else return sum;
} 
int solve(int k,int x)
{
	if(x==0) return 0;
	cnt=0;
	while(x) num[++cnt]=x%k,x/=k;
	return dfs(cnt,k,0,1,1);
}
signed main()
{
	for(int T=read(),k,l,r;T--;) k=read(),l=read(),r=read(),printf("%lld\n",solve(k,r)-solve(k,l-1));
	
	return 0;
}