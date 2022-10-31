#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
using namespace std;
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
int n;
long long a[1100];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    long long ans=-2147483647;
    for(int i=1;i<=n;i++)
    {
        long long t=(int)sqrt(a[i]);
        if (t*t==a[i])continue;
        ans=max(ans,a[i]);
    }
    cout<<ans<<endl;
}