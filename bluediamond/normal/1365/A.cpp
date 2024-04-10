#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int N = 50 + 7;
int n, m;
bool x[N];
bool y[N];

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int t;
        cin >> t;
        while (t--) {
                cin >> n >> m;
                for (int i = 1; i <= n; i++)
                        for (int j = 1; j <= m; j++) {
                                int a;
                                cin >> a;
                                x[i] |= a;
                                y[j] |= a;
                        }
                int r = 0, c = 0;
                for (int i = 1; i <= n; i++)
                        if (x[i] == 0)
                                r++;
                        else
                                x[i] = 0;
                for (int i = 1; i <= m; i++)
                        if (y[i] == 0)
                                c++;
                        else
                                y[i] = 0;
                if (min(r, c) % 2 == 0)
                        cout << "Vivek\n";
                else
                        cout << "Ashish\n";
        }
        return 0;
}