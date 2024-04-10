#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;

const int nn = 1 << 17;

struct edge {
    int to;
    string s;
};
vector<edge> g[nn];

int l;
string s;
vi kmp;
vi ckmp[26];

void KMP() {
    kmp = vi(s.length(), 0);
    for (int i = 2; i <= l; ++i) {
        int p = kmp[i-1];
        while (p > 0 && s[p+1] != s[i]) p = kmp[p];
        kmp[i] = p + (s[p+1] == s[i]);
    }

    for (char c = 'a'; c <= 'z'; ++c)
        ckmp[c - 'a'] = vi(s.length(), 0);

    for (char c = 'a'; c <= 'z'; ++c) {
        int r = c - 'a';
        for (int i = 0; i <= l; ++i) {
            if (c == s[i + 1])
                ckmp[r][i] = i + 1;
            else {
                ckmp[r][i] = ckmp[r][kmp[i]];
            }
        }
    }
}

int proc(int p, const string& s, int& ans) {
    for (int i = 0; i < s.length(); ++i) {
        p = ckmp[s[i] - 'a'][p];
        ans += p == l;
    }
    return p;
}

void go(int v, int p, int& ans) {
    for (int i = 0; i < g[v].size(); ++i) {
        int np = proc(p, g[v][i].s, ans);
        go(g[v][i].to, np, ans);
    }
}

int main() {
    int n;
    cin >> n;
    for (int v = 2; v <= n; ++v) {
        int p;
        edge e;
        e.to = v;
        cin >> p >> e.s;
        g[p].push_back(e);
    }
    cin >> s;
    l = s.length();
    s = " " + s + " ";
    KMP();
/*    
    for (int j = 1; j <= l; ++j)
        cout << kmp[j] << ' ';
    cout << endl << endl;
    
    for (int c = 0; c < 26; ++c) {
        for (int j = 0; j <= l; ++j)
            cout << ckmp[c][j] << ' ';
        cout << endl;
    }
    return 0;*/
    int ans = 0;
    go(1, 0, ans);
    cout << ans << endl;
    return 0;
}