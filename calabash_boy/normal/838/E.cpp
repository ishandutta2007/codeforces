#include<bits/stdc++.h>
#define sqr(_) (_)*(_)
using namespace std;
const int MAX = 2505;
struct Point{
	double x,y;
	double dist( Point p2){
//		printf("%d %.2lf %.2lf\n",sqr(p2.x-x)+sqr(p2.y-y),sqrt(sqr(p2.x-x)+sqr(p2.y-y)),sqrt(2));
		return sqrt((double)sqr(p2.x-x)+sqr(p2.y-y));
	}
}points[MAX];
int n;
double dp[MAX][MAX][2];
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		double x,y;
		scanf("%lf%lf",&x,&y);
		points[i].x=x,points[i].y=y;
	}
	for (int k=2;k<=n;k++){
		for (int i=0;i<n;i++){
			int j = (i+k-2)%n;
			int I = (i-1+n)%n;
			int J = (j+1)%n;
			Point IP = points[I];
			Point JP = points[J];
			dp[I][k][0] = max(dp[i][k-1][0]+IP.dist(points[i]),dp[i][k-1][1]+IP.dist(points[j]));
			dp[i][k][1] = max(dp[i][k-1][1]+JP.dist(points[j]),dp[i][k-1][0]+JP.dist(points[i]));
		}
	}
	double ans=-1;
	for (int i =0;i<n;i++){
		ans = max(ans,max(dp[i][n][0],dp[i][n][1]));
	}
	printf("%.12f\n",ans);
	return 0;
}