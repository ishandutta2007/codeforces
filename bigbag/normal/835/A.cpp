#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1, inf = 1011111111;

int s, v1, v2, t1, t2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int a = s * v1 + 2 * t1;
    int b = s * v2 + 2 * t2;
    if (a < b) {
        cout << "First" << endl;
    } else if (a > b) {
        cout << "Second" << endl;
    } else {
        cout << "Friendship" << endl;
    }
    return 0;
}