#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e4 + 7;
int n, q;
string s;
char t[N];

int main()
{
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        cin >> s >> q;
        n = (int) s.size();

        while (q--)
        {
                int l, r, shift;
                cin >> l >> r >> shift;
                l--;
                r--;

                for (int i = l; i <= r; i++)
                        t[l + (i - l + shift) % (r - l + 1)] = s[i];
                for (int i = l; i <= r; i++)
                        s[i] = t[i];
        }
        cout << s << "\n";

        return 0;
}