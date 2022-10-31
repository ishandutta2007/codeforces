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
#define magic 300
using namespace std;
int n,k;
int a[310000];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    if (k<n && a[k]==a[k+1]){ puts("-1"); return 0; }
    if (k==0 && a[1]==1){ puts("-1"); return 0; }
    if (k==0 && a[1]!=1){ puts("1"); return 0; }
    cout<<a[k]<<endl;
}