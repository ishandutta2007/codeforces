#include <cstdio>
#include <vector>
typedef long long int64;
static const int PERMS = 28;
static const int DIGITS = 19;

int p[PERMS][7];
std::vector<int> bucket[10];
int64 pow10[DIGITS];

inline int next(int i) { return i == 0 ? 4 : (i == 4 ? 7 : 8); }

int64 a[6];
bool search(int64 n, int dig = 0) {
    if (n == 0) return true;
    if (dig >= DIGITS) return false;
    for (std::vector<int>::iterator i = bucket[(n / pow10[dig]) % 10].begin();
        i != bucket[(n / pow10[dig]) % 10].end(); ++i)
    {
        if (n - p[*i][6] * pow10[dig] < 0) continue;
        for (int j = 0; j < 6; ++j) a[j] += p[*i][j] * pow10[dig];
        if (search(n - p[*i][6] * pow10[dig], dig + 1)) return true;
        for (int j = 0; j < 6; ++j) a[j] -= p[*i][j] * pow10[dig];
    }
    return false;
}

int main()
{
    int p_id = 0;
    for (int i = 0; i <= 7; i = next(i))
        for (int j = i; j <= 7; j = next(j))
            for (int k = j; k <= 7; k = next(k))
                for (int l = k; l <= 7; l = next(l))
                    for (int m = l; m <= 7; m = next(m))
                        for (int n = m; n <= 7; n = next(n)) {
                            p[p_id][0] = i; p[p_id][1] = j; p[p_id][2] = k;
                            p[p_id][3] = l; p[p_id][4] = m; p[p_id][5] = n;
                            p[p_id][6] = i + j + k + l + m + n;
                            bucket[(i + j + k + l + m + n) % 10].push_back(p_id);
                            ++p_id;
                        }
    pow10[0] = 1;
    for (int i = 1; i < DIGITS; ++i) pow10[i] = pow10[i - 1] * 10;

    int t;
    int64 n;
    scanf("%d", &t);
    do {
        scanf("%I64d", &n);
        for (int i = 0; i < 6; ++i) a[i] = 0;
        if (search(n))
            for (int i = 0; i < 6; ++i) printf("%I64d%c", a[i], i == 5 ? '\n' : ' ');
        else puts("-1");
    } while (--t);

    return 0;
}