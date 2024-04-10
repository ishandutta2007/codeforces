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
int n;
int a[110000],b[110000];
int main()
{
    scanf("%d",&n);
    int now=2147483647;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        now=min(now,a[i]);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if (a[i]!=now)continue;
        b[++cnt]=i;
    }
    int ans=2147483647;
    for(int i=1;i<cnt;i++)ans=min(ans,b[i+1]-b[i]);
    cout<<ans<<endl;
}