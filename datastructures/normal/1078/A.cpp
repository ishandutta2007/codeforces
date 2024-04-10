#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
#define inf 10000000000
using namespace std;
int a,b,c,xa,xb,ya,yb;
double x[15],y[15],ans=inf;
double dis(double dx,double dy){
	if (dx>2e9||dy>2e9)return inf;
	return sqrt(dx*dx+dy*dy);
}
int book[15];
void dfs(int now,double d){
	if (now==2){
		ans=min(ans,d);
		return;
	}
	book[now]=1;
	for (int i=1;i<=8;i++){
		if (book[i]==1)continue;
		if ((now>4&&i>4)||(x[now]==x[i]||y[now]==y[i]))dfs(i,d+dis(x[i]-x[now],y[i]-y[now]));
	}
	book[now]=0;
	return;
}
signed main(){
	cin>>a>>b>>c>>xa>>ya>>xb>>yb;
	x[1]=xa,y[1]=ya;
	x[2]=xb,y[2]=yb;
	x[3]=xb,y[3]=ya;
	x[4]=xa,y[4]=yb;
	if (a==0||b==0){
		printf("%.9lf\n",fabs(0.0+xa-xb)+fabs(0.0+ya-yb));
		return 0;
	}
	x[5]=xa,y[5]=1.0*(-a*xa-c)/b;
	x[6]=xb,y[6]=1.0*(-a*xb-c)/b;
	x[7]=1.0*(-b*ya-c)/a,y[7]=ya;
	x[8]=1.0*(-b*yb-c)/a,y[8]=yb;
	dfs(1,0.0);
	printf("%.9lf\n",ans);
	return 0;
}