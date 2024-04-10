#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <time.h>
#include <sstream>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

vector<string> res;
int mask;

void go(const string& s, int pos, int dep, string r) {
    if (dep == 4) {
        if (pos == s.length())
            res.push_back(r.substr(1));
    } else {
        for (int l = 1; l <= 3 && pos + l <= s.length(); ++l) {
            if (l>1 && s[pos] == '0') continue;
            int x = 0;
            for (int i = 0; i < l; ++i)
                x = x * 10 + s[pos+i] - '0';
            if (x >= 256) continue;
            go(s, pos + l, dep + 1, r + "." + s.substr(pos, l));
        }
    }
}

void check(const char* s) {
    go(s, 0, 0, "");
}

void gen(string cur, int pos, const string& al) {
    if (pos == al.length()) {
        sort(cur.begin(), cur.end());
        do {
            string d = cur;
            reverse(d.begin(), d.end());
            check((cur + d).c_str());
            check((cur + d.substr(1)).c_str());
        } while (next_permutation(cur.begin(), cur.end())); 
    } else {
        for (int l = 0; cur.length() <= 6; l++) {
            gen(cur, pos + 1, al);
            cur += al[pos];
        }
    }
}

void solve() {
    int n;
    cin >> n;
    stringstream str;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mask |= (1<<x);
        str << x;
    }
    string al = str.str();
    if (al.length() <= 6) {
        gen(al, 0, al);
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i)
        puts(res[i].c_str());
}

int main() {
    solve();
    return 0;
}