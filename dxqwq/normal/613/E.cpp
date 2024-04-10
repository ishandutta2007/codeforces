// Problem: E. Puzzle Lover
// Contest: Codeforces - Codeforces Round #339 (Div. 1)
// URL: https://codeforces.com/problemset/problem/613/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
const int ava=qp(131,p-2);
int iv[5003];
int h1[2][2003],h2[2][2003],h3[2003];
char s[2][2003],t[2003];
int n,m;
int Hash1(int d,int l,int r){return (p+h1[d][r]-h1[d][l-1])*iv[l-1]%p;}
int Hash2(int d,int l,int r){return (p+h2[d][l]-h2[d][r+1])*iv[n-r]%p;}
int Hash3(int l,int r){return (p+h3[r]-h3[l-1])*iv[l-1]%p;}
int f[2][2003];
int ans=0;
void fuckcmll02()
{ 
	if(!(m&1)&&(n<<1)>=m)
		for(int l=1,r=m>>1; r<=n; ++l,++r)
		{
			if(Hash1(0,l,r)==Hash3(1,m>>1)&&
			Hash2(1,l,r)==Hash3((m>>1)+1,m)) ans=(ans+1)%p;
			if(Hash1(1,l,r)==Hash3(1,m>>1)&&
			Hash2(0,l,r)==Hash3((m>>1)+1,m)) ans=(ans+1)%p;
			if(Hash2(0,l,r)==Hash3(1,m>>1)&&
			Hash1(1,l,r)==Hash3((m>>1)+1,m)) ans=(ans+1)%p;
			if(Hash2(1,l,r)==Hash3(1,m>>1)&&
			Hash1(0,l,r)==Hash3((m>>1)+1,m)) ans=(ans+1)%p;
		}
	return (void)"cmll02 ak ioi";
}
void solve()
{
	memset(f,0,sizeof(f));
    for(int i=1,b=1; i<=m; ++i,b=b*131%p) h3[i]=(h3[i-1]+b*(t[i]-'a'))%p;
	f[0][0]=f[1][0]=1;
	for(int i=1; i<=n; ++i)
	{
		for(int j=m; j>=1; --j) 
		{
			f[0][j]=f[1][j]=0;
			if(j>=1&&s[0][i]==t[j]) f[0][j]=(f[0][j]+f[0][j-1])%p;
			if(j>=1&&s[1][i]==t[j]) f[1][j]=(f[1][j]+f[1][j-1])%p;
			if(j>=2&&s[0][i]==t[j]&&s[1][i]==t[j-1]) f[0][j]=(f[0][j]+f[1][j-2])%p;
			if(j>=2&&s[1][i]==t[j]&&s[0][i]==t[j-1]) f[1][j]=(f[1][j]+f[0][j-2])%p;
		}
		ans=(ans+f[0][m]+f[1][m])%p;
		for(int t=0; t<2; ++t)
			for(int j=i-1; j>=1&&((i-j)<<1)<m; --j)
				if(Hash2(t^1,j,i)==Hash3(1,i-j+1)
				&&Hash1(t,j,i)==Hash3(i-j+2,(i-j+1)<<1))
					++f[t][(i+1-j)<<1];
		for(int t=0; t<2; ++t)
			for(int j=i+2; j<=n&&((j-i)<<1)<m; ++j)
				if(Hash1(t,i+1,j)==Hash3(m-((j-i)<<1)+1,m-(j-i))
				&&Hash2(t^1,i+1,j)==Hash3(m-(j-i)+1,m))
					ans=(ans+f[t][m-((j-i)<<1)])%p;
		//after 1~i
	}
	return ;
}
signed main()
{
	scanf("%s",s[0]+1);
	scanf("%s",s[1]+1);
	scanf("%s",t+1);
	n=strlen(s[0]+1),m=strlen(t+1);
	if(m==1)
	{
		for(int i=0; i<2; ++i)
			for(int j=1; j<=n; ++j) if(s[i][j]==t[1]) ++ans;
		printf("%lld\n",ans);
		return 0;
	}
	if(m==2)
	{
		for(int i=0; i<2; ++i)
			for(int j=1; j<n; ++j) 
			{
				if(s[i][j]==t[1]&&s[i][j+1]==t[2]) ++ans;
				if(s[i][j]==t[2]&&s[i][j+1]==t[1]) ++ans;
			}
		for(int i=1; i<=n; ++i)
		{
			if(s[0][i]==t[1]&&s[1][i]==t[2]) ++ans;
			if(s[0][i]==t[2]&&s[1][i]==t[1]) ++ans;
		}
		printf("%lld\n",ans);
		return 0;		
	}
	iv[0]=1;
	for(int i=1; i<=5000; ++i) iv[i]=iv[i-1]*ava%p;
	for(int t=0; t<2; ++t)
		for(int i=1,b=1; i<=n; ++i,b=b*131%p) h1[t][i]=(h1[t][i-1]+b*(s[t][i]-'a'))%p;
    for(int t=0; t<2; ++t)
    	for(int i=n,b=1; i>=1; --i,b=b*131%p) h2[t][i]=(h2[t][i+1]+b*(s[t][i]-'a'))%p;
	solve(),fuckcmll02(),reverse(t+1,t+m+1),solve();
	printf("%lld\n",ans);
	return 0;
}