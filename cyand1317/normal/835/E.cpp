#include <cstdio>
#include <cstdlib>
#include <vector>
static const int MAXN = 1002;

int n, x, y;

inline bool ask(const std::vector<int> &s)
{
    printf("? %lu", s.size());
    for (int u : s) printf(" %d", u + 1);
    putchar('\n'); fflush(stdout);
    int ans; scanf("%d", &ans);
    if (ans == -1) exit(0);
    else {
        int even = (s.size() & 1) ? x : 0;
        return (ans != even);
    }
}

inline void answer(int a, int b)
{
    if (a > b) { int t = a; a = b; b = t; }
    printf("! %d %d\n", a + 1, b + 1); fflush(stdout);
    exit(0);
}

int main()
{
    scanf("%d%d%d", &n, &x, &y);

    int oxo = 0;
    for (int i = 1, b = 0; i < n; i <<= 1, ++b) {
        std::vector<int> s;
        for (int j = 0; j < n; j += i * 2)
            for (int k = 0; k < i && j + k < n; ++k) s.push_back(j + k);
        oxo |= (i * ask(s));
    }

    int lbit = (oxo & -oxo);
    std::vector<int> s;
    for (int j = 0; j < n; j += lbit * 2)
        for (int k = 0; k < lbit && j + k < n; ++k) s.push_back(j + k);
    while (s.size() > 1) {
        int half = s.size() / 2;
        std::vector<int> t;
        for (int i = 0; i < half; ++i) t.push_back(s[i]);
        if (ask(t)) {
            s = t;
        } else {
            s.erase(s.begin(), s.begin() + half);
        }
    }

    answer(s.front(), s.front() ^ oxo);

    return 0;
}