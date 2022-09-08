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

string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    int f = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (i == 0 && s[i] == '9') continue;
        if (s[i] >= '5') {
            s[i] = '9' - s[i] + '0';
        }
    }
    cout << s << endl;
    return 0;
}