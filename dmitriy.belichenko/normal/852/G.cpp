#include <bits/stdc++.h>

using namespace std;

void boost() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
}

string symbol[] = {"a", "b", "c", "d", "e", ""};

vector<string> split(string &s, char c) {
    string cur = "";
    vector<string> result;
    for (char cc: s) {
        if (cc == c) {
            result.push_back(cur);
            cur = "";
        } else {
            cur += cc;
        }
    }
    result.push_back(cur);
    return result;
}

map<string, int> words;
set<string> used;

void solveOne(vector<string> &cur) {
    used.clear();
    for (auto c: symbol) {
        if (words.find(cur[0] + c + cur[1]) != words.end()) {
            used.insert(cur[0] + c + cur[1]);
        }
    }
    int ans = 0;
    for (auto w: used) {
        ans += words[w];
    }
    cout << ans << '\n';
}

void solveTwo(vector<string> &cur) {
    used.clear();
    for (auto c1: symbol) {
        for (auto c2: symbol) {
            if (words.find(cur[0] + c1 + cur[1] + c2 + cur[2]) != words.end()) {
                used.insert(cur[0] + c1 + cur[1] + c2 + cur[2]);
            }
        }
    }
    int ans = 0;
    for (auto w: used) {
        ans += words[w];
    }
    cout << ans << '\n';
}

void solveThree(vector<string> &cur) {
    used.clear();
    for (auto c1: symbol) {
        for (auto c2: symbol) {
            for (auto c3: symbol) {
                if (words.find(cur[0] + c1 + cur[1] + c2 + cur[2] +c3 + cur[3]) != words.end()) {
                    used.insert(cur[0] + c1 + cur[1] + c2 + cur[2] + c3 + cur[3]);
                }
            }
        }
    }
    int ans = 0;
    for (auto w: used) {
        ans += words[w];
    }
    cout << ans << '\n';
}

int main() {
    boost();
    int n, m;
    cin >> n >> m;
    string tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        words[tmp] += 1;
    }
    vector<string> cur;
    for (int i = 0; i < m; ++i) {
        cin >> tmp;
        cur = split(tmp, '?');
        if (cur.size() == 1) {
            if (words.find(cur[0]) != words.end()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
        else if (cur.size() == 2) {
            solveOne(cur);
        } else if (cur.size() == 3) {
            solveTwo(cur);
        } else {
            solveThree(cur);
        }
    }
    return 0;
}