#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n;

vector<string> query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int cnt = (r - l + 1) * (r - l + 2) / 2;
    vector<string> v;
    for (int i = 0; i < cnt; ++i) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        v.push_back(s);
    }
    return v;
}

void answer(const string &s) {
    cout << "! " << s << endl;
    exit(0);
}

bool cmp(const string &a, const string &b) {
    return a.length() < b.length();
}

const int max_c = 26;

int cnt[2][max_c];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    vector<string> a = query(1, n);
    if (n == 1) {
        answer(a[0]);
    }
    vector<string> b = query(2, n);
    map<string, int> q;
    for (const string &s : a) {
        ++q[s];
    }
    for (const string &s : b) {
        --q[s];
    }
    vector<string> v;
    for (auto p : q) {
        if (p.second) {
            v.push_back(p.first);
        }
    }
    sort(v.begin(), v.end(), cmp);
    string ans;
    int q1 = 0, q2 = 1;
    for (const string &s : v) {
        memset(cnt[q2], 0, sizeof(cnt[q2]));
        for (char c : s) {
            ++cnt[q2][c - 'a'];
        }
        for (int i = 0; i < max_c; ++i) {
            if (cnt[q1][i] != cnt[q2][i]) {
                ans += 'a' + i;
                break;
            }
        }
        swap(q1, q2);
    }
    answer(ans);
    return 0;
}