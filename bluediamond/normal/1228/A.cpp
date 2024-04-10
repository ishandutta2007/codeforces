#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
bool ok[N];
int mask[N];

int main()
{
        ok[0] = 1;
        for (int x = 1; x < N; x++)
                if (ok[x / 10] && (mask[x / 10] & (1 << (x % 10))) == 0)
                {
                        ok[x] = 1;
                        mask[x] = mask[x / 10] + (1 << (x % 10));
                }
        int l, r;
        cin >> l >> r;
        for (int j = l; j <= r; j++)
                if (ok[j])
                {
                        cout << j << "\n";
                        return 0;
                }
        cout << "-1\n";
}