#include <cstdio>

#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
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

int n, m;
string b[30];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    int p = 0;
    for (int i1 = 0; i1 < n; ++i1)
        for (int j1 = 0; j1 < m; ++j1)
            for (int i2 = i1; i2 < n; ++i2)
                for (int j2 = j1; j2 < m; ++j2) {
                    bool may = true;
                    for (int i = i1; i <= i2; ++i)
                        for (int j = j1; j <= j2; ++j)
                            if (b[i][j] == '1') {
                                may = false;
                                break;
                            }
                    if (may) {
                        p = max(p, 2 * (i2 - i1 + 1) + 2 * (j2 - j1 + 1));
                    }
                }
    cout << p << endl;
    
    return 0;
}