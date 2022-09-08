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
const int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string a, b;
string day[11];
map<string, int> num;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    day[0] = "monday";
    day[1] = "tuesday";
    day[2] = "wednesday";
    day[3] = "thursday";
    day[4] = "friday";
    day[5] = "saturday";
    day[6] = "sunday";
    for (int i = 0; i < 7; ++i) {
        num[day[i]] = i;
    }
    cin >> a >> b;
    int x = num[a], y = num[b];
    for (int i = 0; i < 11; ++i) {
        if ((x + d[i]) % 7 == y) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}