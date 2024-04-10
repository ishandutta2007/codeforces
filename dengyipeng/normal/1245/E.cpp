#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 11
#define db double
using namespace std;

int n=10,i,j,k,a[maxn][maxn],x,y,xx,yy,xxx,yyy;
db f[maxn][maxn];

void pre(int &xx,int &yy,int x,int y){
	if (y==n) {
		if (x&1) xx=x,yy=y-1;
		else xx=x-1,yy=y;
	} else 
	if (y==1) {
		if (x&1) xx=x-1,yy=y;
		else xx=x,yy=y+1;
	} else{
		if (x&1) xx=x,yy=y-1;
		else xx=x,yy=y+1;
	}
}

void nex(int &xx,int &yy,int x,int y){
	if (y==n) {
		if (!(x&1)) xx=x,yy=y-1;
		else xx=x+1,yy=y;
	} else 
	if (y==1) {
		if (!(x&1)) xx=x+1,yy=y;
		else xx=x,yy=y+1;
	} else{
		if (!(x&1)) xx=x,yy=y-1;
		else xx=x,yy=y+1;
	}	
}

int main(){
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%d",&a[i][j]);
	f[1][1]=0;
	for(i=2;i<=7;i++){
		f[1][i]=1;
		for(j=1;j<i;j++) 	
			f[1][i]+=f[1][i-j]/6;
		f[1][j]/=1.0*(i-1)/6;
	}
	x=1,y=8;
	for(int cnt=1;cnt<=93;cnt++){
		xx=x,yy=y,f[x][y]=1;
		for(i=1;i<=6;i++){
			pre(xxx,yyy,xx,yy);
			f[x][y]+=min(f[xxx][yyy],f[xxx-a[xxx][yyy]][yyy])/6;
			xx=xxx,yy=yyy;
		}
		nex(x,y,x,y);
	}
	printf("%.11lf",f[n][1]);
}