#include <cstdio>
#include <cstring>
#include <cmath>

#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_int = (1LL << 31) - 1;

//#define LOCAL

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

const int modulo = 1e9 + 7;

struct matr {
    int a[2][2];
};

typedef matr* pmatr;

pmatr mult(pmatr a, pmatr b) {
    pmatr res = new matr();
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j) {
            res->a[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                res->a[i][j] = (1LL * a->a[i][k] * b->a[k][j] + res->a[i][j]) % modulo;
            }
        }
    return res;
}

pmatr e_matr() {
    pmatr res = new matr();
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            if (i == j)
                res->a[i][j] = 1;
            else
                res->a[i][j] = 0;
    return res;
}

pmatr matr_pow(pmatr base, ll p) {
    if (p == 0)
        return e_matr();
    if (p % 2 == 0)
        return matr_pow(mult(base, base), p / 2);
    if (p % 2 == 1)
        return mult(base, matr_pow(base, p - 1));
}

int main() {
    ios_base::sync_with_stdio(false); 
    pmatr res = new matr();
    res->a[0][0] = 3; res->a[0][1] = 1;
    res->a[1][0] = 1; res->a[1][1] = 3;
    ll p;
    cin >> p;
    res = matr_pow(res, p);
    cout << res->a[0][0] << endl;
    return 0;
}