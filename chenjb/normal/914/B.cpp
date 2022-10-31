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
int a[110000];
int main()
{
    int n;
    cin>>n;
    int now=-2147483647;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int cnt=1;
    int flag=0;
    for(int i=2;i<=n;i++)
    {
        if (a[i-1]==a[i])cnt++;
        else { if (cnt%2==1)flag=1; cnt=1; }
    }
    if (cnt%2==1)flag=1;
    if (flag)puts("Conan");
    else puts("Agasa");
}