#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <set>
#include <utility>
#include <map>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define x1 gtmshb
#define y0 gtmjtjl
#define y1 gtmsf
using namespace std;
int a[510000];
int n;
set<int> dic;
int main()
{
    cin>>n;
    rep(i,n)scanf("%d",&a[i]);
    int ans=0;
    for(int i=1;i<=n;i++)if (a[i]!=a[1])ans=max(ans,i-1);
    for(int i=1;i<=n;i++)if (a[i]!=a[n])ans=max(ans,n-i);
    cout<<ans<<endl;
    return 0;
}