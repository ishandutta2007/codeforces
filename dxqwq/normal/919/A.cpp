#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int main()
{
    int n=read();
    double m=read();
    double Min=9999999;
    while(n--)
    {
        double a=read(),b=read();
        Min=min(Min,m/b*a);
    }
    printf("%.10lf",Min);
    return 0;
}