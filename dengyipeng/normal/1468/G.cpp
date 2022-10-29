#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 200005
#define db double 
using namespace std;

int n,i,j,k,x[maxn],y[maxn],X,Y,h,id;
db ans;
db sqr(db x){return x*x;}
db dis(db x,db y,db xx,db yy){return sqrt(sqr(x-xx)+sqr(y-yy));}
int cro(int i,int j){return x[i]*y[j]-x[j]*y[i];}

void getcro(db &xx,db &yy,int i,int j){
	if ((y[i+1]-y[i])*x[j]==y[j]*(x[i+1]-x[i])){
		xx=x[i+1],yy=y[i+1];
		return;
	}
	db k=1.0*(y[i+1]-y[i])/(x[i+1]-x[i]),b=-k*x[i+1]+y[i+1];
	db k0=1.0*y[j]/x[j];
	xx=-b/(k-k0);
	yy=xx*k0;
}

int main(){
	scanf("%d%d",&n,&h);
	for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	X=x[n],Y=y[n]+h;
	for(i=1;i<=n;i++) x[i]=x[i]-X,y[i]=y[i]-Y;
	ans=dis(x[n-1],y[n-1],x[n],y[n]),id=n-1;
	for(i=n-2;i>=1;i--) if (cro(i,id)>=0){
		db xx,yy; getcro(xx,yy,i,id);
		ans+=dis(x[i],y[i],xx,yy);
		id=i;
	} 
	printf("%.11lf",ans);
}