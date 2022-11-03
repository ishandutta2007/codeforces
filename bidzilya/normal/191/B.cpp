#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <map>
#include <fstream>
#include <cstdio>
using namespace std;

typedef long long lli;
typedef pair<int,int> pii;

bool cmp(const pii & a, const pii & b)
{
     return (a.first>b.first);
}

pii a[111111];

int main()
{
    int n,k;
    cin >> n >> k;
    lli b;
    cin >> b;
    for (int i=0;i<n-1;i++)
    {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a, a+n-1, cmp);
    for (int i=0;i<k-1;i++)
        b -= a[i].first;
    int tk = -1;
    for (int i=k-1;i<n-1;i++)
        if (b-a[i].first<0 && (tk==-1 || a[i].second<a[tk].second))
           tk=i;
    if (tk==-1)
       cout << n;
    else
    {
        int ans = a[tk].second;
        for (int i=0;i<k-1;i++)
            ans = min(ans, a[i].second);
        cout << ans;
    }
    return 0;
}