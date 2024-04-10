#include <iostream>
#include <math.h>
using namespace std;
int n,v[100005],r=0,pas;
char ch;
bool ok(int l)
{
    for(int i=0;i<26;i++)
    {
        int last=0,acm=1;
        for(int j=1;j<=n;j++)
        {
            if(v[j]==i+'a')
                last=j;
            if(j-last>=l)
                {
                    acm=0;
                    break;
                }
        }
        if(acm)
            return 1;
    }
    return 0;
}
int main()
{
    while(1)
    {
        ch=cin.get();
        if(ch=='\n')
            break;
        v[++n]=ch;
    }
    pas=1<<int(log2(n));
    while(pas)
    {
        if(ok(r+pas)==0)
            r+=pas;
        pas/=2;
    }
    cout<<r+1;
    return 0;
}
/**

**/