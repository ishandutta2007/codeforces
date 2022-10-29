#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
bool p[10]={0,1,0,0,0,0,1,0,1,1};
int a[]={1,8,6,9};
int main()
{
    int p0=0,p1=0,s=0;
    char c;
    while((c=getchar())!=EOF)
    {
        if(c<'0'||c>'9')break;
        if(p[c-'0'])
            p[c-'0']=0;
        else if(c!='0')putchar(c),s=(s*10+c-'0')%7,p1=1;
        else p0++;
    }
    if(!p1)
    {
        printf("1869");
    while(p0--)putchar('0');
    return 0;
    }
    for(int i=0;i<p0+4;i++)s=s*10%7;
    while(p0--)putchar('0');
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                for(int l=0;l<4;l++)
                    if(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l)
                        if((((a[i]*10+a[j])*10+a[k])*10+a[l]+s)%7==0)
                        {
    printf("%d%d%d%d",a[i],a[j],a[k],a[l]);
    puts("");
    return 0;
                    }
    return 0;
}