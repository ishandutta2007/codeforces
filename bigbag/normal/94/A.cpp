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

string s, a[11];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    for (int i = 0; i < 10; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (s.substr(i * 10, 10) == a[j]) {
                cout << j;
                break;
            }
        }
    }
    cout << endl;
    return 0;
}