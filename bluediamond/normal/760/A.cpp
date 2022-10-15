#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int cnt[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d, a = 1;
    cin >> n >> d;
    d--;

    for (int i = 0; i < cnt[n]; i++)
    {
        a += (i && d == 0);
        d = (d + 1) % 7;
    }

    cout << a << "\n";

}