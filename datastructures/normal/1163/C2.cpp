#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define eps 0.0000000001
#define int long long
using namespace std;
struct node{
	double k,b;
}line[3000005],c[3000005];
int tot,len;
inline bool cmp(node a,node b){
	if (fabs(a.k-b.k)<=eps)return a.b<b.b;
	return a.k<b.k;
}
int n,ans;
double x[10005],y[10005];
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>x[i]>>y[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<i;j++){
			double xa=x[i],ya=y[i],xb=x[j],yb=y[j];
			++tot;
			if (xa==xb)line[tot].k=100000000000.00,line[tot].b=xa;
			else if (ya==yb)line[tot].k=0,line[tot].b=ya;
			else line[tot].k=(yb-ya)/(xb-xa),line[tot].b=ya-line[tot].k*xa;
		}
	sort(line+1,line+1+tot,cmp);
	for (int i=1;i<=tot;i++)
		if (i==1||fabs(line[i].b-line[i-1].b)>eps||fabs(line[i].k-line[i-1].k)>eps)
			c[++len]=line[i];
	ans=len*(len-1)/2;
	for (int i=1;i<=len;i++){
		int j=i;
		while(fabs(c[j].k-c[i].k)<=eps&&j<=len)j++;
		j--;
		ans-=(j-i+1)*(j-i)/2;
		i=j;
	}
	cout<<ans<<endl;
	return 0;
}
//y=kx+b 
//xa=xb -> k=100000000,b=xa
//ya=yb -> k=0,b=ya
//k=(yb-ya)/(xb-xa),b=ya-k*xa