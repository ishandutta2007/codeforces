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
    while (p--) {
        long long poz;
        cin >> poz;
        cout << ans(n, k, poz);
    }
    cout << endl;
    return 0;
}