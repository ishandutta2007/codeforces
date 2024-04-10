#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%s", &n, s);
    sort(s, s + n);
    printf("%s", s);
    return 0;
}