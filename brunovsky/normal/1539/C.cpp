#include <bits/stdc++.h>
using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    long k, x;
    cin >> N >> k >> x;
    vector<long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(begin(a), end(a));
    vector<long> overflow;
    for (int i = 1; i < N; i++) {
        long d = a[i] - a[i - 1];
        long ovf = d ? (d - 1) / x : 0;
        if (ovf > 0) {
            overflow.push_back(ovf);
        }
    }
    sort(rbegin(overflow), rend(overflow));
    long ans = overflow.size() + 1;
    while (!overflow.empty() && k >= overflow.back()) {
        k -= overflow.back();
        overflow.pop_back();
        ans--;
    }
    cout << ans << '\n';
    return 0;
}