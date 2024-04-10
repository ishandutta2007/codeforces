/**
 *  created: 01/04/2021, 18:29:03
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int x;

double st = clock();

double get_time() {
    return (clock() - st) / CLOCKS_PER_SEC;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x;
    /*if (x == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (x == 0) {
        cout << 2 << endl;
        return 0;
    }
    if (x == 2) {
        cout << -2 << endl;
        return 0;
    }
    if (x == -1) {
        cout << 1 << endl;
        return 0;
    }
    if (x == -100) {
        cout << -99 << endl;
        return 0;
        //while (1);
    }
    if (x != 1 && x != 0) {
        while (get_time() <= 0.003 * (100 + x)) {
        }
    }*/
    cout << 2 - x * x << endl;
    return 0;
}