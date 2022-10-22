#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 50
using namespace std;
int n,a[N+5][N+5],s[N+5][N+5],f[N+5][N+5][N+5][N+5];
I int DP(CI xx,CI yx,CI xy,CI yy)
{
	if(f[xx][yx][xy][yy]) return f[xx][yx][xy][yy];RI i,t,res=max(xy-xx+1,yy-yx+1);
	if(t=s[xy][yy]-s[xx-1][yy]-s[xy][yx-1]+s[xx-1][yx-1],!t) return 0;if(t==(xy-xx+1)*(yy-yx+1)) return res;
	for(i=xx;i^xy;++i) t=DP(xx,yx,i,yy)+DP(i+1,yx,xy,yy),res>t&&(res=t);
	for(i=yx;i^yy;++i) t=DP(xx,yx,xy,i)+DP(xx,i+1,xy,yy),res>t&&(res=t);return f[xx][yx][xy][yy]=res;
}
int main()
{
	RI i,j;string st;for(scanf("%d",&n),i=1;i<=n;++i)
		for(cin>>st,j=1;j<=n;++j) a[i][j]=st[j-1]=='#',
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	return printf("%d",DP(1,1,n,n)),0;
}