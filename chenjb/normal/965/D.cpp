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
#define maxn 110000
#define magic 26
using namespace std;
int a[110000];
int main()
{
    int w,l;
    cin>>w>>l;
    for(int i=1;i<w;i++)scanf("%d",&a[i]);
    int now=0;
    for(int i=1;i<=l;i++)now+=a[i]; 
    int ans=now;
    for(int i=l+1;i<w;i++)
    {
        now-=a[i-l];
        now+=a[i];
        ans=min(ans,now);
    }
    cout<<ans<<endl;
}