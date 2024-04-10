#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b;
    cin >> a >> b;
    ll sol = 0;
    for (int i = 1; i <= 60; i++)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (a <= (1LL << i) - (1LL << j) - 1 && (1LL << i) - (1LL << j) - 1 <= b)
            {
                sol++;
            }
        }
    }
    cout << sol << "\n";
}