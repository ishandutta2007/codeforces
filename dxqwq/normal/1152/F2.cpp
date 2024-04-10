// Problem: C. Neko Rules the Catniverse (Small Version)
// Contest: Codeforces - zmf flip
// URL: https://codeforces.com/gym/374646/problem/C
// Memory Limit: 256 MB
// Time Limit: 7000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
int n=read(),k=read(),m=read(),M=1<<m,S=(k+1)<<m;
struct Matrix
{
    int a[233][233];
    Matrix operator*(const Matrix&t)const
    {
        Matrix res;
        memset(res.a,0,sizeof(res.a));
        for(int i=0; i<=S; ++i)
            for(int k=0; k<=S; ++k)
                for(int j=0; j<=S; ++j)
                    res.a[i][j]=(res.a[i][j]+1ll*a[i][k]*t.a[k][j])%p;
        return res;
    }
    void remake()
    {
    	memset(a,0,sizeof(a));
    	for(int i=0; i<S; ++i)
    		a[i][i]=1;
    }
}A;
int f[53][53],id[53][53];
signed main()
{
	for(int i=0; i<=k; ++i)
		for(int j=0; j<M; ++j)
			A.a[(i<<m)+j][(i<<m)+((j<<1)&(M-1))]=1;
	for(int i=0; i<k; ++i)
		for(int j=0; j<M; ++j)
			A.a[(i<<m)+j][((i+1)<<m)+((j<<1)&(M-1))+1]=
				__builtin_popcount(j)+1;
	Matrix ans;
	ans.remake();
	int sum=0;
	for(Matrix g=A; n; n>>=1,g=g*g) if(n&1) ans=ans*g;
	for(int i=k<<m; i<S; ++i) sum=(sum+ans.a[0][i])%p;
	printf("%lld\n",sum);
	return 0;
}