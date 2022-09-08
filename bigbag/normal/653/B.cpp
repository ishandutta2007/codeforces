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

const int max_n = 55, inf = 1111111111;

int len, n;
char a[max_n];
string b[max_n];
set<string> ss;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> len >> n;
    for (int i = 0; i < n; ++i) {
        cin >> b[i] >> a[i];
    }
    queue<string> q;
    q.push("a");
    ss.insert("a");
    int ans = 0;
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        if (s.length() == len) {
            ++ans;
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == s[0]) {
                string to = "";
                to += b[i];
                if (s.length() > 1) {
                    to += s.substr(1);
                }
                if (!ss.count(to)) {
                    ss.insert(to);
                    q.push(to);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}