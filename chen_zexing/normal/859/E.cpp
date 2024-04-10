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
int f[200005],edge[200005],s[200005],flag[200005];
int find(int x)
{
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
int main()
{
    int n,a,b;
    cin>>n;
    for(int i=1;i<=2*n;i++)
    {
        f[i]=i;
        s[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        if(a==b||flag[find(a)]||flag[find(b)])
        {
            flag[find(a)]=1;
            continue;
        }
        a=find(a);
        b=find(b);
        if(a!=b)
        {
            s[a]+=s[b];
            edge[a]+=edge[b];
            edge[a]++;
            f[b]=a;
        }
        else edge[a]++;
    }
    long long ans=1;
    for(int i=1;i<=2*n;i++)
    {
        if(f[i]==i)
        {
            //printf("%d\n",i);
            if(flag[i]);
            else if(edge[i]==s[i]&&flag[i]==0) ans=ans*2%1000000007;
            else ans=ans*s[i]%1000000007;
        }
    }
    printf("%lld\n",ans);
}