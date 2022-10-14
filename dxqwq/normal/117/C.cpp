//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[5003];
vector<int> e[5003];
int f[5003];
int stk[5003],top;
bool q[5003][5003];
void solve(int fa,int x)
{
	vector<int> v;
	int C=fa;
	while(fa!=stk[top]) v.push_back(stk[top--]);  
	reverse(v.begin(),v.end());
	int n=(int)v.size();
	while(n>2)
	{
		int A=v[n-2],B=v[n-1];
		if(q[C][A]) printf("%d %d %d\n",A,B,C),exit(0);
		else v.pop_back();
	}
	printf("%d %d %d\n",v[0],v[1],C);
	exit(0);
}
bool dfs(int x)
{
	stk[++top]=x,f[x]=1;
	for(int i:e[x]) if(f[i]==1) solve(i,x);
	else if(f[i]==0) dfs(i);
	--top,f[x]=2;
	return 0;
}
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i)
	{
		scanf("%s",s+1);
		for(int j=1; j<=n; ++j) if(s[j]=='1') q[i][j]=1,e[i].push_back(j);
	}
	for(int i=1; i<=n; ++i) dfs(i);
	puts("-1");
	return 0;
}