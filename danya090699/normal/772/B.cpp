#include <bits/stdc++.h>
#define int long long
using namespace std;
double ans=1e10;
struct poi
{
    int x, y;
};
void check(poi p1, poi p2, poi p3)
{
    double s=((p2.x-p1.x)*(p1.y+p2.y)+(p3.x-p2.x)*(p2.y+p3.y)+(p1.x-p3.x)*(p3.y+p1.y))/2.0;
    double h=s/sqrt(pow(p1.x-p3.x, 2)+pow(p1.y-p3.y, 2));
    ans=min(ans, h);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    poi ar[n];
    for(int a=0; a<n; a++) cin>>ar[a].x>>ar[a].y;
    for(int a=0; a<n; a++) check(ar[a], ar[(a+1)%n], ar[(a+2)%n]);
    cout<<fixed<<setprecision(10)<<ans;
}