#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto get_counts(const string& s) {
    vector<int> a(26);
    for (char c : s) {
        a[c - 'A']++;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s[3] = {};
    cin >> s[0] >> s[1] >> s[2];
    int S[3] = {s[0].size(), s[1].size(), s[2].size()};
    int& A = S[0];
    int& B = S[1];
    int& C = S[2];
    vector<int> cnts[3] = {get_counts(s[0]), get_counts(s[1]), get_counts(s[2])};
    int M = 0;
    vector<array<int, 2>> matches;
    for (int i = 0; i < 26; i++) {
        int& x = cnts[0][i];
        int& y = cnts[1][i];
        int& z = cnts[2][i];
        while (x + y + z != max({x, y, z})) {
            if (x == min({x, y, z})) {
                y--, z--, M++, matches.push_back({i, 0});
            } else if (y == min({x, y, z})) {
                z--, x--, M++, matches.push_back({i, 1});
            } else {
                x--, y--, M++, matches.push_back({i, 2});
            }
        }
    }
    // Thrice use cards
    int P = min({M, A, B, C});
    for (int s = 0; s < 3; s++) {
        if (P == S[s]) {
            sort(begin(matches), end(matches), [&](auto a, auto b) {
                return (a[1] == s) < (b[1] == s); //
            });
            break;
        }
    }
    auto find_any = [&](int s) {
        for (int c = 0; c < 26; c++) {
            if (cnts[s][c] > 0) {
                cnts[s][c]--;
                return c;
            }
        }
        assert(false);
        return -1;
    };
    vector<string> cards;
    for (int i = P; i < M; i++) {
        auto [x, y] = matches[i];
        for (int s = 0; s < 3; s++) {
            if (s != y) {
                cnts[s][x]++;
            }
        }
    }
    for (int i = 0; i < P; i++) {
        auto [x, y] = matches[i];
        string card(2, '.');
        card[0] = 'A' + x;
        card[1] = 'A' + find_any(y);
        cards.push_back(card);
    }
    A -= P, B -= P, C -= P;
    // Twice used cards
    while (A + B + C != max({A, B, C})) {
        string card(2, '.');
        if (A == min({A, B, C})) {
            B--, C--, card[0] = 'A' + find_any(1), card[1] = 'A' + find_any(2);
        } else if (B == min({A, B, C})) {
            C--, A--, card[0] = 'A' + find_any(2), card[1] = 'A' + find_any(0);
        } else {
            A--, B--, card[0] = 'A' + find_any(0), card[1] = 'A' + find_any(1);
        }
        cards.push_back(card);
    }
    // Once used cards
    for (int s = 0; s < 3; s++) {
        for (int c = 0; c < 26; c++) {
            while (cnts[s][c] > 0) {
                cnts[s][c]--;
                string card(2, 'A' + c);
                cards.push_back(card);
            }
        }
    }
    cout << cards.size() << '\n';
    for (string card : cards) {
        cout << card << '\n';
    }
    return 0;
}