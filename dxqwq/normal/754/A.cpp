#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int x[1003],y[1003],cnt=0;
int main(){
	int n=read(),lst=1;
    for(int i=1; i<=n; i++)
    {
        int q=read();
        if(q) x[++cnt]=lst,y[cnt]=i,lst=i+1;  
    }
    y[cnt]=n;
    if(cnt)
    {
        puts("YES");
        printf("%d\n",cnt);
        for(int i=1; i<=cnt; i++) printf("%d %d\n",x[i],y[i]);
    } else puts("NO");
	return 0;
}