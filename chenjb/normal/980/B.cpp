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
using namespace std;
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    puts("YES");
    for(int i=1;i<=n;i++)putchar('.');puts("");
    if(k&1)
    {
        if(k<=n-2)
        {
            for(int i=1;i<=(n-k)/2;i++)putchar('.');
            for(int i=1;i<=k;i++)putchar('#');
            for(int i=1;i<=(n-k)/2;i++)putchar('.');puts("");
            for(int i=1;i<=n;i++)putchar('.');puts("");
        }
        else
        {
            putchar('.');
            for(int i=1;i<=n-2;i++)putchar('#');
            putchar('.');puts("");
            k-=n-2;
            putchar('.');
            for(int i=1;i<=k/2;i++)putchar('#');
            for(int i=1;i<=n-2-k;i++)putchar('.');
            for(int i=1;i<=k/2;i++)putchar('#');
            putchar('.');puts("");
        }
    }
    else
    {
        putchar('.');
        for(int i=1;i<=k/2;i++)putchar('#');
        for(int i=1;i<=n-1-k/2;i++)putchar('.');puts("");
        putchar('.');
        for(int i=1;i<=k/2;i++)putchar('#');
        for(int i=1;i<=n-1-k/2;i++)putchar('.');puts("");
    }
    for(int i=1;i<=n;i++)putchar('.');puts("");
    return 0;
}