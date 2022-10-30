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
int n,m;
int a[510][510],b[510][510];
int main()
{
    cin>>n>>m;
    rep(i,n)rep(j,m)scanf("%d",&a[i][j]);
    rep(i,n)rep(j,m)scanf("%d",&b[i][j]);
    for(int i=1;i<=n-1;i++)
    for(int j=1;j<=m-1;j++)
        if (a[i][j]!=b[i][j])
            a[i][j]^=1,a[i+1][j]^=1,a[i][j+1]^=1,a[i+1][j+1]^=1;

    int flag=1;
    rep(i,n)rep(j,m)if (a[i][j]!=b[i][j])flag=0;

    if (flag)puts("Yes"); else puts("No");
}