#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

// Longest prefix of a matching suffix of b
auto compute_prefix(const string& a, const string& b) {
    int A = a.size(), B = b.size(), N = A + B + 1;
    string s = a + '$' + b;

    vector<int> z(N);
    for (int i = 1, l = 0, r = 0; i < N; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < N && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r + 1)
            l = i, r = i + z[i] - 1;
    }
    for (int i = A + 1; i < N; i++) {
        if (z[i] == N - i) {
            return N - i;
        }
    }
    return 0;
}

auto solve() {
    int N, S = 0;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i], S += words[i].size();
    }
    string text = move(words[0]);
    text.reserve(S);

    for (int i = 1; i < N; i++) {
        string w = move(words[i]);
        int len;
        if (text.size() > w.size()) {
            string t = text.substr(text.size() - w.size());
            len = compute_prefix(w, t);
        } else {
            len = compute_prefix(w, text);
        }
        text.insert(end(text), begin(w) + len, end(w));
    }
    return text;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}