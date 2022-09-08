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

string s;
vector<int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        v.push_back(s[i] - '0');
    }
    int ans = 0;
    while (true) {
        if (v.back() == 0) {
            ++ans;
            v.pop_back();
        } else {
            if (v.size() == 1) {
                cout << ans << endl;
                return 0;
            }
            ++ans;
            int k = v.size();
            while (v.size() > 0 && v.back() == 1) {
                v.pop_back();
            }
            if (v.size() == 0) {
                cout << ans + k << endl;
                return 0;
            }
            v[v.size() - 1] = 1;
            ans += k - v.size();
        }
    }
    return 0;
}