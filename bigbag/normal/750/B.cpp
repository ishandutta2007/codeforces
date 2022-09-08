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

const int max_n = 111, inf = 1011111111;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, x, y, len;
map<string, int> q;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    q["North"] = 0;
    q["South"] = 1;
    q["West"] = 2;
    q["East"] = 3;
    cin >> n;
    while (n--) {
        cin >> len >> s;
        int num = q[s];
        while (len--) {
            if (x == 0) {
                if (num != 1) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
            if (x == 20000) {
                if (num != 0) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
            x += dx[num];
            y += dy[num];
            x += 20001;
            x %= 20001;
            y += 20001;
            y %= 20001;
        }
    }
    //cout << x << " " << y << endl;
    if (x != 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}