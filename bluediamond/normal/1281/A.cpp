#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int l = (int) s.size();
        if (s[l - 1] == 'o')
        {
            cout << "FILIPINO\n";
            continue;
        }
        if (s[l - 1] == 'u')
        {
            cout << "JAPANESE\n";
            continue;
        }
        cout << "KOREAN\n";
    }
}