#include <cstdio>
#include <set>
#include <utility>
#include <vector>
static const int MAXN = 100003;
static const int INF = 0x3fffffff;

int n, k;
int h[MAXN];
std::vector< std::pair<int, int> > ans;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &h[i]);
    h[n++] = INF;

    int p = 0, q = 0;
    int a = 0;
    std::multiset<int> s;
    while (q < n - 1) {
        while (q < n && (s.size() <= 1 || (*s.rbegin() - *s.begin() <= k)))
            s.insert(h[q++]);
        s.erase(s.find(h[--q]));
        if (a < q - p) {
            a = q - p;
            ans.clear();
            ans.push_back(std::make_pair(p, q));
        } else if (a == q - p) {
            ans.push_back(std::make_pair(p, q));
        }
        s.erase(s.find(h[p++]));
    }

    printf("%d %lu\n", a, ans.size());
    for (std::vector< std::pair<int, int> >::iterator i = ans.begin();
        i != ans.end(); ++i)
    {
        printf("%d %d\n", i->first + 1, i->second);
    }

    return 0;
}