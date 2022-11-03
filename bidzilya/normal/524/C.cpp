#include <bits/stdc++.h>
using namespace std;

bool Find(const vector<int>& a, int n, int y)
{
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (a[m] == y) {
            return true;
        }
        if (a[m] < y) {
            l = m + 1;
        } else if (a[m] > y) {
            r = m - 1;
        }
    }
    return false;
}

int Calc(int x, const vector<int>& a, int n, int k)
{
    for (int s = 1; s <= k; ++s) {
        for (int l = 0; l <= s; ++l) {
            for (int i = 0; i < n; ++i) {
                int y = x - l * a[i];
                int r = s - l;
                if (r == 0) {
                    if (y == 0) {
                        return s;
                    }
                } else {
                    if (y % r == 0) {
                        y /= r;
                        if (Find(a, n, y)) {
                            return s;
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int q;
    scanf("%d", &q);
    for (int itr = 0; itr < q; ++itr) {
        int x;
        scanf("%d", &x);
        cout << Calc(x, a, n, k) << endl;
    }

    return 0;
}