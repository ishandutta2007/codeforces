#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, N;
    string s;
    cin >> n >> s;
    N = 1 << n;

    int A = 256, C = 0, S = 1;
    vector<int> cnt(max(A, N)), sa(N), clazz(N), sec(N);

    for (int i = 0; i < N; i++)
        cnt[s[i] - 'a']++;
    for (int a = 1; a < A; a++)
        cnt[a] += cnt[a - 1];
    for (int i = N - 1; i >= 0; i--)
        sa[--cnt[s[i] - 'a']] = i;
    for (int i = 1; i < N; i++)
        clazz[sa[i]] = C += s[sa[i]] != s[sa[i - 1]];

    while (S < N && clazz[sa[0]] == clazz[sa[1]]) {
        for (int i = 0; i < N; i++)
            sec[i] = sa[i] ^ S;
        for (int c = 0; c <= C; c++)
            cnt[c] = 0;
        for (int i = 0; i < N; i++)
            cnt[clazz[i]]++;
        for (int a = 1; a <= C; a++)
            cnt[a] += cnt[a - 1];
        for (int i = N - 1; i >= 0; i--) // backwards for stable sort
            sa[--cnt[clazz[sec[i]]]] = sec[i];

        if (2 * S >= N)
            break;

        sec[sa[0]] = C = 0;
        for (int i = 1; i < N; i++) {
            int a = sa[i] ^ S;
            int b = sa[i - 1] ^ S;
            C += clazz[a] != clazz[b] || clazz[sa[i]] != clazz[sa[i - 1]];
            sec[sa[i]] = C;
        }
        swap(clazz, sec);
        S *= 2;
    }

    int x = sa[0];
    string t(N, '0');
    for (int i = 0; i < N; i++) {
        t[i] = s[i ^ x];
    }
    cout << t << '\n';
    return 0;
}