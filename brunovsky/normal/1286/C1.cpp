#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

vector<string> QUERY(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int n = r - l + 1;
    int S = n * (n + 1) / 2;
    vector<string> s(S);
    for (int i = 0; i < S; i++) {
        cin >> s[i];
        if (s[i] == "-") {
            exit(0);
        }
        sort(begin(s[i]), end(s[i]));
    }
    sort(begin(s), end(s));
    return s;
}

void ANSWER(string s) {
    cout << "! " << s << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    auto all = QUERY(1, N);
    if (N == 1) {
        ANSWER(all[0]);
    }
    auto first = QUERY(1, N - 1);
    vector<string> diff;
    set_difference(begin(all), end(all), begin(first), end(first), back_inserter(diff));

    assert(int(diff.size()) == N);
    sort(begin(diff), end(diff),
         [&](const string& a, const string& b) { return a.size() < b.size(); });

    string answer(N, '0');
    answer[N - 1] = diff[0][0];
    for (int i = 1; i < N; i++) {
        string s;
        set_difference(begin(diff[i]), end(diff[i]), begin(diff[i - 1]), end(diff[i - 1]),
                       back_inserter(s));
        answer[N - i - 1] = s[0];
    }
    ANSWER(answer);

    return 0;
}