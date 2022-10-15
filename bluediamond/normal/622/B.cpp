#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int m;
    cin >> s >> m;
    m += 60 * (10 * (s[0] - '0') + s[1] - '0') + 10 * (s[3] - '0') + s[4] - '0';
    m %= (60 * 24);
    int h = m / 60;
    m %= 60;
    if (h < 10)
    {
        cout << 0;
    }
    cout << h << ":";
    if (m < 10)
    {
        cout << 0;
    }
    cout << m << "\n";
    
}