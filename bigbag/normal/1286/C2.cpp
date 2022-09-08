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

string solve(int n) {
    vector<string> a = query(1, n);
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
    return ans;
}

char ans[max_n];
int tot[max_c], cur[max_c], lastc[max_c];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    if (n <= 2) {
        string ans;
        for (int i = 1; i <= n; ++i) {
            ans += query(i, i)[0];
        }
        answer(ans);
    }
    int len = (n + 1) / 2;
    string first = solve(len);
    vector<string> v = query(1, n);
    string last = "";
    for (int i = 0; i < first.length(); ++i) {
        ans[i] = first[i];
    }
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].length() == n) {
            for (char c : v[i]) {
                ++tot[c - 'a'];
                ++lastc[c - 'a'];
            }
            break;
        }
    }
    for (int i = 0; i + first.length() < n; ++i) {
        map<string, int> q;
        for (int j = 0; j < v.size(); ++j) {
            if (v[j].length() == n - i - 1) {
                ++q[v[j]];
            }
        }
        for (int j = 1; j <= i + 1; ++j) {
            for (int c = 0; c < max_c; ++c) {
                cur[c] = tot[c];
            }
            for (int k = 0; k < j; ++k) {
                --cur[ans[k] - 'a'];
            }
            for (int k = n - 1; k >= n - (i + 1 - j); --k) {
                --cur[ans[k] - 'a'];
            }
            string s;
            for (int c = 0; c < max_c; ++c) {
                for (int k = 0; k < cur[c]; ++k) {
                    s += c + 'a';
                }
            }
            --q[s];
        }
        for (auto p : q) {
            if (p.second == 1) {
                for (int c = 0; c < max_c; ++c) {
                    cur[c] = lastc[c];
                }
                //cout << "#" << p.first << endl;
                for (char c : p.first) {
                    --cur[c - 'a'];
                }
                for (int c = 0; c < max_c; ++c) {
                    if (cur[c]) {
                        ans[n - i - 1] = c + 'a';
                        --lastc[c];
                    }
                }
                break;
            }
        }
    }
    string s;
    for (int i = 0; i < n; ++i) {
        s += ans[i];
    }
    answer(s);
    return 0;
}