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

const int max_n = 1, inf = 1111111111;

int n, x, y, a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    while (n--) {
        cin >> x >> y;
        a += (x > y);
        b += (x < y);
    }
    if (a > b) {
        cout << "Mishka" << endl;
    } else if (a < b) {
        cout << "Chris" << endl;
    } else {
        cout << "Friendship is magic!^^" << endl;
    }
    return 0;
}