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

const int max_n = 19, inf = 111111111;
const int dx[] = {4, 5, 5, 4};
const int dx2[] = {3, 4, 4, 3};
const int ls[] = {0, 3, 7, 12, 16};
const int rs[] = {2, 6, 11, 15, 18};

int dp[1 << max_n];
char c[max_n];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

bool is_in(int poz, int r) {
    return ls[r] <= poz && poz <= rs[r];
}

int game(int x) {
    //cout << x << endl;
    if (dp[x] != 0) {
        return dp[x];
    }
    for (int i = 0; i < 5; ++i) {
        for (int l = ls[i]; l <= rs[i]; ++l) {
            int k = x;
            for (int r = l; r <= rs[i]; ++r) {
                if (get_bit(x, r) == 0) {
                    break;
                }
                k = k ^ (1 << r);
                if (game(k) == 1) {
                    dp[x] = 2;
                    return 2;
                }
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = ls[i]; j <= rs[i]; ++j) {
            int k = x, poz = j;
            for (int lev = i; lev < 5/*?*/; ++lev) {
                if (!is_in(poz, lev)) {
                    break;
                }
                if (get_bit(x, poz) == 0) {
                    break;
                }
                k = k ^ (1 << poz);
                if (game(k) == 1) {
                    dp[x] = 2;
                    return 2;
                }
                poz += dx[lev];
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = ls[i]; j <= rs[i]; ++j) {
            int k = x, poz = j;
            for (int lev = i; lev < 5/*?*/; ++lev) {
                if (!is_in(poz, lev)) {
                    break;
                }
                if (get_bit(x, poz) == 0) {
                    break;
                }
                k = k ^ (1 << poz);
                if (game(k) == 1) {
                    dp[x] = 2;
                    return 2;
                }
                poz += dx2[lev];
            }
        }
    }
    dp[x] = 1;
    return 1;
}

int x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 19; ++i) {
        cin >> c[i];
        if (c[i] == 'O') {
            x += (1 << i);
        }
    }
    dp[0] = 1;
    if (game(x) == 1) {
        cout << "Lillebror" << endl;
    } else {
        cout << "Karlsson" << endl;
    }
    return 0;
}