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

const int max_n = 555555, inf = 1111111111;

int n, m, poz, nxt[max_n], pr[max_n], used[max_n];
char s[max_n], c[max_n];

void write() {
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            printf("%c", s[i]);
        }
    }
    //printf("  poz = %d\n", poz);
    printf("\n", poz);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &poz);
    scanf("%s%s", s, c);
    --poz;
    for (int i = 0; i < n; ++i) {
        nxt[i] = i + 1;
        pr[i] = i - 1;
    }
    for (int i = 0; i < m; ++i) {
        if (c[i] == 'L') {
            poz = pr[poz];
        } else if (c[i] == 'R') {
            poz = nxt[poz];
        } else {
            if (s[poz] == '(') {
                int k = pr[poz];
                int bal = 0;
                while (true) {
                    if (s[poz] == '(') {
                        ++bal;
                    } else {
                        --bal;
                    }
                    used[poz] = 1;
                    poz = nxt[poz];
                    if (bal == 0) {
                        break;
                    }
                }
                if (k != -1) {
                    nxt[k] = poz;
                }
                pr[poz] = k;
                if (poz == n) {
                    poz = k;
                }
            } else {
                int k = nxt[poz];
                int bal = 0;
                while (true) {
                    if (s[poz] == ')') {
                        ++bal;
                    } else {
                        --bal;
                    }
                    used[poz] = 1;
                    poz = pr[poz];
                    if (bal == 0) {
                        break;
                    }
                }
                if (k != n) {
                    pr[k] = poz;
                }
                if (poz != -1) {
                    nxt[poz] = k;
                }
                if (k != n) {
                    poz = k;
                }
            }
        }
        //cout << i << " : ";
        //write();
    }
    write();
    return 0;
}