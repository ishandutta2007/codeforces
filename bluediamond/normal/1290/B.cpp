#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n, q, a[N], p[N][26];
string s;

int get(int c, int l, int r)
{
        return p[r][c] - p[l - 1][c];
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin >> s >> q;
        n = (int) s.size();
        for (int i = 1; i <= n; i++)
                a[i] = s[i - 1] - 'a';

        for (int c = 0; c < 26; c++)
                for (int i = 1; i <= n; i++)
                        p[i][c] = p[i - 1][c] + (a[i] == c);

        while (q--)
        {
                int l, r;
                cin >> l >> r;
                if (l == r)
                {
                        cout << "Yes\n";
                        continue;
                }
                int cnt = 0;
                for (int c = 0; c < 26; c++)
                        if (get(c, l, r))
                                cnt++;
                if (cnt <= 2 && a[l] == a[r])
                        cout << "No\n";
                else
                        cout << "Yes\n";
        }

}