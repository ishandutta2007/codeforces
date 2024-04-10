#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int d[1000003];
int main()
{
    int n=read(),m=n-1;
    while(m--) d[read()]++,d[read()]++;
    for(int i=1; i<=n; i++) if(d[i]==2) puts("NO"),exit(0);
    puts("YES"); 
	return 0;
}