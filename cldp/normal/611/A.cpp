#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;


int X[7];
int Y[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    ios_base::sync_with_stdio(false);
    int T = 4;
    for (int i = 0; i < 366; ++i) {
        ++X[T];
        T = (T + 1) % 7;
    }
    int A;
    string P, Q;
    cin >> A >> P >> Q;
    if (Q == "week") cout << X[A - 1] << endl; else {
        int C = 0;
        for (int i = 0; i < 12; ++i) {
            if (A <= Y[i]) ++C;
        }
        cout << C << endl;
    }
    return 0;
}