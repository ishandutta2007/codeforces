#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct rolling_hasher {
    static constexpr size_t base = 2001539UL;
    static constexpr size_t mask = (1 << 26) - 1;
    size_t n, mul;

    explicit rolling_hasher(size_t n) : n(n), mul(powovf(n) & mask) {}

    size_t operator()(const char* s, const char* e) const noexcept {
        size_t seed = 0;
        while (s != e) {
            seed = (seed * base + *s++) & mask;
        }
        return seed;
    }

    size_t operator()(const string& s) const noexcept {
        return (*this)(s.data(), s.data() + s.length());
    }

    size_t roll(size_t seed, unsigned char out, unsigned char in) const noexcept {
        return (seed * base + in + (mask + 1 - out) * mul) & mask;
    }

    static constexpr size_t powovf(size_t e) {
        size_t power = 1, b = base;
        while (e) {
            if (e & 1) {
                power = power * b;
            }
            e >>= 1;
            b = b * b;
        }
        return power;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> words(N);
        bool yes = false;
        for (int i = 0; i < N; i++) {
            cin >> words[i];
            yes |= words[i].front() == words[i].back();
        }

        if (yes) {
            cout << "YES\n";
            continue;
        }

        set<string> ss;
        for (auto s : words) {
            reverse(begin(s), end(s));
            yes |= ss.count(s) > 0;
            int S = s.size();
            if (S == 2) {
                for (char c = 'a'; c <= 'z'; c++) {
                    s.push_back(c);
                    yes |= ss.count(s) > 0;
                    s.pop_back();
                }
            } else {
                char c = s.back();
                s.pop_back();
                yes |= ss.count(s) > 0;
                s.push_back(c);
            }
            if (yes) {
                break;
            }

            reverse(begin(s), end(s));
            ss.insert(s);
        }

        cout << (yes ? "YES\n" : "NO\n");
    }
    return 0;
}