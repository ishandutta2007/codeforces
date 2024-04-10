#include<bits/stdc++.h>
using namespace std;
struct Point
{
    double x,y,z;
}P[5678];
int n;
double dist(const Point &a,const Point &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
int main()
{
    double minn=1e100;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>P[i].x>>P[i].y>>P[i].z;
	}
        
    for(int i=2;i<=n;i++){
    	for(int j=i+1;j<=n;j++){
    		minn=min(minn,dist(P[1],P[i]) + dist(P[1],P[j]) + dist(P[i],P[j]));
		}      
	}
    printf("%.10f\n",minn/2.0);
    return 0;
}