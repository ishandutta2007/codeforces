#include <cstdio>
#include <cstring>
static const int MODULUS = 1e9 + 7;
static const int INV_2 = MODULUS / 2 + 1;
#define _ % MODULUS;
typedef long long int64;
typedef int64 mat2[2][2];

inline void mat2_mul(mat2 a, mat2 b) {
    static int64 aa, bb, cc;
    aa = (a[0][0] * b[0][0] + a[0][1] * b[1][0])_;
    bb = (a[0][0] * b[0][1] + a[0][1] * b[1][1])_;
    cc = (a[1][0] * b[0][0] + a[1][1] * b[1][0])_;
    a[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1])_;
    a[1][0] = cc;
    a[0][1] = bb;
    a[0][0] = aa;
}

inline void mat2_fpow(mat2 base, int64 exp) {
    mat2 ans = {{1, 0}, {0, 1}};
    for (; exp; exp >>= 1) {
        if (exp & 1) mat2_mul(ans, base);
        mat2_mul(base, base);
    }
    memcpy(base, ans, sizeof(mat2));
}

int main()
{
    int n;
    int64 ai;
    scanf("%d", &n);

    mat2 m = {{-1 + MODULUS, 1}, {0, 2}};
    do {
        scanf("%I64d", &ai);
        mat2_fpow(m, ai);
    } while (--n);
    int64 num = ((m[0][0] + m[0][1]) * INV_2)_;
    int64 den = ((m[1][0] + m[1][1]) * INV_2)_;
    printf("%I64d/%I64d\n", num, den);

    return 0;
}