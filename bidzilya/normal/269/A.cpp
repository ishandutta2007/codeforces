#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>
#include <deque>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const ll MD = (ll)1e9 + 9;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

int n;
pii a[100000];

bool cmp(const pii& p1, const pii& p2)
{
    return p1.first < p2.first;
}

bool check(int x)
{
    int cnt = 1;
    for (int i=n-1; i>=0; i--)
    {
        int r = x-a[i].first;
        if (r >= 15)
            return true;
        int mn = pow(4, r);
        if (1LL*mn*cnt < a[i].second)
            return false;
        if (1LL*mn*cnt >= 1e9)
            return true;
        x = a[i].first;
        cnt = mn*cnt;
    }

    return true;
}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a+n, cmp);

    for (int i=a[n-1].first+1; i<=a[n-1].first+15; i++)
        if (check(i))
        {
            cout << i << endl;
            break;
        }

    return 0;
}