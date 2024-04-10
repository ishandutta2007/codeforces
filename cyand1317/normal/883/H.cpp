#include <cstdio>
#include <vector>
static const int MAXN = 4e5 + 4;
static const int AB_SZ = 62;
static const char alphabet[AB_SZ + 1] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

static int n;
static int ct[AB_SZ] = { 0 };
std::vector<int> odds;
static char t[MAXN] = { 0 };

static inline int get_id(const char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    else if (c >= 'A' && c <= 'Z') return 10 + c - 'A';
    else if (c >= 'a' && c <= 'z') return 36 + c - 'a';
    else return -1;
}

inline bool check(int len)
{
    // What...
    if (len % 2 == 0) {
        return odds.empty();
    } else {
        return odds.size() <= n / len;
    }
}

int main()
{
    //for (int i = 0; i < AB_SZ; ++i) if (get_id(alphabet[i]) != i) puts("> <");
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i) ++ct[get_id(getchar())];
    for (int i = 0; i < AB_SZ; ++i) if (ct[i] & 1) odds.push_back(i);

    int ans = -1;
    for (int i = 1; i * i <= n; ++i) if (n % i == 0) {
        if (i * i <= n && check(n / i)) { ans = n / i; break; }
        if (check(i) && ans < i) ans = i;
    }

    // <ans> is the length
    printf("%d\n", n / ans);
    if (ans % 2 == 0) {
        int p = 0;
        for (int i = 0; i < n / ans; ++i) {
            for (int j = 0; j < ans / 2; ++j) {
                while (ct[p] == 0) ++p;
                t[j] = t[ans - 1 - j] = alphabet[p];
                ct[p] -= 2;
            }
            printf("%s%c", t, i == n / ans - 1 ? '\n' : ' ');
        }
    } else {
        int p = 0;
        for (int i = 0; i < n / ans; ++i) {
            for (int j = 0; j < ans / 2; ++j) {
                while (ct[p] <= 1) ++p;
                t[j] = t[ans - 1 - j] = alphabet[p];
                ct[p] -= 2;
            }
            if (i < odds.size()) {
                t[ans / 2] = alphabet[odds[i]];
                --ct[odds[i]];
            } else {
                if ((i - odds.size()) % 2 == 0) {
                    while (ct[p] == 0) ++p;
                    t[ans / 2] = alphabet[p];
                    --ct[p];
                } else {
                    // keep t[ans / 2] unchanged
                    --ct[get_id(t[ans / 2])];
                }
            }
            printf("%s%c", t, i == n / ans - 1 ? '\n' : ' ');
        }
    }

    return 0;
}