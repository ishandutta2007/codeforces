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
int a[1100000];
int main() 
{
   cin>>n>>m;
   for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if (m<n){ puts("0"); return 0; }
    long long ans=1;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            ans=(1ll*abs(a[i]-a[j])%m)*ans%m;
    cout<<ans<<endl;
    return 0;
}