#include <bits/stdc++.h>
using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    vector<long> prefix(N + 1);
    for (int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + (s[i] - 'a' + 1);
    }
    for (int q = 0; q < Q; q++) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << '\n';
    }
    return 0;
}