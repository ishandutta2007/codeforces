#include <bits/stdc++.h>

using namespace std;

const int max_n = 500555, inf = 1000111222;

int n;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%s", s);
    n = strlen(s);
    char mn = 'z';
    for (int i = 0; i < n; ++i) {
        mn = min(mn, s[i]);
        if (s[i] == mn) {
            puts("Mike");
        } else {
            puts("Ann");
        }
    }
    return 0;
}