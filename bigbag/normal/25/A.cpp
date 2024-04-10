#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
set <pair <int, int> > a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (x % 2 == 0) a.insert(make_pair(x, i));
        if (x % 2 == 1) b.insert(make_pair(x, i));
    }
    if (a.size() == 1) {
        pair <int, int> x = *a.begin();
        cout << x.second << endl;
    } else {
        pair <int, int> x = *b.begin();
        cout << x.second << endl;
    }
    return 0;
}