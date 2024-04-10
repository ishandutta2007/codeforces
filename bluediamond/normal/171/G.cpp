#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b;
    int c;
    cin >> a >> b >> c;
    for (int i = 1; i <= c; i++)
    {
        swap(a, b);
        b += a;
    }
    cout << a << "\n";
}