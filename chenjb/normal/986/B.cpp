#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
int n;
int a[1100000];
long long t[1100000];
int lowbit(int x)
{
    return x & (-x);
}
void insert(int k)
{
    while (k<=n)
    {
        t[k]++;
        k+=lowbit(k);
    }
}
long long get(int p)
{
    long long ret=0;
    while (p)
    {
        ret+=t[p];
        p-=lowbit(p);
    }
    return ret;
}
long long calc()
{
    long long ans=0;
    for(int i=n;i>=1;i--)
    {
        ans=ans+get(a[i]-1);
        insert(a[i]);
    }
    return ans;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if (((calc()^n) & 1)==1)puts("Um_nik"); else puts("Petr");
}