#pragma comment(linker, "/STACK:102400000,102400000")
//#include<bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <list>
#include <stack>
#include <utility> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const double eps = 1e-4;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N =1e6+6; 
const int M=100010;
const int maxn=55555;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define pi acos(-1.0)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson  l , mid , rt << 1    
#define rson  mid + 1 , r , rt << 1 | 1  
const int lowbit(int x) { return x&-x; }
//const int lowbit(int x) { return ((x)&((x)^((x)-1))); } 
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}

struct Point   
{  
    double x,y;  
};  
double dist(Point p1,Point p2)  
{  
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));  
}  
double Angle(double a,double b,double c)  
{  
    return acos((a*a+b*b-c*c)/(2*b*a));  
}  
double gcd(double a,double b)  
{  
    if(b+eps>0&&b-eps<0)//eps 
        return a;  
    if(a+eps>0&&a-eps<0)  
        return b;  
    return gcd(b,fmod(a,b));  
}
int main()  
{  
    Point p1,p2,p3;  
    while(~scanf("%lf%lf%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y))  
    {  
        double a,b,c,p,s,r;  
        double angle1,angle2,angle3,angle;  
        a=dist(p1,p2);  
        b=dist(p1,p3);  
        c=dist(p2,p3);
		 
		// 
        p=(a+b+c)/2;  
        s=sqrt(p*(p-a)*(p-b)*(p-c));  
        
        r=a*b*c/(4*s); // 
        
        angle1=Angle(r,r,a);  
        angle2=Angle(r,r,b);  
        angle3=2*pi-angle1-angle2;  
        
        angle=gcd(angle1,gcd(angle2,angle3)); //123angle 
        double ans;  
        //
        //2*pi/angle
        ///r^2*sin(angle)/2
        ans=0.5*r*r*sin(angle)*(2*pi/angle);  
        printf("%.6lf\n",ans);  
    }  
    return 0;  
}