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

string a, b;

void proc(string &a) {
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] <= 'Z') {
            a[i] = a[i] - 'A' + 'a';
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    proc(a);
    proc(b);
    if (a < b) {
        cout << -1 << endl;
    } else if (a > b) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}