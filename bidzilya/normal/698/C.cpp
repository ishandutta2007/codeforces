#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#include <cstring>
#include <cmath>
using namespace std;

const double EPS = 1e-9;

inline int GetBit(int mask, int num) {
    return (mask >> num) & 1;
}

#ifdef LOCAL
#define LLD_SPEC "%lld"
#else
#define LLD_SPEC "%I64d"
#endif

const int MAX_N = 20;
const int MAX_B = 20;
const int MAX_MASK = (1 << MAX_B);

int n, k;
double p[MAX_N];

int bitCount[MAX_MASK];

double pMask[MAX_MASK];

double coeffs[MAX_MASK][MAX_B + 1];

void BuildCoeffs() {
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (bitCount[mask] < k) {
            coeffs[mask][0] = pMask[mask];
        }
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int b = 0; b < n; ++b) {
            coeffs[mask][b + 1] = coeffs[mask][b];
            if (GetBit(mask, b)) {
                coeffs[mask][b + 1] -= coeffs[mask - (1 << b)][b + 1];
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &p[i]);
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        bitCount[mask] = 0;
        for (int i = 0; i < n; ++i) {
            if (GetBit(mask, i)) {
                bitCount[mask] = 1 + bitCount[mask - (1 << i)];
                break;
            }
        }
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        pMask[mask] = 0.0;
        for (int i = 0; i < n; ++i) {
            if (GetBit(mask, i)) {
                pMask[mask] += p[i];
            }
        }
        if (!(fabs(pMask[mask] - 1.0) < EPS)) {
            pMask[mask] = 1.0 / (1.0 - pMask[mask]);
        }
    }

    BuildCoeffs();

    for (int i = 0; i < n; ++i) {
        if (fabs(p[i]) < EPS) {
            printf("%.15lf ", 0.0);
            continue;
        }

        double result = 0.0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (bitCount[mask] < k && !GetBit(mask, i)) {
                result += coeffs[mask][n];
            }
        }

        result *= p[i];

        printf("%.15lf ", result);
    }
    printf("\n");

    return 0;
}