#include <bits/stdc++.h>
using namespace std;

/**
 * Compute the suffix array of a string.
 * sa[i]: Starting index of the rotation in the (i+1)th lexicographical order.
 *
 * You should append to s a value smaller than any value in s and then pop the front
 * element of the returned SA. If not, the algorithm computes a sorting of rotations
 * instead of suffixes, breaking ties arbitrarily.
 * To get the LCP as well do so before popping SA[0], and then pop LCP[0] as well.
 *
 * Complexity: O(N log N)
 * Reference: https://cp-algorithms.com/string/suffix-array.html
 */
template <typename Vec, typename T = typename Vec::value_type>
auto build_cyclic_shifts(const Vec& s, int A, T first) {
    int N = s.size();
    if (N == 0)
        return vector<int>{};

    int C = 0, S = 1; // #classes - 1, sorted width
    vector<int> cnt(max(A, N), 0), sa(N, 0), clazz(N, 0), perm(N, 0), clazzn(N, 0);

    for (int i = 0; i < N; i++)
        cnt[s[i] - first]++;
    for (int a = 1; a < A; a++)
        cnt[a] += cnt[a - 1];
    for (int i = N - 1; i >= 0; i--)
        sa[--cnt[s[i] - first]] = i;
    for (int i = 1; i < N; i++)
        clazz[sa[i]] = C += s[sa[i]] != s[sa[i - 1]];

    while (S < N) {
        for (int i = 0; i < N; i++)
            perm[i] = sa[i] - S, perm[i] += perm[i] < 0 ? N : 0;
        for (int c = 0; c <= C; c++)
            cnt[c] = 0;
        for (int i = 0; i < N; i++)
            cnt[clazz[perm[i]]]++;
        for (int a = 1; a <= C; a++)
            cnt[a] += cnt[a - 1];
        for (int i = N - 1; i >= 0; i--) // backwards for stable sort
            sa[--cnt[clazz[perm[i]]]] = perm[i];

        if (2 * S >= N)
            break;

        clazzn[sa[0]] = C = 0;
        for (int i = 1; i < N; i++) {
            int j = sa[i] + S;
            int k = sa[i - 1] + S;
            j -= j >= N ? N : 0;
            k -= k >= N ? N : 0;
            C += clazz[k] != clazz[j] || clazz[sa[i]] != clazz[sa[i - 1]];
            clazzn[sa[i]] = C;
        }
        swap(clazz, clazzn);
        S *= 2;
    }

    return sa;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    if (N == 1 || s[0] < s[1]) {
        string ans(K, s[0]);
        cout << ans << endl;
        return 0;
    }
    auto sa = build_cyclic_shifts(s + "|", 128, '\0');
    vector<int> order(N + 1);
    for (int i = 0; i <= N; i++) {
        order[sa[i]] = i;
    }
    for (int i = 1; i < N; i++) {
        if (order[i] > order[0]) {
            s = s.substr(0, i);
            break;
        }
    }
    s.reserve(K);
    while (int(s.size()) < K) {
        s = s + s;
    }
    s.resize(K);
    cout << s << endl;
    return 0;
}