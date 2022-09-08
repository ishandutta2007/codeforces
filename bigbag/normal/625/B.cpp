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

int ans;
string a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    for (int i = 0; i + b.length() <= a.length(); ++i) {
        if (a.substr(i, b.length()) == b) {
            ++ans;
            a[i + b.length() - 1] = '#';
        }
    }
    cout << ans << endl;
    return 0;
}