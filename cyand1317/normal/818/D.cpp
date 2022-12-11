#include <cstdio>
#include <set>
static const int MAXN = 1e5 + 4;
static const int MAXC = 1e6 + 1;

int n, a, c[MAXN];

bool valid[MAXC];
int count[MAXC] = { 0 };
std::set<int> s[MAXN];

int main()
{
    scanf("%d%d", &n, &a);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);

    for (int i = 1; i < MAXC; ++i) valid[i] = (i != a);
    for (int i = 1; i < MAXC; ++i) if (i != a) s[0].insert(i);
    for (int i = 0; i < n; ++i) {
        if (c[i] == a) {
            for (std::set<int>::iterator j = s[count[c[i]]].begin(); j != s[count[c[i]]].end(); ++j)
                valid[*j] = false;
            s[count[c[i]]].clear();
        } else if (valid[c[i]]) {
            s[count[c[i]]].erase(c[i]);
            s[count[c[i]] + 1].insert(c[i]);
        }
        ++count[c[i]];
    }

    for (int i = 1; i < MAXC; ++i) if (valid[i]) { printf("%d\n", i); return 0; }
    puts("-1"); return 0;
}