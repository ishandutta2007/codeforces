#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#include <cassert>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
int a[305];
int main()
{
    int n,x,k;
    cin>>n>>k;
    memset(a,255,sizeof(a));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(a[x]==-1)
            for(int j=max(0,x-k+1);j<=x;j++)
            {
                if(a[j]==-1||a[j]==j)
                {
                    for(int t=j;t<=x;t++)a[t]=j;
                    break;
                }
            }
        printf("%d ",a[x]);
    }
    puts("");
    return 0;
}