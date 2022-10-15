#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, t;
    cin >> a >> b >> c;
    t = min(a, min(b / 2, c / 4));
    cout << t * 7 << "\n";
}