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
    while (n--) {
        string s;
        cin >> s;
        if (s.length() <= 10) {
            cout << s << endl;
        } else {
            cout << s[0] << s.length() - 2 << s[s.length() - 1] << endl;
        }
    }
    return 0;
}