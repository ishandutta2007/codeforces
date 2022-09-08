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

const int max_n = 22, inf = 1111111111;

int n;
string s, ans;
set<char> q;
vector<string> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (!q.count(s[i])) {
            q.insert(s[i]);
            if (i) {
                v.push_back(ans);
            }
            ans = "";
        }
        ans += s[i];
    }
    v.push_back(ans);
    if (v.size() < n) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < n) {
            cout << endl;
        }
    }
    return 0;
}