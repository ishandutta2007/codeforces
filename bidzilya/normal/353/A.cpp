#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

int n;
int s1, s2;
int b[2][2];

int main() {
    cin >> n;
    s1 = s2 = b[0][1] = b[1][0] = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        s1 += x;
        s2 += y;
        ++b[x % 2][y % 2];
    }
    if ((s1 % 2) + (s2 % 2) == 0) {
        cout << 0 << endl;
    } else if ((s1 % 2) + (s2 % 2) == 2 && b[0][1] + b[1][0] > 0) {
        cout << 1 << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}