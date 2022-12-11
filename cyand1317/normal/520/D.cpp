#include <cstdio>
#include <map>
#include <set>
#include <utility>
static const int DIVIDOR = 1e9 + 9;
typedef std::pair<int, int> point;
typedef std::set<int> pointlist;
#define x first
#define y second

pointlist all, rmvb;    // That's 'removable', not a file extension
std::map<point, int> _ptnum;
point *pts;

inline int ptnum(const point &p)
{
    std::map<point, int>::iterator s = _ptnum.find(p);
    return s == _ptnum.end() ? -1 : s->second;
}

void recheck(point p)
{
    if (all.find(ptnum(p)) == all.end()) return;
    pointlist::iterator ritr = rmvb.find(ptnum(p));
    bool rmvbnow = ritr != rmvb.end(),
        tl1 = all.count(ptnum(point(p.x - 1, p.y + 1))),
        tm0 = all.count(ptnum(point(p.x, p.y + 1))),
        tr1 = all.count(ptnum(point(p.x + 1, p.y + 1))),
        l2 = all.count(ptnum(point(p.x - 2, p.y))),
        l1 = all.count(ptnum(point(p.x - 1, p.y))),
        r1 = all.count(ptnum(point(p.x + 1, p.y))),
        r2 = all.count(ptnum(point(p.x + 2, p.y)));
    bool nrmvbsoon = (tl1 && !(l2 || l1)) ||
        (tr1 && !(r2 || r1)) || (tm0 && !(l1 || r1));
    if (!(rmvbnow ^ nrmvbsoon)) {
        if (rmvbnow) rmvb.erase(ritr);
        else rmvb.insert(ptnum(p));
    }
}

int main()
{
    int m;
    scanf("%d", &m);
    pts = new point[m + 3];
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &pts[i].x, &pts[i].y);
        _ptnum[pts[i]] = i;
        all.insert(i);
    }
    for (pointlist::iterator i = all.begin(); i != all.end(); ++i) {
        recheck(pts[*i]);
    }
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        int t;
        if (i % 2) {
            // Petya (min. player)
            pointlist::iterator it = rmvb.begin();
            t = *it; rmvb.erase(it);
        } else {
            // Vasya (max. player)
            // rbegin() returns reverse_iterator, which can't be used to erase elements
            pointlist::iterator it = rmvb.end();
            t = *(--it); rmvb.erase(it);
        }
        all.erase(t);
        ans = (ans * m + t) % DIVIDOR;
        int cx = pts[t].x, cy = pts[t].y;
        recheck(point(cx - 2, cy));
        recheck(point(cx - 1, cy));
        recheck(point(cx + 1, cy));
        recheck(point(cx + 2, cy));
        recheck(point(cx - 1, cy - 1));
        recheck(point(cx, cy - 1));
        recheck(point(cx + 1, cy - 1));
    }
    delete[] pts;
    printf("%I64d\n", ans);
    return 0;
}