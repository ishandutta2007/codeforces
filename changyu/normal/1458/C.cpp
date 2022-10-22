#include<bits/stdc++.h>
const int N=1003,Q=1e5+3;
int n,a[N][N],b[N][N],p[3],d[3],x[3];char s[Q];
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d",&n,x);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	scanf("%s",s+1);
	p[0]=0,p[1]=1,p[2]=2,d[0]=0,d[1]=0,d[2]=0;
	for(int i=1;s[i];i++){
	  switch(s[i]){
		case'R':++d[p[1]];break;
		case'L':--d[p[1]];break;
		case'D':++d[p[0]];break;
		case'U':--d[p[0]];break;
		case'I':std::swap(p[1],p[2]);break;
		case'C':std::swap(p[0],p[2]);break;
	  }
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
	  x[0]=((i+d[0]-1)%n+n)%n+1,x[1]=((j+d[1]-1)%n+n)%n+1,x[2]=((a[i][j]+d[2]-1)%n+n)%n+1;
	  b[x[p[0]]][x[p[1]]]=x[p[2]];
	}
	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)printf("%d ",b[i][j]);puts("");}
	}return 0;
}