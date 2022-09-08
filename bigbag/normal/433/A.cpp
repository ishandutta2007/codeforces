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

int n, sum, a[3];

void write(string s) {
    cout << s << endl;
    exit(0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        ++a[x / 100];
        sum += x / 100;
    }
    if (sum % 2) {
        write("NO");
    }
    if (a[2] % 2 && a[1] == 0) {
        write("NO");
    }
    write("YES");
    return 0;
}