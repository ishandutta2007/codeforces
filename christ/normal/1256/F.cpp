#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

char s[2][MAXN];
int cnt[2][26];
long long inv[2];

int main()
{
    int q;
    scanf("%i", &q);
    while (q--)
    {
        int n;
        scanf("%i%s%s", &n, s[0], s[1]);
        bool pos = false;
        for (int k = 0; k < 2; k++)
        {
            inv[k] = 0;
            fill(cnt[k], cnt[k] + 26, 0);
            for (int x = 0; x < n; x++)
            {
                int c = s[k][x] - 'a';
                for (int y = c + 1; y < 26; y++)
                    inv[k] += cnt[k][y];
                cnt[k][c]++;
            }
            for (int x = 0; x < 26; x++)
                pos |= cnt[k][x] >= 2;
        }
        for (int x = 0; x < 26; x++)
            if(cnt[0][x] != cnt[1][x])
                goto NXT;
        if (pos || (((inv[0] ^ inv[1]) & 1) == 0))
        {
            printf("YES\n");
            continue;
        }
NXT:
        printf("NO\n");
    }
}