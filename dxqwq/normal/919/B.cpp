#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline int sum(int x)
{
    int res=0;
    while(x)
    {
        res+=x%10,x/=10;
    }
    return res;
}
int main()
{
    int n=read(),i=1,j=0;
    for(i=1; j<n; i++) if(sum(i)==10) ++j;
    cout<<i-1;
    return 0;
}