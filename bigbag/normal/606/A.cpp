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

int a[3], b[3], c, poz;
vector<int> v;

void write(string s) {
    cout << s << endl;
    exit(0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 3; ++i) {
        cin >> b[i];
        if (a[i] < b[i]) {
            c += b[i] - a[i];
        } else {
            c -= (a[i] - b[i]) / 2;
        }
    }
    if (c <= 0) {
        write("Yes");
    }
    write("No");
    return 0;
}