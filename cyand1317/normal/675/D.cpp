#include <cstdio>
#include <set>
#include <utility>
static const int MAXN = 100007;
typedef std::pair<int, char> node;
#define val  first
#define chl  second
static const int CHL_LEFT = 1;
static const int CHL_RIGHT = 2;

int n, ai;
std::set<node> l;

int main()
{
    scanf("%d", &n);
    scanf("%d", &ai);
    l.insert(node(ai, 0));

    for (int i = 1; i < n; ++i) {
        scanf("%d", &ai);
        std::set<node>::iterator q = l.lower_bound(node(ai, 0));
        std::set<node>::iterator p = q;
        if (p == l.begin()) p = l.end(); else --p;
        if (p == l.end() || (p->chl & CHL_RIGHT)) {
            // Put a_i under q as the left child
            printf("%d%c", q->val, i == n - 1 ? '\n' : ' ');
            //q->chl ^= CHL_LEFT;
            l.insert(node(q->val, q->chl ^ CHL_LEFT));
            l.erase(q);
        } else {
            // Put a_i under p as the right child
            printf("%d%c", p->val, i == n - 1 ? '\n' : ' ');
            //p->chl ^= CHL_RIGHT;
            l.insert(node(p->val, p->chl ^ CHL_RIGHT));
            l.erase(p);
        }
        l.insert(node(ai, 0));
    }

    return 0;
}