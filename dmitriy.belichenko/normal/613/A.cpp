#include <vector>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<set>
#include<map>
#include <iomanip>
#include<string>
#include<iostream>

#include<math.h>
#define count count1557
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const double pi=acos(-1.0);

double mx,mn=1e12;
long long xx,yy,x[100005],y[100005];
int n;

int main(){
    cin >> n >> xx >> yy;
    double a,b,c;
    for(int i=1;i<=n;i++)
    {
        cin >> x[i] >>y[i];
        x[i]-=xx;
        y[i]-=yy;
        c=(x[i] * x[i])+ (y[i] * y[i]);
        mx=max(c,mx);
        mn=min(c,mn);
    }
    x[n+1]=x[1];
    y[n+1]=y[1];
    for(int i=1;i<=n;i++)
    {
        a=(x[i] * x[i])+ (y[i] * y[i]);
        b=(x[1+i] * x[1+i])+ (y[i+1] * y[i+1]);
        c=(x[i]-x[i+1])*(x[i]-x[i+1])+(y[i]-y[i+1])*(y[i]-y[i+1]);
        if(a+c<b)continue;
        if(b+c<a)continue;
        a=sqrt(a);
        b=sqrt(b);
        c=sqrt(c);
        double p=(a+b+c)/2;
        double S=sqrt(p*(p-a)*(p-b)*(p-c));
        p=1.0*(2*S/c)*(2*S/c);
        mn=min(mn,p);
    }
    cout << setprecision(20) << pi*(mx-mn) ;
}