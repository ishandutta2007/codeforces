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

long long n, k, p;

bool bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

string get_ans(int n, int k) {
    int mx = n * 2;
    string ans = "Z";
    for (int i = 0; i < (1 << n); ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += bit(i, j);
        }
        if (sum == k) {
            sum = 0;
            int last = 0, first = 0;
            string s = "";
            for (int j = 0; j < n; ++j) {
                if (bit(i, j)) {
                    s += 'X';
                    int poz = j + 1 - last;
                    sum += (poz + 1) / 2;
                    last = j + 1;
                    if (first == 0) {
                        first = j + 1;
                    }
                } else {
                    s += '.';
                }
            }
            sum += (n - last) / 2 + ((n - last) % 2) * ((first + n - last) % 2);
            if (sum < mx || sum == mx && s < ans) {
                mx = sum;
                ans = s;
            }
        }
    }
    return ans;
}

char ans(long long n, long long k, long long poz) {
    if (n % 2 == 0) {
        if (poz % 2 == 0) {
            poz /= 2;
            --poz;
            if (k >= n / 2 - poz) {
                return 'X';
            }
            return '.';
        } else {
            poz /= 2;
            --poz;
            if (k >= n - 1 - poz) {
                return 'X';
            }
            return '.';
        }
    }
    if (poz % 2 == 0) {
        poz /= 2;
        --poz;
        if (k >= n / 2 - poz + 1) {
            return 'X';
        }
        return '.';
    } else {
        if (poz == n) {
            if (k >= 1) {
                return 'X';
            }
            return '.';
        }
        poz /= 2;
        --poz;
        if (k >= n - 1 - poz) {
            return 'X';
        }
        return '.';
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> p;
    /*for (int n = 1; n <= 15; ++n) {
        for (int k = 0; k <= n; ++k) {
            cout << n << " " << k << "  - ";
            if (k < 10) cout << " ";
            cout << get_ans(n, k) << "   ";
            for (int q = 1; q <= n; ++q) {
                cout << ans(n, k, q);
            }
            cout << endl;
        }
    }*/
    while (p--) {
        long long poz;
        cin >> poz;
        cout << ans(n, k, poz);
    }
    cout << endl;
    return 0;
}