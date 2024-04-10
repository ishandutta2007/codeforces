#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003],b[1000003];
int main()
{
    int n=read();
    for(int i=1; i<=n; i++) b[i]=read();
    sort(b+1,b+n+1);
    if(n&1) 
    {
        a[n/2+1]=b[1];
        int l=n/2,r=n/2+2;
        bool f=1;
        for(int i=2; i<=n; i++) {if(f) a[l--]=b[i]; else a[r++]=b[i]; f^=1;} 
    }
    else 
    {
        int l=n/2,r=n/2+1;
        bool f=1;
        for(int i=1; i<=n; i++) {if(f) a[l--]=b[i]; else a[r++]=b[i]; f^=1;} 
    }
    for(int i=2; i<n; i++) if(a[i-1]+a[i+1]<=a[i]) puts("NO"),exit(0);
    if(a[n]+a[2]<=a[1]) puts("NO"),exit(0);
    if(a[n-1]+a[1]<=a[n]) puts("NO"),exit(0);
    puts("YES");
    for(int i=1; i<=n; i++) printf("%d ",a[i]);
	return 0;
}