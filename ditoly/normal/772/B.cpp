#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
inline int read()
{
    int x,f=1;char c;
    while((c=getchar())<'0'||c>'9')if(c=='-')f=0;
    for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
    return f?x:-x;
}
#define MN 1000
struct point{double x,y;}p[MN+5];
double dis(point a){return sqrt(a.x*a.x+a.y*a.y);}
point operator-(point a,point b){return (point){a.x-b.x,a.y-b.y};}
double operator*(point a,point b){return a.x*b.y-a.y*b.x;}
int main()
{
    int n=read(),i,j;double ans=1e18;
    for(i=0;i<n;++i)p[i].x=read(),p[i].y=read();
    p[n]=p[0];p[n+1]=p[1];
    for(i=0;i<n;++i)ans=min(ans,fabs((p[i+1]-p[i])*(p[i+2]-p[i]))/dis(p[i]-p[i+2]));
    printf("%.10lf",ans/2);
}