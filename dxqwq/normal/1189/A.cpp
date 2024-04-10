#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char ch[1000003];
int main()
{
    int n=read();
    scanf("%s",ch+1);
    if(n&1)
    {
        puts("1");
        for(int i=1; i<=n; i++) printf("%c",ch[i]);
        puts("");
        return 0;
    }
    int cnt=0;
    for(int i=1; i<=n; i++) if(ch[i]=='1') ++cnt;
    if(cnt*2==n)
    {
        puts("2");
        printf("%c ",ch[1]);
        for(int i=2; i<=n; i++) printf("%c",ch[i]);
        puts("");
    }
    else 
    {
        puts("1");
        for(int i=1; i<=n; i++) printf("%c",ch[i]);
        puts("");
        return 0;
    }
	return 0;
}