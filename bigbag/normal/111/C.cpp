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

const int max_n = 111, inf = 111111111;

int n, m, a[max_n], used[max_n], num[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    if (n > m) {
        swap(n, m);
    }
    if (n == 1) {
        if (n == 1 && m == 1) cout << 0 << endl;
        if (n == 1 && m == 2) cout << 1 << endl;
        if (n == 1 && m == 3) cout << 2 << endl;
        if (n == 1 && m == 4) cout << 2 << endl;
        if (n == 1 && m == 5) cout << 3 << endl;
        if (n == 1 && m == 6) cout << 4 << endl;
        if (n == 1 && m == 7) cout << 4 << endl;
        if (n == 1 && m == 8) cout << 5 << endl;
        if (n == 1 && m == 9) cout << 6 << endl;
        if (n == 1 && m == 10) cout << 6 << endl;
        if (n == 1 && m == 11) cout << 7 << endl;
        if (n == 1 && m == 12) cout << 8 << endl;
        if (n == 1 && m == 13) cout << 8 << endl;
        if (n == 1 && m == 14) cout << 9 << endl;
        if (n == 1 && m == 15) cout << 10 << endl;
        if (n == 1 && m == 16) cout << 10 << endl;
        if (n == 1 && m == 17) cout << 11 << endl;
        if (n == 1 && m == 18) cout << 12 << endl;
        if (n == 1 && m == 19) cout << 12 << endl;
        if (n == 1 && m == 20) cout << 13 << endl;
        if (n == 1 && m == 21) cout << 14 << endl;
        if (n == 1 && m == 22) cout << 14 << endl;
        if (n == 1 && m == 23) cout << 15 << endl;
        if (n == 1 && m == 24) cout << 16 << endl;
        if (n == 1 && m == 25) cout << 16 << endl;
        if (n == 1 && m == 26) cout << 17 << endl;
        if (n == 1 && m == 27) cout << 18 << endl;
        if (n == 1 && m == 28) cout << 18 << endl;
        if (n == 1 && m == 29) cout << 19 << endl;
        if (n == 1 && m == 30) cout << 20 << endl;
        if (n == 1 && m == 31) cout << 20 << endl;
        if (n == 1 && m == 32) cout << 21 << endl;
        if (n == 1 && m == 33) cout << 22 << endl;
        if (n == 1 && m == 34) cout << 22 << endl;
        if (n == 1 && m == 35) cout << 23 << endl;
        if (n == 1 && m == 36) cout << 24 << endl;
        if (n == 1 && m == 37) cout << 24 << endl;
        if (n == 1 && m == 38) cout << 25 << endl;
        if (n == 1 && m == 39) cout << 26 << endl;
        if (n == 1 && m == 40) cout << 26 << endl;
        return 0;
    }
    if (n == 2 && m == 2) cout << 2 << endl;
    if (n == 2 && m == 3) cout << 4 << endl;
    if (n == 3 && m == 2) cout << 4 << endl;
    if (n == 2 && m == 4) cout << 5 << endl;
    if (n == 4 && m == 2) cout << 5 << endl;
    if (n == 2 && m == 5) cout << 7 << endl;
    if (n == 5 && m == 2) cout << 7 << endl;
    if (n == 2 && m == 6) cout << 8 << endl;
    if (n == 6 && m == 2) cout << 8 << endl;
    if (n == 2 && m == 7) cout << 10 << endl;
    if (n == 7 && m == 2) cout << 10 << endl;
    if (n == 2 && m == 8) cout << 11 << endl;
    if (n == 8 && m == 2) cout << 11 << endl;
    if (n == 2 && m == 9) cout << 13 << endl;
    if (n == 9 && m == 2) cout << 13 << endl;
    if (n == 2 && m == 10) cout << 14 << endl;
    if (n == 10 && m == 2) cout << 14 << endl;
    if (n == 2 && m == 11) cout << 16 << endl;
    if (n == 11 && m == 2) cout << 16 << endl;
    if (n == 2 && m == 12) cout << 17 << endl;
    if (n == 12 && m == 2) cout << 17 << endl;
    if (n == 2 && m == 13) cout << 19 << endl;
    if (n == 13 && m == 2) cout << 19 << endl;
    if (n == 2 && m == 14) cout << 20 << endl;
    if (n == 14 && m == 2) cout << 20 << endl;
    if (n == 2 && m == 15) cout << 22 << endl;
    if (n == 15 && m == 2) cout << 22 << endl;
    if (n == 2 && m == 16) cout << 23 << endl;
    if (n == 16 && m == 2) cout << 23 << endl;
    if (n == 2 && m == 17) cout << 25 << endl;
    if (n == 17 && m == 2) cout << 25 << endl;
    if (n == 2 && m == 18) cout << 26 << endl;
    if (n == 18 && m == 2) cout << 26 << endl;
    if (n == 2 && m == 19) cout << 28 << endl;
    if (n == 19 && m == 2) cout << 28 << endl;
    if (n == 2 && m == 20) cout << 29 << endl;
    if (n == 20 && m == 2) cout << 29 << endl;
    if (n == 3 && m == 3) cout << 6 << endl;
    if (n == 3 && m == 4) cout << 8 << endl;
    if (n == 4 && m == 3) cout << 8 << endl;
    if (n == 3 && m == 5) cout << 11 << endl;
    if (n == 5 && m == 3) cout << 11 << endl;
    if (n == 3 && m == 6) cout << 13 << endl;
    if (n == 6 && m == 3) cout << 13 << endl;
    if (n == 3 && m == 7) cout << 15 << endl;
    if (n == 7 && m == 3) cout << 15 << endl;
    if (n == 3 && m == 8) cout << 17 << endl;
    if (n == 8 && m == 3) cout << 17 << endl;
    if (n == 3 && m == 9) cout << 20 << endl;
    if (n == 9 && m == 3) cout << 20 << endl;
    if (n == 3 && m == 10) cout << 22 << endl;
    if (n == 10 && m == 3) cout << 22 << endl;
    if (n == 3 && m == 11) cout << 24 << endl;
    if (n == 11 && m == 3) cout << 24 << endl;
    if (n == 3 && m == 12) cout << 26 << endl;
    if (n == 12 && m == 3) cout << 26 << endl;
    if (n == 3 && m == 13) cout << 29 << endl;
    if (n == 13 && m == 3) cout << 29 << endl;
    if (n == 4 && m == 4) cout << 12 << endl;
    if (n == 4 && m == 5) cout << 14 << endl;
    if (n == 5 && m == 4) cout << 14 << endl;
    if (n == 4 && m == 6) cout << 17 << endl;
    if (n == 6 && m == 4) cout << 17 << endl;
    if (n == 4 && m == 7) cout << 21 << endl;
    if (n == 7 && m == 4) cout << 21 << endl;
    if (n == 4 && m == 8) cout << 24 << endl;
    if (n == 8 && m == 4) cout << 24 << endl;
    if (n == 4 && m == 9) cout << 26 << endl;
    if (n == 9 && m == 4) cout << 26 << endl;
    if (n == 4 && m == 10) cout << 30 << endl;
    if (n == 10 && m == 4) cout << 30 << endl;
    if (n == 5 && m == 5) cout << 18 << endl;
    if (n == 5 && m == 6) cout << 22 << endl;
    if (n == 6 && m == 5) cout << 22 << endl;
    if (n == 5 && m == 7) cout << 26 << endl;
    if (n == 7 && m == 5) cout << 26 << endl;
    if (n == 5 && m == 8) cout << 29 << endl;
    if (n == 8 && m == 5) cout << 29 << endl;
    if (n == 6 && m == 6) cout << 26 << endl;
    return 0;
}