#include <cstdio>
typedef long long int64;
static const int MAXN = 102;

int b, d;
int slen, tlen;
char s[MAXN], t[MAXN];

namespace matrix {

static const int SZ = ::MAXN;
typedef int mat[SZ][SZ];
mat identity = {{ 0 }};

inline void get_identity() {
    if (identity[0][0] == 0) {
        for (int i = 0; i < SZ; ++i) identity[i][i] = 1;
    }
}

template <typename S, typename T> inline void assign(S a[][SZ], T c[][SZ]) {
    for (int i = 0; i < SZ; ++i)
        for (int j = 0; j < SZ; ++j) a[i][j] = c[i][j];
}

inline void mul(mat a, mat b) {
    static int64 c[SZ][SZ];
    for (int i = 0; i < SZ; ++i)
        for (int j = 0; j < SZ; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < SZ; ++k) c[i][j] += (int64)a[i][k] * b[k][j];
        }
    assign(a, c);
}

inline void pow(mat a, int exp) {
    static mat ans;
    get_identity();
    assign(ans, identity);
    for (; exp; exp >>= 1) {
        if (exp & 1) mul(ans, a);
        mul(a, a);
    }
    assign(a, ans);
}

}

int main()
{
    scanf("%d%d", &b, &d); getchar();
    for (slen = 0; (s[slen] = getchar()) != '\n'; ++slen) ;
    for (tlen = 0; (t[tlen] = getchar()) != '\n'; ++tlen) ;

    int t_repeats = slen / tlen + 1;
    matrix::mat state = {{ 0 }}, transition = {{ 0 }};

    // State
    state[0][0] = 1;
    for (int i = 1; i <= tlen; ++i) state[0][i] = 0;
    // Transition
    int answer_location = tlen;
    for (int i = 0; i <= tlen; ++i)
        for (int j = 0; j <= tlen; ++j) transition[i][j] = 0;
    for (int i = 0; i < tlen; ++i) {
        int u = i;
        for (int i = 0; i < slen; ++i) if (s[i] == t[u % tlen]) ++u;
        transition[i][u % tlen] = 1;
        transition[i][answer_location] = u / tlen;
    }
    transition[answer_location][answer_location] = 1;
    // Apply
    matrix::pow(transition, b);
    matrix::mul(state, transition);
    printf("%d\n", state[0][answer_location] / d);

    return 0;
}