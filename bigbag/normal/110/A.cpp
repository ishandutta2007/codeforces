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

long long x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x;
    int cnt = 0;
    while (x) {
        cnt += (x % 10) == 4;
        cnt += (x % 10) == 7;
        x /= 10;
    }
    x = cnt;
    if (x == 0) {
        cout << "NO" << endl;
        return 0;
    }
    while (x) {
        if (x % 10 != 4 && x % 10 != 7) {
            cout << "NO" << endl;
            return 0;
        }
        x /= 10;
    }
    cout << "YES" << endl;
    return 0;
}