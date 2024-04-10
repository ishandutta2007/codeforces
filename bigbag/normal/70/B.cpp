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

int n;
string s;
vector<int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int cnt = 0, max_len = -1, len = 0;
    while (1 || !feof(stdin)) {
        s = "";
        cin >> s;
        if (s == "") break;
        ++cnt;
        len += s.length();
        if (s[s.length() - 1] == '.' || s[s.length() - 1] == '?' || s[s.length() - 1] == '!') {
            len += cnt - 1;
            max_len = max(max_len, len);
            v.push_back(len);
            cnt = 0;
            len = 0;
        }
    }
    if (max_len > n) {
        cout << "Impossible" << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < v.size(); ) {
        int sum = -1;
        while (i < v.size() && sum + v[i] + 1 <= n) {
            sum += v[i] + 1;
            ++i;
        }
        ++ans;
    }
    cout << ans << endl;
    return 0;
}