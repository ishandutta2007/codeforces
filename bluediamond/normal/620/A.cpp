#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << max(abs(x1 - x2), abs(y1 - y2)) << "\n";

}