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

int n, ans;
map<string, int> q;

void norm(string &s) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 'a') {
            s[i] = s[i] - 'a' + 'A';
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    while (n--) {
        string a, b, c;
        cin >> a >> b >> c;
        norm(a);
        norm(c);
        q[a] = q[c] + 1;
        ans = max(ans, q[a]);
    }
    printf("%d\n", ans + 1);
    return 0;
}