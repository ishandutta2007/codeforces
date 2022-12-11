#include <cstdio>
#include <vector>
static const int MAXN = 100005;

int c[6], n;
int ty[MAXN], assign[MAXN];
std::vector<int> bucket[15];

static const char *type_str[] = { "S", "M", "L", "XL", "XXL", "XXXL" };
inline int get_type_uni(const char *s)
{
    switch (s[0]) {
        case 'S': return 0;
        case 'M': return 1;
        case 'L': return 2;
        case 'X':
            if (s[1] == 'L') return 3;
            else if (s[2] == 'L') return 4;
            else /*if (s[3] == 'L')*/ return 5;
        default: return -1;
    }
}
inline int get_type(const char *s)
{
    bool has_comma = false;
    for (const char *t = s; *t; ++t) if (*t == ',') { has_comma = true; break; }
    if (has_comma) {
        return get_type_uni(s) + 6;
    } else {
        return get_type_uni(s);
    }
}

int main()
{
    for (int i = 0; i < 6; ++i) scanf("%d", &c[i]);
    scanf("%d", &n);
    char s[24];
    for (int i = 0; i < n; ++i) { scanf("%s", s); ty[i] = get_type(s); bucket[ty[i]].push_back(i); }

    for (int i = 0; i < n; ++i) {
        if (ty[i] < 6) {
            if (--c[ty[i]] < 0) { puts("NO"); return 0; }
            assign[i] = ty[i];
        } else {
            assign[i] = -1;
        }
    }
    for (int i = 0; i < 6; ++i) {
        if (i != 0) for (std::vector<int>::iterator j = bucket[i + 5].begin(); j != bucket[i + 5].end(); ++j) {
            if (assign[*j] != -1) continue;
            if (--c[i] < 0) { puts("NO"); return 0; }
            assign[*j] = i;
        }
        for (std::vector<int>::iterator j = bucket[i + 6].begin(); j != bucket[i + 6].end() && c[i] > 0; ++j) {
            if (assign[*j] != -1) continue;
            --c[i];
            assign[*j] = i;
        }
    }

    puts("YES");
    for (int i = 0; i < n; ++i) puts(type_str[assign[i]]);

    return 0;
}