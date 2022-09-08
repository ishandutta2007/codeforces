#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111, inf = 1000111222;

string s;
vector<int> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    int a = 0, b = s.length() - 1;
    while (a < b) {
        while (a < b && s[a] == ')') {
            ++a;
        }
        while (a < b && s[b] == '(') {
            --b;
        }
        if (a < b) {
            ans.push_back(a);
            ans.push_back(b);
            ++a;
            --b;
        }
    }
    if (ans.empty()) {
        puts("0");
    } else {
        sort(ans.begin(), ans.end());
        printf("%d\n%d\n", 1, ans.size());
        for (int x : ans) {
            printf("%d ", x + 1);
        }
        puts("");
    }
    return 0;
}