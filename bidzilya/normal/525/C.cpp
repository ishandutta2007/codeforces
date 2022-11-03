#include <bits/stdc++.h>
using namespace std;

const int kMaxA = 1e6;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> b(kMaxA + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++b[x];
    }
    vector<int> c(kMaxA + 1, 0);
    int r = 0;
    for (int i = kMaxA; i > 0; --i) {
        if (r == 0) {
            c[i] = b[i] / 2;
            r = b[i] % 2;
        } else {
            if ((b[i] + 1) % 2 == 0) {
                c[i] = (b[i] + 1) / 2;
                r = 0;
            } else {
                if (b[i] > 0) {
                    c[i] = b[i] / 2;
                    r = 1;
                } else {
                    c[i] = 0;
                    r = 0;
                }
            }
        }
    }

    vector<int> a;
    for (int i = 1; i <= kMaxA; ++i) {
        for (int j = 0; j < c[i]; ++j) {
            a.push_back(i);
        }
    }
    long long answer = 0;
    for (int i = (int) a.size() - 1; i > 0; i -= 2) {
        answer += 1LL * a[i] * a[i - 1];
    }
    cout << answer << endl;

    return 0;
}