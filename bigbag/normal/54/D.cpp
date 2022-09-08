#include <map>
#include <set>
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

const int max_n = 111, inf = 111;

int n, k, used[max_n];
string p, f, ans;

bool good(string q) {
    for (int i = 0; i < f.length(); ++i) {
        if (f[i] == '0' && q.substr(i, p.length()) == p) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> p >> f;
    for (int i = 0; i < n; ++i) {
        ans += "!";
    }
    for (int i = 0; i < f.length(); ++i) {
        if (f[i] == '1') {
            for (int j = i; j < i + p.length(); ++j) {
                ans[j] = p[j - i];
            }
        }
    }
    for (int i = 0; i < f.length(); ++i) {
        if (f[i] == '1') {
            if (ans.substr(i, p.length()) != p) {
                cout << "No solution" << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < p.length(); ++i) {
        used[p[i] - 'a'] = 1;
    }
    for (int i = 0; i < k; ++i) {
        if (used[i] == 0) {
            for (int j = 0; j < ans.length(); ++j) {
                if (ans[j] == '!') {
                    ans[j] = i + 'a';
                }
            }
            if (good(ans)) {
                cout << ans << endl;
                return 0;
            }
        }
    }
    /*for (int bred = 0; bred < inf; ++bred) {
        string q = ans;
        for (int i = 0; i < q.length(); ++i) {
            if (q[i] == '!') {
                q[i] = rand() % k + 'a';
            }
        }
        if (good(q)) {
            cout << q << endl;
            return 0;
        }
    }*/
    string q = ans;
    for (int i = 0; i < q.length(); ++i) {
        if (q[i] == '!') {
            q[i] = (p[0] + 1) % k + 'a';
        }
    }
    if (good(q)) {
        cout << q << endl;
        return 0;
    }
    cout << "No solution" << endl;
    return 0;
}