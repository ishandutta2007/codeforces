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
int b[110000],a[110000];
int n,h;
bool check(int n)
{
    for(int i=1;i<=n;i++)a[i]=b[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    long long x=0,y=0;
    for(int i=1;i<=n;i++)
        if (i%2==1)x+=a[i]; else y+=a[i];
    if (x<=h && y<=h)return 1;
    return 0;
}
int main()
{
    cin>>n>>h;
    rep(i,n)scanf("%d",&b[i]);
    for(int i=n;i>=1;i--)
        if (check(i)){ cout<<i<<endl; return 0; }

    return 0;
}