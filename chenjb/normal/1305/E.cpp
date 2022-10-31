#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n,m;
int cnt[110000];
long long calc(int n)
{
    return ((n*(n-1)/2)-n/2)/2;
}
int main() 
{
    cin>>n>>m;
    if (m==0)
    {
        for(int i=1;i<=n;i++)printf("%d ",2*n+i);
        puts("");
        return 0;
    }
    if (m>calc(n))
    {
        puts("-1");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        long long have=calc(i);
        if (have<m)continue;
        int k=i-1;
        for(int j=1;j<=k;j++)printf("%d ",j);
        for(int x=1;x<=k;x++)
            for(int y=x+1;y<=k;y++)
                cnt[x+y]++;
        int need=m-calc(k);
        for(int j=k+1;j<=2*k;j++)
            if (cnt[j]==need)
            {
                printf("%d ",j);
                break;
            }
        int s=5e8;
        for(int j=k+2;j<=n;j++)
        {
            printf("%d ",s);
            s+=3*n;
        }
        puts("");
        return 0;
    }
   
}