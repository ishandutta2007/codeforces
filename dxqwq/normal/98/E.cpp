#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
double f[1010][1010];
double dfs(int n,int m)
{
    if(n==0)return 1.0/(1+m);
    if(m==0)return 1.0;
    if(f[n][m]>1e-8)return f[n][m];
    double A=1.0*m/(m+1)*(1.0-dfs(m-1,n));
    //real,believe (next)
    double B=1.0/(m+1)+1.0*m/(m+1)*(1.0-dfs(m-1,n));
    //real,unbelieve 
    double C=1.0;
    //fake,believe (lose)
    double D=1.0-dfs(m,n-1);
    //fake,unbelieve (next)
    double p=(D-C)/(A-B-C+D);
    return f[n][m]=A*p+1-p;
}
signed main()
{
    int n=read(),m=read();
    double ans=dfs(n,m);
    printf("%.10lf %.10lf",ans,1.0-ans);
    return 0;
}