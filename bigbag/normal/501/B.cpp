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

int q;
vector<string> v;
map<string, string> m, ans;
set<string> s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> q;
    while (q--) {
        string s1, s2;
        cin >> s1 >> s2;
        if (!s.count(s1)) {
            v.push_back(s1);
            s.insert(s2);
            m[s2] = s1;
            ans[s1] = s2;
        } else {
            s.erase(s1);
            s.insert(s2);
            ans[m[s1]] = s2;
            m[s2] = m[s1];
        }
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " " << ans[v[i]] << endl;
    }
    return 0;
}