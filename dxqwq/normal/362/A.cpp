#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define QAQ int T=read(); while(T--)
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
char ch[13][13];
signed main()
{
    QAQ
    {
        bool f=0;
        int p,q,r,s;
        for(int i=1; i<=8; i++) scanf("%s",ch[i]+1);
        for(int i=1; i<=8; i++) for(int j=1; j<=8;j++) if(ch[i][j]=='K') if(!f) p=i,q=j,f=1; else r=i,s=j;
        if(!((abs(p-r))&3) && !((abs(q-s))&3)) puts("YES"); else puts("NO");
    }
    return 0;
}