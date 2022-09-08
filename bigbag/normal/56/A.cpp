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

const string a[] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};

int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 11; ++j) {
            if (s == a[j]) {
                ++ans;
            }
        }
        if (s[0] >= '0' && s[0] <= '9') {
            if (s.length() == 1 || s.length() == 2 && s[0] == '1' && s[1] < '8') {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}