#include <bits/stdc++.h>

using namespace std;

const int max_n = 100011, inf = 1000111222;

int n, cnt[222];
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i]];
    }
    while (cnt['o'] && cnt['n'] && cnt['e']) {
        printf("1 ");
        --cnt['o'];
        --cnt['n'];
        --cnt['e'];
    }
    while (cnt['z'] && cnt['e'] && cnt['r'] && cnt['o']) {
        printf("0 ");
        --cnt['z'];
        --cnt['e'];
        --cnt['r'];
        --cnt['o'];
    }
    return 0;
}