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

const int max_n = 1, inf = 1011111111;

long long n, k;

int get(long long n) {
    set<int> q;
    for (int i = 1; ; ++i) {
        if (q.count(n % i)) {
            return i;
        }
        q.insert(n % i);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    if (k >= get(n)) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}