#include <bits/stdc++.h>

using namespace std;

#define long int64_t

template <typename T, typename... Rs>
string to_string(const vector<T, Rs...>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}
template <typename T, typename... Rs>
ostream& operator<<(ostream& out, const vector<T, Rs...>& v) {
    return out << to_string(v);
}

#define debug(...) cerr << "[" #__VA_ARGS__ " = " << (__VA_ARGS__) << "]\n"

int within(int a, int b, int c) { return min(max(a, b), c); }

// Fuck this problem. I guess I suck at combinatorics.

int main() {
    ios::sync_with_stdio(false);
    int N, p;
    cin >> N >> p;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(begin(arr), end(arr));

    // compute smallest non-zero x
    int x = 0;
    for (int i = 0; i < N; i++) {
        x = max(x, arr[i] - i);
    }
    debug(x);

    vector<int> qnt(N);
    vector<int> prefix(N + 1);
    for (int i = 0; i < N; i++) {
        qnt[x + N - 1 - within(x, arr[i], x + N - 1)]++;
    }
    for (int i = 0; i < N; i++) {
        prefix[i + 1] = qnt[i] + prefix[i];
    }

    debug(qnt), debug(prefix);

    vector<int> fac(N + 1); // largest power of p dividing n!
    for (long b = p; b <= N; b *= p) {
        for (int n = b; n <= N; n += b) {
            fac[n]++;
        }
    }
    for (int n = 2; n <= N; n++) {
        fac[n] += fac[n - 1];
    }
    debug(fac);

    set<int> nums;

    for (int i = 0; i < N; i++) {
        // qnt[N - i - 1] to qnt[N - 1]
        // prefix[N] - prefix[N - i - 1]
        int num = N - prefix[N - i - 1];
        if (fac[num] == 0) {
            nums.insert(i);
        }
    }

    for (int i = 0; i + 1 < N && !nums.empty(); i++) {
        int q = qnt[i];
        if (q >= p) {
            nums.clear();
        } else if (q > 0) {
            // there are periods of divisibility by p
            // a period starts when num+add is divisible by p
            // a period ends when den+add is divisible by p
            // length is q
            // numerator is j + num
            // denominator is j + den
            int num = i + 1 - prefix[i];
            int den = num - q;
            int j = 0;
            for (int z = 0; z < q && j + num < N - prefix[i]; z++, j++) {
                if (fac[j + num] == fac[j + den]) {
                    j += p - (j + num) % p;
                    assert((j + num) % p == 0);
                }
                if (j + num >= N - prefix[i]) {
                    break;
                }
                int bad = j;
                while (bad + num < N - prefix[i] && nums.count(bad)) {
                    nums.erase(bad);
                    bad += p;
                }
            }
        }
    }

    vector<int> ans(begin(nums), end(nums));

    int A = ans.size();
    cout << A << endl;
    for (int i = 0; i < A; i++) {
        cout << x + ans[i] << " \n"[i + 1 == A];
    }
    return 0;
}