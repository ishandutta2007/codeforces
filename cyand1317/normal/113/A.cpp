// You have submitted exactly the same code before
#include <cstdio>
#include <cstring>
#include <utility>
static const int MAXN = 1e5 + 4;

enum word_type { ADJ = 0, NOUN, VERB, UNKNOWN };
typedef std::pair<enum word_type, bool> word;

int n;
char s[MAXN];
word w[MAXN];

inline word parse_word(const char *s)
{
    int len = strlen(s);
    if (len >= 4 && !strcmp(s + len - 4, "lios")) return std::make_pair(ADJ, true);
    if (len >= 5 && !strcmp(s + len - 5, "liala")) return std::make_pair(ADJ, false);
    if (len >= 3 && !strcmp(s + len - 3, "etr")) return std::make_pair(NOUN, true);
    if (len >= 4 && !strcmp(s + len - 4, "etra")) return std::make_pair(NOUN, false);
    if (len >= 6 && !strcmp(s + len - 6, "initis")) return std::make_pair(VERB, true);
    if (len >= 6 && !strcmp(s + len - 6, "inites")) return std::make_pair(VERB, false);
    return std::make_pair(UNKNOWN, false);
}

int main()
{
    while (scanf("%s", s) == 1) {
        if ((w[n++] = parse_word(s)).first == UNKNOWN) { puts("NO"); return 0; }
    }

    if (n == 1) puts("YES");
    else {
        bool noun_appeared = false;
        for (int i = 0; i < n; ++i) {
            if (w[i].second ^ w[0].second) { puts("NO"); return 0; }
            switch (w[i].first) {
                case ADJ: if (noun_appeared) { puts("NO"); return 0; } else break;
                case NOUN: if (noun_appeared) { puts("NO"); return 0; } else { noun_appeared = true; break; }
                case VERB: if (!noun_appeared) { puts("NO"); return 0; } else break;
                default: puts(" (`)  "); break;
            }
        }
        puts(noun_appeared ? "YES" : "NO");
    }

    return 0;
}