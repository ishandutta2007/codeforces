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

const int max_n = 555, inf = 1000000000;

int n, a, b, q[max_n][max_n];

const int max_p = 1011;

int used[max_p];
vector<int> pw;

void get_all_primes() {
    for (int i = 2; i < max_p; ++i) {
        if (used[i] == 0) {
            pw.push_back(i);
            if (1LL * i * i < max_p) {
                for (int j = i * i; j < max_p; j += i) {
                    used[j] = 1;
                }
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            q[2 * i + j][i + 2 * j] = 1;
        }
    }
    scanf("%d", &n);
    get_all_primes();
    while (n--) {
        scanf("%d%d", &a, &b);
        int f = 1;
        for (int i = 0; i < pw.size(); ++i) {
            int c1 = 0, c2 = 0;
            while (a % pw[i] == 0) {
                ++c1;
                a /= pw[i];
            }
            while (b % pw[i] == 0) {
                ++c2;
                b /= pw[i];
            }
            if (q[c1][c2] == 0) {
                f = 0;
                break;
            }
        }
        //cout << "#" << a << " " << b << " " << f << ": ";
        if (f) {
            if (a > b) {
                swap(a, b);
            }
            if (1LL * a * a == b || (a == 1 && b == 1)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else {
            printf("No\n");
        }
    }
    return 0;
}