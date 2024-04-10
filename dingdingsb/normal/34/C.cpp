#include<bits/stdc++.h>
using namespace std;
int a[101],n=1;
inline void input()
{
    while(1)
    {
        char ch=getchar();
        if(ch==',') ++n;
        else if(ch>='0'&&ch<='9')
            a[n]=a[n]*10+ch-'0';
        else return;
    }
}
int main()
{
    int f=0;input();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
    {
        int c=i;
        while(a[c+1]-a[c]==1||a[c+1]-a[c]==0) ++c;
        if(a[c]==a[i])
        {
            if(f==0) printf("%d",a[i]),f=1;
            else printf(",%d",a[i]);i=c;continue;
        }
        if(f==0) printf("%d-%d",a[i],a[c]),f=1;
        else printf(",%d-%d",a[i],a[c]);i=c;
    }
    return 0;
}