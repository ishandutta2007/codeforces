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
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    int x = n;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '0') {
            x = i + 1;
            break;
        }
    }
    cout << x << endl;
    return 0;
}