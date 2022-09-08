#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        n = strlen(s);
        vector<char> v;
        for (int i = 0; i < n; ++i) {
            v.push_back(s[i]);
            if (v.size() >= 2 && s[i] == 'B') {
                v.pop_back();
                v.pop_back();
            }
        }
        printf("%d\n", v.size());
    }
    return 0;
}