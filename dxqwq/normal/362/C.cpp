#include<bits/stdc++.h>
using namespace std;
inline int read()
{
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline long long readll()
{
   long long s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[2000003],f[7000003],l[5003][5003];
int main(){
    int n=read();
    int x,y,z,s=0;
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n;j++) l[i][j]=l[i-1][j];
        for(int j=0;j<a[i];j++) ++l[i][j];
    }
    for(int i=1;i<=n;i++) s+=l[i][a[i]];
    int Min=998244535,t;
    for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) if(a[i]>a[j])
    {
        int x=l[j][a[j]]-l[i-1][a[j]];
        int y=l[j][a[j]]-l[i][a[j]]-l[j][a[i]]+l[i][a[i]];
        int z=l[j][a[i]]-l[i][a[i]];
        if(s+z-x-y<Min) Min=s+z-x-y,t=0;
        if(s+z-x-y==Min) t++;
    }
    printf("%d %d\n",Min,t),exit(0);
}