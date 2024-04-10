#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 100005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
double v;
double Time(double X1,double Y1,double X2,double Y2)
{
    /*
    debug(X1);
    debug(X2);
    debug(Y1);
    debug(Y2);
    debug(v);*/
    return sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2))/v;
}
int main()
{
    double c1,c2,r1,r2,t,vx,vy,wx,wy,l,r,mid;
    int i;
    cin>>c1>>r1>>c2>>r2>>v>>t>>vx>>vy>>wx>>wy;
    //debug(Time(c1+vx*t,r1+vy*t,c2,r2));
    if(Time(c1+vx*t,r1+vy*t,c2,r2)<=t)
    {
        l=0,r=t;
        for(i=1;i<=200;i++)
        {
            mid=(r+l)/2;
            if(Time(c1+vx*mid,r1+vy*mid,c2,r2)<mid)
                    r=mid;
            else l=mid;
        }
        printf("%.12f\n",(double)mid);
    }
    else
    {
        l=t,r=1e15;
        for(i=1;i<=200;i++)
        {
            mid=(r+l)/2;
            //debug(mid);
            if(Time(c1+vx*t+wx*(mid-t),r1+vy*t+wy*(mid-t),c2,r2)<mid)
                r=mid;
            else l=mid;
        }
        printf("%.12f\n",(double)mid);
    }
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))
/*
-9680 -440 9680 440
969 1000
-968 -44
-968 -44

*/