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

int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int i = 1, x = 1, sum = 1;
    while (sum <= n) {
        ++i;
        x += i;
        sum += x;
    }
    cout << i - 1 << endl;
    return 0;
}