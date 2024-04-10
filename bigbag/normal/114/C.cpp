#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

bool ok(string a, string b) {
    if (a.length() < b.length()) {
        return false;
    }
    return a.substr(a.length() - b.length(), b.length()) == b;
}

pair<int, int> get_t(string s) {
    if (ok(s, "lios")) {
        return make_pair(1, 1);
    }
    if (ok(s, "etr")) {
        return make_pair(1, 2);
    }
    if (ok(s, "initis")) {
        return make_pair(1, 3);
    }
    if (ok(s, "liala")) {
        return make_pair(2, 1);
    }
    if (ok(s, "etra")) {
        return make_pair(2, 2);
    }
    if (ok(s, "inites")) {
        return make_pair(2, 3);
    }
    cout << "NO" << endl;
    exit(0);

}

int l[11], r[11], b[11], cnt;
string s;
set<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    l[1] = l[2] = l[3] = 1e9;
    r[1] = r[2] = r[3] = -1;
    while (cin >> s) {
        pair<int, int> p = get_t(s);
        q.insert(p.first);
        l[p.second] = min(l[p.second], cnt);
        r[p.second] = max(r[p.second], cnt);
        ++b[p.second];
        ++cnt;
    }
    if (cnt == 1) {
        cout << "YES" << endl;
        return 0;
    }
    if (q.size() > 1) {
        cout << "NO" << endl;
        return 0;
    }
    if (b[2] != 1) {
        cout << "NO" << endl;
        return 0;
    }
    if (r[1] < l[2] && l[2] < l[3]) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}