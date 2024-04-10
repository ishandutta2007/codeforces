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

int n, m;
char c;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    n *= m;
    while (n--) {
        cin >> c;
        if (c == 'C' || c == 'M' || c == 'Y') {
            cout << "#Color" << endl;
            return 0;
        }
    }
    cout << "#Black&White" << endl;
    return 0;
}