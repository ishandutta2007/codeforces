// Problem: CF1548D2 Gregor and the Odd Cows (Hard)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1548D2
// Memory Limit: 250 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
int a[10003],b[10003];
int f[4][4][4];
//dis x,dis y,dis z
int yzhtxdy(int A,int B,int C,int D,int E,int F)
{
	return (((A*D+C*F+E*B-B*C-D*E-F*A+444444))&2)>>1;
}
int rintxdy[4][4][4][4][4][4];
signed main()
{
	int P=0,Q=0;
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read(),b[i]=read();
	for(int i1=0; i1<4; ++i1)
		for(int i2=0; i2<4; ++i2)
			for(int i3=0; i3<4; ++i3)
				for(int i4=0; i4<4; ++i4)
					for(int i5=0; i5<4; ++i5)
						for(int i6=0; i6<4; ++i6)
							rintxdy[i1][i2][i3][i4][i5][i6]=yzhtxdy(i1,i2,i3,i4,i5,i6);
	for(int i=1; i<=n; ++i)
	{
		memset(f,0,sizeof(f));
		for(int j=1; j<=n; ++j) if(i!=j)
			++f[a[j]&3][b[j]&3][__gcd(abs(a[j]-a[i]),abs(b[j]-b[i]))&3];
		for(int AA=0; AA<=1; ++AA)
			for(int BB=0; BB<=1; ++BB)
				for(int CC=0; CC<=1; ++CC)
					for(int a1=AA; a1<4; ++a1,++a1)
						for(int b1=BB; b1<4; ++b1,++b1)
							for(int g1=CC; g1<4; ++g1,++g1)
								for(int a2=AA; a2<4; ++a2,++a2)
									for(int b2=BB; b2<4; ++b2,++b2)
										for(int g2=CC; g2<4; ++g2,++g2)
										{
											int S=rintxdy[a[i]&3][b[i]&3][a1][b1][a2][b2];
											int A=((g1+g2+__gcd(4+a1-a2,4+b1-b2))&2)>>1;
											((S-A+1)&1)&&(
												(a1!=a2||b1!=b2||g1!=g2)?(
													(g1&1)?(
														Q+=f[a1][b1][g1]*f[a2][b2][g2])
													:(
														P+=f[a1][b1][g1]*f[a2][b2][g2])
												):(
													(g1&1)?(
														Q+=f[a1][b1][g1]*(f[a2][b2][g2]-1))
													:(
														P+=f[a1][b1][g1]*(f[a2][b2][g2]-1))
												)
											);
										}			
	}
	printf("%lld\n",P/6+Q/2);
	return 0;
}