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
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
int a[110],b[110];
int main() 
{
    int T;
    cin>>T;
    while (T--)
    {
        scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        rep(i,n)scanf("%d",&b[i]);
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++)printf("%d%c",a[i],i==n?'\n':' ');
        for(int i=1;i<=n;i++)printf("%d%c",b[i],i==n?'\n':' ');
    }
    return 0;
}