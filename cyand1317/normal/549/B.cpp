#include <cstdio>
#include <list>
static const int MAXN = 104;

int n;
bool c[MAXN][MAXN];
int a[MAXN];
bool slctd[MAXN] = { false };

int main()
{
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= n; ++j) c[i][j] = (getchar() == '1');
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    std::list<int> matters;
    for (int i = 0; i < n; ++i) matters.push_back(i);
    while (!matters.empty()) {
        bool has_zeroes = false;
        for (std::list<int>::iterator i = matters.begin(); i != matters.end(); ++i) if (a[*i] == 0) {
            slctd[*i] = true;
            for (int j = 0; j < n; ++j) if (c[*i][j]) --a[j];
            matters.erase(i);
            has_zeroes = true; break;
        }
        if (!has_zeroes) break;
    }

    int ct = 0;
    for (int i = 0; i < n; ++i) if (slctd[i]) ++ct;
    printf("%d\n", ct);
    for (int i = 0; i < n; ++i)
        if (slctd[i]) printf("%d%c", i + 1, --ct == 0 ? '\n' : ' ');

    return 0;
}