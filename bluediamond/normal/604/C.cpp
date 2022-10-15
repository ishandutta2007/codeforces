#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e5 + 7;
int n;
string s;
int alt[2];
int cnt = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            alt[0] = max(alt[0], 1 + alt[1]);
        }
        else
        {
            alt[1] = max(alt[1], 1 + alt[0]);
        }
    }
    for (int i = 1; i < n; i++)
    {
        cnt += (s[i] == s[i - 1]);
    }
    int ans = max(alt[0], alt[1]) + min(2, cnt);
    cout << ans << "\n";
}