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
long long a[200005],now[200005],ans=0;
int b[200005],n,in[200005],used[200005];
stack <int> bad;
queue <int> good;
void solve(int x)
{
    //cout<<x<<endl;
    used[x]=1;
    if(now[x]<0)
    {
        bad.push(x);
        if(b[x]!=-1)
        {
            if(in[b[x]]>1) in[b[x]]--;
            else solve(b[x]);
        }
        ans+=now[x];
        return;
    }
    good.push(x);
    ans+=now[x];
    if(b[x]!=-1)
    {
        now[b[x]]+=now[x];
        if(in[b[x]]>1) in[b[x]]--;
        else solve(b[x]);
    }
    return;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        now[i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        if(b[i]!=-1) in[b[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0&&used[i]==0)
        {
            solve(i);
        }
    }
    printf("%lld\n",ans);
    while(!good.empty()) {
        printf("%d ", good.front());
        good.pop();
    }
    while(!bad.empty()) {
        printf("%d ", bad.top());
        bad.pop();
    }
    printf("\n");
}