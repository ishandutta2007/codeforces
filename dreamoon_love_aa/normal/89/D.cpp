#include<stdio.h>
#include<algorithm>
using namespace std;
#include<math.h>
struct Point{
    long long x,y,z;
    void scan(){scanf("%I64d%I64d%I64d",&x,&y,&z);}
    Point operator+(Point X){return (Point){x+X.x,y+X.y,z+X.z};}
    Point operator-(Point X){return (Point){x-X.x,y-X.y,z-X.z};}
    long long operator*(Point X){return x*X.x+y*X.y+z*X.z;}
}Ball,Bv,mine,strike;
long long R,n;
long long sqr(long long x){return x*x;}
long long Dis2(Point X,Point Y){
    return sqr(X.x-Y.x)+sqr(X.y-Y.y)+sqr(X.z-Y.z);
}
double Test(Point X,long long r){
    if(Bv*(X-Ball)<=0)return 1e30;
    long long c=Bv*X;
    long long L2=Dis2(X,Ball);
    double d2=(double)sqr(Bv*Ball-c)/Dis2(Bv,(Point){0,0,0});
    double s2=L2-d2;
    if(L2*Dis2(Bv,(Point){0,0,0})-sqr(Bv*Ball-c)>sqr(r+R)*Dis2(Bv,(Point){0,0,0}))return 1e30;
    double l=sqrt(d2)-sqrt(sqr(R+r)-s2);
    return l/sqrt(sqr(Bv.x)+sqr(Bv.y)+sqr(Bv.z));
}
main(){
    long long n,m,r;
    double an=1e30;
    Ball.scan();
    Bv.scan();
    scanf("%I64d",&R);
    scanf("%I64d",&n);
    while(n--){
        mine.scan();
        scanf("%I64d",&r);
        an=min(an,Test(mine,r));
        scanf("%I64d",&m);
        while(m--){
            strike.scan();
            an=min(an,Test(mine+strike,0));
        }
    }
    if(an==1e30)puts("-1");
    else printf("%.10lf\n",an);
}