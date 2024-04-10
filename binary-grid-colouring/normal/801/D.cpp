#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
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
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N =1e6+6; 
const int M=100010;
const int maxn=1001;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define pi acos(-1.0)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
map<int,int>mp;

struct Point
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y) {}
}p[1000010];
typedef Point point;
point operator -(Point a,Point b) {
    return point(a.x-b.x,a.y-b.y);
}
point operator +(Point a,Point b) {
    return point(a.x+b.x,a.y+b.y);
}
point operator *(Point a,double t) {
    return point(a.x*t,a.y*t);
}
point operator /(Point a,double t) {
    return point(a.x/t,a.y/t);
}
bool operator < (const Point &a,const Point &b) {
    return a.y<b.y || (fabs(a.y-b.y)<=eps && a.x<b.x);
}
bool operator == (const Point &a,const Point &b) {
    if(fabs(a.x-b.x)<=eps && fabs(a.y-b.y)<=eps)
        return true;
    return false;
}
int dcmp(double x)
{
    if(fabs(x)<=eps) return 0;
    return x<0?-1:1;
}

double dot(point a,point b) //
{
    return a.x*b.x+a.y*b.y;
}
double cross(Point a,Point b) //
{
    return a.x*b.y-a.y*b.x;
}

double disn(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    /**/
}
double lentgh(Point a)//
{
    return sqrt(dot(a,a));
}
double vec_angle(point a,point b)//
{ 
    return acos(dot(a,b)/lentgh(a)/lentgh(b));
}
double distance(Point p,Point a,Point b)
{
    point v1=b-a;
    point v2=p-a;
    return fabs(cross(v1,v2))/lentgh(v1);
    /*  
         
    */
}
double distancetoseg(Point p,Point a,Point b)
{
    if(a==b) return lentgh(p-a);
    point v1=b-a;
    point v2=p-a;
    point v3=p-b;
    if(dcmp(dot(v1,v2))<0)
        return lentgh(v2);
    else if(dcmp(dot(v1,v3))>0)
        return lentgh(v3);
    else
        return fabs(cross(v1,v2))/lentgh(v1);
    /**/
}

int n;
int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i) scanf("%lf%lf",&p[i].x,&p[i].y);
    double ans = inf;
    for(int i=1;i<=n;i++)
	{
        int last = i-1;
        int nex = i+1;
        if(last == 0) last = n;
        if(nex==n+1) nex = 1;
        ans = min(distancetoseg(p[i],p[nex],p[last])/2,ans);
	}
    printf("%.10f\n",ans);
    return 0;
}