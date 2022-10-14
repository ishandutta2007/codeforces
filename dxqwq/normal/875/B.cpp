#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
bool a[1000003];
int main()
{
    int n=read(),lst=0;
    printf("1");
    for(int i=1; i<=n; i++)
    {
        int pos=read();
        a[pos]=1;
        while(lst<=n&&a[n-lst]==1) ++lst;
        printf(" %d",i-lst+1);
    }
    return 0;
}