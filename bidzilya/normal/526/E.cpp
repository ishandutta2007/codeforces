#include <bits/stdc++.h>
using namespace std;

const int kMaxLog = 20;

int n;
int q;
vector<int> a;
vector<long long> s;
vector<int> one, to_end, bg;
long long b;

inline long long GetSum(int l, int r)
{
    if (l > r) {
        return 0;
    }
    if (l == 0) {
        return s[r];
    }
    return s[r] - s[l - 1];
}

int Solve()
{
    if (GetSum(0, n - 1) <= b) {
        return 1;
    }
    one[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        one[i] = one[i + 1];
        while (GetSum(i, one[i]) > b) {
            --one[i];
        }
    }
    to_end[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        if (one[i] == n - 1) {
            to_end[i] = 1;
        } else {
            to_end[i] = 1 + to_end[one[i] + 1];
        }
    }
    bg[n - 1] = 0;
    while (a[n - 1] + GetSum(0, bg[n - 1]) <= b) {
        ++bg[n - 1];
    }
    for (int i = n - 2; one[i] == n - 1; --i) {
        bg[i] = bg[i + 1];
        while (GetSum(i, n - 1) + GetSum(0, bg[i] - 1) > b) {
            --bg[i];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (one[i] != n - 1) {
            bg[i] = bg[one[i] + 1];
        }
    }
    int ans = n;
    for (int i = 0; i < n; ++i) {
        if (bg[i] >= i) {
            ans = min(ans, to_end[i]);
        }
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &q);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    s.resize(n);
    s[0] = a[0];
    for (int i = 1; i < n; ++i) {
        s[i] = s[i - 1] + a[i];
    }
    one.resize(n);
    to_end.resize(n);
    bg.resize(n);

    for (int itr = 0; itr < q; ++itr) {
        cin >> b;
        cout << Solve() << endl;
    }

    return 0;
}