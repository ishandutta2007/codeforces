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

int a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    for (int i = 0; ; ++i) {
        if (i % 2 == 0) {
            if (a == 0) {
                cout << "Second";
                break;
            }
            --a;
        } else {
            if (b == 0) {
                cout << "First";
                break;
            }
            --b;
        }
    }
    return 0;
}