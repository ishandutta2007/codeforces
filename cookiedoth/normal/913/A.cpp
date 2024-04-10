#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll MOD = 1e9 + 7;
ll n, m, p;

int main()
{
    cin >> n >> m;
    p = 1;
    for (int i = 0; i < n; ++i) {
        p *= 2;
        if (p > m)
            break;
    }
    cout << (m % p) << endl;
    return 0;
}