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

const int d[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int ans, x;
string s1, s2, s3;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s1 >> s2 >> s3;
    x = atoi(s1.c_str());
    if (s3 == "week") {
        --x;
        int y = 4;
        for (int i = 0; i < 366; ++i) {
            if (x == y) {
                ++ans;
            }
            ++y;
            y %= 7;
        }
    } else {
        for (int i = 0; i < 12; ++i) {
            if (x <= d[i]) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}