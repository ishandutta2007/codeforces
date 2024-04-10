#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char ch[53][53];
int a[53][53][53][53];//(i->j)*(k->l)
using namespace std;
signed main()
{
	int n=read();
	for(int i=1; i<=n; i++) scanf("%s",ch[i]+1);
	for(int i=1; i<=n; i++) for(int j=i; j<=n; j++) for(int k=1; k<=n; k++) for(int l=k; l<=n; l++) a[i][j][k][l]=max(j-i+1,l-k+1);
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(ch[i][j]=='.') a[i][i][j][j]=0;
	for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) for(int k=1; k+i<=n; k++) for(int l=1; l+j<=n; l++) 
	{
		//printf("%d %d %d %d %d->",k,k+i,l,l+j,a[k][k+i][l][l+j]);
		for(int m=0; m<i; m++) a[k][k+i][l][l+j]=min(a[k][k+i][l][l+j],a[k][k+m][l][l+j]+a[k+m+1][k+i][l][l+j]);
		for(int m=0; m<j; m++) a[k][k+i][l][l+j]=min(a[k][k+i][l][l+j],a[k][k+i][l][l+m]+a[k][k+i][l+m+1][l+j]);
		//printf("%d\n",a[k][k+i][l][l+j]);
	}
	cout<<a[1][n][1][n];
	return 0;
}