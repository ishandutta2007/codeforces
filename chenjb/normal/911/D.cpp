#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <bitset>
using namespace std;
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
int n,q;
int a[5000];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)if(a[i]>a[j])ans++;
    ans%=2;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int len=r-l+1;
        if(len%4==3 || len%4==2 )ans^=1;
        if(ans)puts("odd");else puts("even");
    }
    return 0;
}