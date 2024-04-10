#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200010;
const int INF = 1000000000;



int main() {
    ios_base::sync_with_stdio(false);
    int N, C, D;
    cin >> N;
    int L = -INF, R = INF;
    for (int i = 0; i < N; ++i) {
        cin >> C >> D;
        if ((D == 1 && R < 1900) || (D == 2 && L >= 1900)) {
            cout << "Impossible" << endl;
            return 0;
        }
        if (D == 1) L = max(L, 1900) + C, R += C;
        if (D == 2) R = min(R, 1899) + C, L += C;
    }
    if (R > INF / 2) {
        cout << "Infinity" << endl;
    } else {
        cout << R << endl;
    } 
    return 0;
}