//  228

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define int long long
using namespace std;
int h,w,t,p=1,a,b,i;
inline int read(){int x=0,f=1;char ch='\0';while(ch<'0'||ch>'9')f=(ch=='-')?(0-f):f,ch=getchar();
while(ch>='0'&&ch<='9')x=x*10+(ch^'0'),ch=getchar();return x*f;}signed main(){h=read();w=read();
for(i=0;i<30;i++,p<<=1){if(p<=h&&4*p<=5*w){t=min(w,5*p/4);if(p*t>a*b||(p*t==a*b&&a<p))a=p,b=t;}
if(p<=w&&4*p<=5*h){t=min(h,5*p/4);if(p*t>a*b||(p*t==a*b&&a<t))a=t,b=p;}}
printf("%lld %lld\n",a,b);return 0;}