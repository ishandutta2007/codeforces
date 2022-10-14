// Problem: CF149D Coloring Brackets
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF149D
// Memory Limit: 250 MB
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
const int p=1e9+7;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
char s[703];
int f[703][703][5];//left,right,both&same,both&different,none
int v[703][703];//valid or not
signed main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1; i<n; ++i)
		if(s[i]=='('&&s[i+1]==')')
			f[i][i+1][0]=1,
			f[i][i+1][1]=1,
			f[i][i+1][2]=0,
			f[i][i+1][3]=0,
			f[i][i+1][4]=0,
			v[i][i+1]=114514;
	for(int len=4; len<=n; len+=2)
		for(int l=1,r=len; r<=n; ++l,++r)
			if(s[l]=='('&&s[r]==')')
			if(v[l+1][r-1])
				f[l][r][0]=(f[l+1][r-1][0]+f[l+1][r-1][1]*2+f[l+1][r-1][2]+f[l+1][r-1][3]+f[l+1][r-1][4]*2)%p,
				//baxx1 ax?x2 baax1 babx1 axxx2
				f[l][r][1]=(f[l+1][r-1][0]*2+f[l+1][r-1][1]+f[l+1][r-1][2]+f[l+1][r-1][3]+f[l+1][r-1][4]*2)%p,
				//x?xa2 xxab1 xaab1 xaba1 xxxa2
				f[l][r][2]=0,
				f[l][r][3]=0,
				f[l][r][4]=0,
				v[l][r]=114514;
			else
				for(int k=l+1; k<r; k+=2)
					if(v[l][k]&&v[k+1][r])
					{
						int*L=f[l][k],*R=f[k+1][r];
						f[l][r][0]=(
						L[0]*R[4]*2+L[2]*R[4]*2+L[3]*R[4]*2+
						L[0]*R[0]*2+L[2]*R[0]+L[3]*R[0]
						)%p,
						//axxx1 aaxx1 abxx1 ax?x2 aabx1 abax1
						f[l][r][1]=(
						R[1]*L[4]*2+R[2]*L[4]*2+R[3]*L[4]*2+
						R[1]*L[1]*2+R[2]*L[1]+R[3]*L[1]
						)%p,
						//xxxa1 x?xa2 xxaa2 xxba1 xaba1 xbaa1
						f[l][r][2]=(
						L[0]*R[1]+L[2]*R[1]+L[3]*R[1]+
						L[0]*R[2]+L[0]*R[3]+L[2]*R[3]+L[3]*R[2]
						)%p,
						//axxa1 aaxa1 abxa1 axaa1 axba1 aaba1 abaa1 
						f[l][r][3]=(
						L[0]*R[1]+L[2]*R[1]+L[3]*R[1]+
						L[0]*R[3]+L[0]*R[2]+L[2]*R[2]+L[3]*R[3]
						)%p,
						//axxb1 aaxb1 abxb1 axab1 axbb1 aabb1 abab1 
						f[l][r][4]=(
						L[4]*R[4]*4+L[1]*R[4]*2+L[4]*R[0]*2+L[1]*R[0]
						)%p,
						//xxxx1 x?xx2 xx?x2 xabx2
						v[l][r]=k;
						break;
					}
	printf("%lld\n",(f[1][n][0]+f[1][n][1]+f[1][n][2]+f[1][n][3]+f[1][n][4])*2%p);
	return 0;
}