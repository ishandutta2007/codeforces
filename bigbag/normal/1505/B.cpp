/**
 *  created: 01/04/2021, 17:52:22
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int a;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a;
    int x = a % 9;
    if (!x) {
        x = 9;
    }
    cout << x << endl;
    return 0;
}