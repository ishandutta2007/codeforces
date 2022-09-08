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

const int max_n = 5555, inf = 1111111111;

int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    if (n == 1) {
        cout << "1\n1\n";
        return 0;
    }
    if (n == 2) {
        cout << "1\n1\n";
        return 0;
    }
    if (n == 3) {
        cout << "2\n1 3\n";
        return 0;
    }
    if (n == 4) {
        cout << "4\n2 4 1 3\n";
        return 0;
    }
    cout << n << endl;
    int x = n - n / 2 + 1;
    for (int i = 1; i <= n / 2; ++i) {
        cout << i << " " << x << " ";
        ++x;
    }
    if (n % 2 == 1) {
        cout << n / 2 + 1 << endl;
    }
    return 0;
}