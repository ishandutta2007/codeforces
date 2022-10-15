#include <bits/stdc++.h>

using namespace std;

string a, b;

const int N = (int) 1e6 + 7;
int urm[N][26];
bool seen[26];

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> a >> b;
        int ln = (int) a.size();

        for (int c = 0; c < 26; c++)
        {
                urm[ln][c] = -1;
        }

        for (int i = ln - 1; i >= 0; i--)
        {
                seen[a[i] - 'a'] = 1;
                for (int c = 0; c < 26; c++)
                {
                        urm[i][c] = urm[i + 1][c];
                }
                urm[i][a[i] - 'a'] = i;
        }

        int tour = 1, poz = 0;

        for (auto &ch : b)
        {
                int c = ch - 'a';
                if (seen[c] == 0)
                {
                        cout << "-1\n";
                        return 0;
                }
                int x = urm[poz][c];
                if (x == -1)
                {
                        tour++;
                        poz = urm[0][c] + 1;
                }
                else
                {
                        poz = urm[poz][c] + 1;
                }
        }

        cout << tour << "\n";

        return 0;
}