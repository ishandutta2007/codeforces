// Problem: E. Mr. Kitayuta's Gift
// Contest: Codeforces - Codeforces Round #286 (Div. 1)
// URL: https://codeforces.com/problemset/problem/506/E
// Memory Limit: 768 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
// #define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e4+7;
int f[203][203][203],g[203];
int n,m,M;
char s[203];
struct Matrix
{
    int a[403][403];
    Matrix operator*(const Matrix&t)const
    {
        Matrix res;
        memset(res.a,0,sizeof(res.a));
        for(int i=0; i<=M; ++i)
            for(int k=0; k<=M; ++k)
                for(int j=0; j<=M; ++j)
                    res.a[i][j]=(res.a[i][j]+a[i][k]*t.a[k][j])%p;
        return res;
    }
}A,B,res;
Matrix qp(Matrix x,int y)
{
	memset(res.a,0,sizeof(res.a));
	for(int i=0; i<=M; ++i) res.a[i][i]=1;
	for(Matrix t=x; y; y>>=1,t=t*t) if(y&1) res=res*t;
	return res;
}
void build()
{
	A.a[0][1]=1,B.a[M][M]=26,
	A.a[0][M-((n+1)>>1)]=g[0];
	for(int i=1;i<=n;++i)
		B.a[i][i]=24,B.a[i][M-((n-i+1)>>1)]=g[i],B.a[i][i+1]=1;
	B.a[n][n+1]=0;
	for(int i=n+1;i<M;++i)B.a[i][i+1]=1,B.a[i][i]=25;
	return ;
}
signed main(){
	scanf("%s",s+1),n=strlen(s+1),m=read(),f[1][n][0]=1;
	for(int i=1; i<=n; ++i)
		for(int j=n; j>=i; --j)
			if(s[i]==s[j])
				for(int k=0; k+j<i+n; ++k)
					if(i+1<j) f[i+1][j-1][k]=(f[i+1][j-1][k]+f[i][j][k])%p;
					else g[k]=(g[k]+f[i][j][k])%p;
			else 
				for(int k=1; k+j<=i+n; ++k)
					f[i+1][j][k]=(f[i+1][j][k]+f[i][j][k-1])%p,
					f[i][j-1][k]=(f[i][j-1][k]+f[i][j][k-1])%p;
	M=n+((n+1)>>1)+1,build();
	if((n+m)&1) 
	{
		int ans=(A*qp(B,(n+m+1)>>1)).a[0][M];
		memset(g,0,sizeof(g));
		for(int i=1; i<n; ++i) if(s[i]==s[i+1])
			for(int j=0; j<=n; ++j)
				g[j]=(g[j]+f[i][i+1][j])%p;
		build(),B.a[M][M]=0;
		ans=(ans+p-(A*qp(B,(n+m+1)>>1)).a[0][M])%p;
		printf("%d\n",ans);
	}
	else printf("%d\n",(A*qp(B,(n+m)>>1)).a[0][M]);
	return 0;
}