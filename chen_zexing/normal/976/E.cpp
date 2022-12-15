#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
#include <bitset>
#include <vector>
using namespace std;
struct person
{
    int a,b;
}s[200005];
bool cmp(person a,person b)
{
    return a.a-a.b>b.a-b.b;
}
int main() {
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&s[i].a,&s[i].b);
    }
    sort(s+1,s+n+1,cmp);
    long long sum=0,ans;
    for(int i=1;i<=b;i++) sum+=max(s[i].a,s[i].b);
    for(int i=b+1;i<=n;i++) sum+=s[i].b;
    ans=sum;
    if(b==0)
    {
        printf("%lld\n",ans);
        return 0;
    }
    for(int i=1;i<=b;i++)
        if(ans<sum-max(s[i].a,s[i].b)+s[i].a*pow(2,a))
            ans=sum-max(s[i].a,s[i].b)+s[i].a*pow(2,a);
    sum=sum-max(s[b].a,s[b].b)+s[b].b;
    for(int i=b+1;i<=n;i++)
        if(ans<sum-s[i].b+s[i].a*pow(2,a))
            ans=sum-s[i].b+s[i].a*pow(2,a);
    printf("%lld\n",ans);
    return 0;
}