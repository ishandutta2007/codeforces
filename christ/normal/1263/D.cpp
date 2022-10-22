#include <bits/stdc++.h>

using namespace std;

vector<int> par(30);

int find(int n)
{
    if (n == par[n])
        return n;
    return par[n] = find(par[n]);
}

void merge(int a, int b)
{
    par[find(a)] = find(b);
}

char s[256];

int main()
{
    iota(par.begin(), par.end(), 0);
    int n;
    scanf("%i", &n);
    int has = 0;
    while (n--)
    {
        scanf(" %s", s);
        char prev = s[0];
        has |= (1 << prev - 'a');
        for (int x = 1; s[x] != '\0'; x++)
        {
            has |= 1 << (s[x]- 'a');
            if (s[x] != prev)
            {
                merge(prev - 'a', s[x] - 'a');
                prev = s[x];
            }
        }
    }
    int ans = 0;
    for (int x = 0; x < 26; x++)
        if ((has>>x&1) && x == find(x))
            ans++;
    printf("%i\n", ans);
}