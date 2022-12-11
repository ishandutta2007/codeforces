#include <cstdio>
#include <algorithm>
#include <vector>
static const int MAXN = 256;

static const char *nucleotides = "ACGT";
int n;
char s[MAXN];
int ct[4] = { 0, 0, 0, 0 };
std::vector<int> blanks;

int main()
{
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i) switch (s[i] = getchar()) {
        case 'A': ++ct[0]; break;
        case 'C': ++ct[1]; break;
        case 'G': ++ct[2]; break;
        case 'T': ++ct[3]; break;
        default: blanks.push_back(i); break;
    }

    int max = std::max(std::max(ct[0], ct[1]), std::max(ct[2], ct[3]));
    if (n % 4 != 0 || max * 4 > n) { puts("==="); return 0; }
    int p = 0;
    for (int i = 0; i < 4; ++i) {
        for (int q = 0; q < max - ct[i]; ++q) s[blanks[p + q]] = nucleotides[i];
        p += max - ct[i];
    }
    for (int q = 0; q < (int)blanks.size() - p; ++q) s[blanks[p + q]] = nucleotides[q % 4];

    puts(s);
    return 0;
}