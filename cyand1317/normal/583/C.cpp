#include <cstdio>
#include <set>
static const int MAXN = 512;
int n;
std::multiset<int> g;

int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
    scanf("%d", &n);
    int x;
    for (int i = 0; i < n * n; ++i) {
        scanf("%d", &x);
        g.insert(x);
    }

    std::multiset<int>::iterator it;
    it = g.end(); --it; // g.rbegin()
    int a[MAXN] = { *it };
    g.erase(it);
    int top = 1;
    while (!g.empty()) {
        it = g.end(); --it;
        x = *it;
        g.erase(it);
        for (int i = 0; i < top; ++i) {
            g.erase(g.find(gcd(x, a[i])));
            g.erase(g.find(gcd(x, a[i])));
        }
        a[top++] = x;
    }

    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    putchar('\n');
    return 0;
}