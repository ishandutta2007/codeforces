#include <iostream>
#include <algorithm>

using namespace std;

const long long mx = 120000;
const long long mod = 10007;

bool comp(const int a, const int b)
{
    return a > b;
}

long long l[mx], d[mx], n, i, ans;

int main()
{
    cin >> n;
    for (i = 0; i<n; i++) {
        cin >> l[i];
        d[i] = l[i];
    }
    sort(l, l+n);
    sort(d, d+n, comp);
    ans = 0;
    for (i = 0; i<n; i++) {
        ans = (ans + l[i]*d[i])% mod;
    }
    cout << ans;
    return 0;
}