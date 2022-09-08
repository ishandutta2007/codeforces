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

int n, x;

int main() {
    cin >> n;
    while (n--) {
        cin >> x;
        if (x == 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}