#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int main()
{
    double x1,x2,y1,y2,v,t,v1,v2,v3,v4;
    cin>>x1>>y1>>x2>>y2>>v>>t>>v1>>v2>>v3>>v4;
    double l=0,r=1e18;
    for(int a=1;a<=1000;a++)
    {
        double mid=(l+r)/2.0,x3,y3;
        if(mid>t)
        {
            x3=x1+t*v1+(mid-t)*v3;
            y3=y1+t*v2+(mid-t)*v4;
        }
        else
        {
            x3=x1+mid*v1;
            y3=y1+mid*v2;
        }
        if((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)<=v*mid*v*mid)
            r=mid;
        else
            l=mid;
    }
    printf("%.11f",l);
}