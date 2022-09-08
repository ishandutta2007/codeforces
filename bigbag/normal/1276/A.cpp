#include <bits/stdc++.h>

using namespace std;

const int max_n = 2000222, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int t, used[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        string s = read();
        for (int i = 0; i < s.length(); ++i) {
            used[i] = 0;
        }
        for (int i = 0; i + 4 < s.length(); ++i) {
            if (s.substr(i, 5) == "twone") {
                used[i + 2] = 1;
            }
        }
        for (int i = 0; i + 2 < s.length(); ++i) {
            if (s.substr(i, 3) == "one" && !used[i]) {
                used[i + 1] = 1;
            }
        }
        for (int i = 0; i + 2 < s.length(); ++i) {
            if (s.substr(i, 3) == "two" && !used[i + 2]) {
                used[i + 1] = 1;
            }
        }
        vector<int> ans;
        for (int i = 0; i < s.length(); ++i) {
            if (used[i]) {
                ans.push_back(i);
            }
        }
        printf("%d\n", ans.size());
        for (int i : ans) {
            printf("%d ", i + 1);
        }
        puts("");
    }
    return 0;
}