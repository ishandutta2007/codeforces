#include<cstdio>
#include<cstring>
const int N=53,S=20003;
int n,m,a[4][N],b[4][N],x[S],y[S],z[S],c,f;
inline int X(int p){return p<n?1:2;}
inline int Y(int p){return p<n?p:n+n-1-p;}
inline int P(int x,int y){
	if(x==1)return y;
	if(x==2)return n+n-1-y;
}
inline void Move(int a,int p,int q){
	if(!a)return;
	++p,++q;
	++c;
	x[c]=a,y[c]=p,z[c]=q;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<4;i++)
	  for(int j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	for(int k=0;k<n+n;k++){
	  for(int j=0;j<n;j++){
		if(a[1][j]&&a[1][j]==a[0][j]){
		  Move(a[1][j],0,j);
		  a[1][j]=a[0][j]=0;
		}
		if(a[2][j]&&a[2][j]==a[3][j]){
		  Move(a[2][j],3,j);
		  a[2][j]=a[3][j]=0;
		}
	  }
	  memcpy(b,a,sizeof b);
	  for(int p=0;p<n+n;p++)if(!a[X(p)][Y(p)]){
		for(int q=0;q<n+n;q++){
		  b[X((p+q)%(n+n))][Y((p+q)%(n+n))]=a[X((p+q+1)%(n+n))][Y((p+q+1)%(n+n))];
		  Move(a[X((p+q+1)%(n+n))][Y((p+q+1)%(n+n))],X((p+q)%(n+n)),Y((p+q)%(n+n)));
		}
		break;
	  }
	  memcpy(a,b,sizeof a);
	}
	f=0;
	for(int i=0;i<4;i++)
	  for(int j=0;j<n;j++)
		f|=a[i][j];
	if(f)return 0*puts("-1");
	printf("%d\n",c);
	for(int j=1;j<=c;j++)
	  printf("%d %d %d\n",x[j],y[j],z[j]);
	return 0;
}