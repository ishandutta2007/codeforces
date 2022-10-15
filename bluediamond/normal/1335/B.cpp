#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        for (int i = 0; i < b; i++)
        {
            s += (char) ('a' + i);
        }
        for (int i = 0; i < a - b; i++)
        {
            s += s.back();
        }
        while ((int) s.size() < n)
        {
            int sz = (int) s.size();
            char c = s[sz - a];
            s += c;
        }
        cout << s << "\n";
    }

}