/**
 *
 * With Love from Mihnea Andreescu
 *
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2000 + 7;

int n, a[N], b[N];
int t[N], poz[N];
bool viz[N];
int g[N];

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin >> n;
        for (int i = 1; i <= n; i++)
                cin >> a[i];
        for (int i = 1; i <= n; i++) {
                cin >> b[i];
                t[b[i]] = i;
        }
        vector <pair <int, int>> swaps;
        for (int i = 1; i <= n; i++)
                a[i] = t[a[i]];
        for (int i = 1; i <= n; i++)
                poz[a[i]] = i;
        int ntt = 0;
        for (int i = 1; i <= n; i++) {
                if (g[i] == 0) {
                        int j = i;
                        ntt++;
                        while (g[j] == 0) {
                                g[j] = ntt;
                                j = poz[j];
                        }
                }
        }
        int cost = 0;
        for (int i = 1; i <= n; i++) {
                int j = 1;
                for (int k = i; k <= n; k++)
                        if (a[k] == i)
                                j = k;
                cost += (j - i);
                int last = j;
                for (int k = j; k >= i; k--)
                        if (k < a[k] && last <= a[k] && g[last] == g[k]) {
                                swaps.push_back({k, last});
                                swap(a[k], a[last]);
                                last = k;
                        }
        }
        cout << cost << "\n" << (int) swaps.size() << "\n";;
        for (auto &x : swaps)
                cout << x.first << " " << x.second << "\n";
        return 0;
}