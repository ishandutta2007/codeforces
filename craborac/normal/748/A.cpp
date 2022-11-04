#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long n, m, a;
    cin >> n >> m >> a;
    a--;
    long long t = a / (2 * n);
    cout << (a / (2 * m)) + 1 << " " << (a % (2 * m)) / 2 + 1 << " ";
    if (a % 2 == 0)
        cout << "L" << endl;
    else
        cout << "R" << endl;
    return 0;
}