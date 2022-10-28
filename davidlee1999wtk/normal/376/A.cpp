#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
    char s[1000005];
    int len,loc;
    int i;
    long long l=0,r=0;
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++)
        if(s[i]=='^')
        {
            loc=i;
            break;
        }
    for(i=0;i<loc;i++)
        if(s[i]>48&&s[i]<=58)
            l+=(s[i]-48)*(loc-i);
    for(i=loc+1;i<len;i++)
        if(s[i]>48&&s[i]<=58)
            r+=(s[i]-48)*(i-loc);
    if(l==r)
    {
        printf("balance\n");
        return 0;
    }
    else if(l>r)
    {
        printf("left\n");
        return 0;
    }
    else
        printf("right\n");
    return 0;
}