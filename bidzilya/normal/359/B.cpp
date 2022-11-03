#include <cstdio>
#include <cmath>

#include <queue>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

const int max_n = 2e5 + 100;

int a[max_n];
int n, k;

void build_answer() {
    for (int i = 0; i < 4 * k; i += 4) {
        a[i] = i + 1;
        a[i + 1] = i + 2;
        a[i + 2] = i + 4;
        a[i + 3] = i + 3;
    }
    for (int i = 4 * k; i < 2 * n; i += 2) {
        a[i] = i + 2;
        a[i + 1] = i + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    build_answer();
    for (int i = 0; i < 2 * n; ++i)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}