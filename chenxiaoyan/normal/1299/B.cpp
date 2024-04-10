/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define y1 dsljffjwe
const double eps=1e-7;
bool eq(double x,double y){return abs(x-y)<=eps;}
const int N=100000;
int n;
int x[N+2],y[N+2];
double slope(int x1,int y1,int x2,int y2){
	return y2==y1?1e12:1.*(x2-x1)/(y2-y1);
}
int dis(int x1,int y1,int x2,int y2){
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
signed main(){
	cin>>n;
	if(n%2==1)return puts("NO"),0;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	x[n+1]=x[1];y[n+1]=y[1];
	for(int i=1;i<=n/2;i++){
		if(!eq(slope(x[i],y[i],x[i+1],y[i+1]),slope(x[i+n/2],y[i+n/2],x[i+n/2+1],y[i+n/2+1]))||
		dis(x[i],y[i],x[i+1],y[i+1])!=dis(x[i+n/2],y[i+n/2],x[i+n/2+1],y[i+n/2+1])
		)return puts("NO"),0;
	}
	puts("YES");
	return 0;
}