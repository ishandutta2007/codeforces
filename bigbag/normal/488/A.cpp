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

int a;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a;
    for (int i = a + 1; ; ++i) {
        set<int> q;
        int k = abs(i);
        while (k) {
            q.insert(k % 10);
            k /= 10;
        }
        if (q.count(8)) {
            cout << i - a << endl;
            return 0;
        }
    }
    return 0;
}