#include <cstdio>
static const int MAXN = 1e5 + 7;

int ns = 0, nt = 0;
int s[MAXN], t[MAXN];

inline bool valid(const char ch) { return ch == '4' || ch == '7'; }

int main()
{
    for (ns = 0; valid(s[ns] = getchar()); ++ns) ;
    for (nt = 0; valid(t[nt] = getchar()); ++nt) ;

    int c47 = 0, c74 = 0;
    for (int i = 0; i < ns; ++i) if (s[i] != t[i]) {
        if (s[i] == '4') ++c47; else ++c74;
    }

    printf("%d\n", c47 > c74 ? c47 : c74);
    return 0;
}