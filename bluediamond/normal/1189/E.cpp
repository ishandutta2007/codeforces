#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, p, k;
map<int, int> mt;

int add(int a, int b)
{
    a += b;
    if (a >= p)
    {
        return a - p;
    }
    if (a < 0)
    {
        return a + p;
    }
    return a;
}

int mul(int a, int b)
{
    return a * (ll) b % p;
}

int pw(int a, int b)
{
    int r = 1;
    while (b)
    {
        if (b & 1)
        {
            r = mul(r, a);
        }
        a = mul(a, a);
        b /= 2;
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    /**
    quick math :
        (a + b) * (a ^ 2 + b ^ 2) = k mod p
        (a + b) * (a - b) * (a ^ 2 + b ^ 2) = k * (a - b) mod p
        (a ^ 2 - b ^ 2) * (a ^ 2 + b ^ 2) = k * (a - b) mod p
        a ^ 4 - b ^ 4 = k * (a - b) mod p
        a ^ 4 - k * a = b ^ 4 - k * b mod p
    **/

    cin >> n >> p >> k;

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, e;
        cin >> x;
        e = add(pw(x, 4), - mul(k, x));
        ans += mt[e]++;
    }
    cout << ans << "\n";

}