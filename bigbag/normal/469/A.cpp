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

const int inf = 1111111111;

int n, p;
set<int> s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> p;
    while (p--) {
        int x;
        cin >> x;
        s.insert(x);
    }
    cin >> p;
    while (p--) {
        int x;
        cin >> x;
        s.insert(x);
    }
    if (s.size() == n) {
        cout << "I become the guy." << endl;
    } else {
        cout << "Oh, my keyboard!" << endl;
    }
    return 0;
}