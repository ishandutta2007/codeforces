//dp
//QAQ
#include<bits/stdc++.h>
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int a[13];
signed main()
{
    int n=read();
    for(int i=1; i<=n; i++) 
    {
        char ch=getchar();
        while(!isdigit(ch)) ch=getchar();
        int x=ch-48;
        if(x==4) a[2]+=2,a[3]++;
        else if(x==6) a[3]++,a[5]++;
        else if(x==8) a[2]+=3,a[7]++;
        else if(x==9) a[2]++,a[3]+=2,a[7]++;
        else if(x>1) a[x]++;
    }
    for(int i=1; i<=a[7]; i++) printf("7");
    for(int i=1; i<=a[5]; i++) printf("5");
    for(int i=1; i<=a[3]; i++) printf("3");
    for(int i=1; i<=a[2]; i++) printf("2");
    return 0;
}