#include <cstdio>
#include <vector>
static const int MAXN = 100005;

int n;
int a[MAXN], p[MAXN];
std::vector<int> placed[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]); --a[i]; p[a[i]] = i;
    }

    int max = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (p[i] > max) max = p[i];
        placed[max].push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        bool first = true;
        for (std::vector<int>::iterator j = placed[i].begin(); j != placed[i].end(); ++j) {
            if (!first) putchar(' '); else first = false;
            printf("%d", *j + 1);
        }
        putchar('\n');
    }
    return 0;
}