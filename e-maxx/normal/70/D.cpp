#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;


const double EPS = 1E-9;


struct pt {
        int x, y;

        bool operator< (const pt & p) const {
                return x<p.x || x==p.x && y<p.y;
        }
};

int q;
set<pt> up, down;


bool read() {
        if (! (cin >> q))  return false;
        return true;
}


inline long long vec (pt a, pt b, pt c) {
        return (b.x - a.x) * 1ll * (c.y - a.y) - (b.y - a.y) * 1ll * (c.x - a.x);
}

inline bool cwise (pt a, pt b, pt c) {
        return vec (a, b, c) < 0;
}
inline bool ccwise (pt a, pt b, pt c) {
        return vec (a, b, c) > 0;
}


inline double segment_y (pt a, pt b, int x) {
        if (x < a.x || x > b.x)  throw;
        return a.y + (b.y - a.y) * 1. / (b.x - a.x) * (x - a.x);
}

double get_y (set<pt> & v, pt p) {
        set<pt>::iterator i = v.lower_bound (p);
        if (i == v.end())  --i;
        if (i->x == p.x)  return i->y;
        set<pt>::iterator j = i;  --j;
        return segment_y (*j, *i, p.x);
}

bool inside (pt p) {
        if (p.x < up.begin()->x || p.x > up.rbegin()->x)
                return false;
        double y1 = get_y (down, p);
        double y2 = get_y (up, p);
        return y1 <= p.y+EPS && p.y <= y2+EPS;
}


void include_up (pt p) {
    pt tmp = { p.x, -1000000 };
    set<pt>::iterator it = up.lower_bound (tmp);
    if (it != up.end() && it->x == p.x)  up.erase (it);

        up.insert (p);
        set<pt>::iterator i = up.find (p);
        for (;;) {
                set<pt>::iterator r1 = i;  ++r1;
                if (r1 != up.end()) {
                        set<pt>::iterator r2 = r1;  ++r2;
                        if (r2 != up.end())
                                if (! cwise (p, *r1, *r2)) {
                                        up.erase (r1);
                                        continue;
                                }
                }

                set<pt>::iterator l1 = i;
                if (l1 != up.begin()) {
                        --l1;
                        set<pt>::iterator l2 = l1;
                        if (l2 != up.begin()) {
                                --l2;
                                if (! cwise (*l2, *l1, p)) {
                                        up.erase (l1);
                                        continue;
                                }
                        }
                }

                break;
        }
}

void include_down (pt p) {
    pt tmp = { p.x, -1000000 };
    set<pt>::iterator it = down.lower_bound (tmp);
    if (it != down.end() && it->x == p.x)  down.erase (it);

        down.insert (p);
        set<pt>::iterator i = down.find (p);
        for (;;) {
                set<pt>::iterator r1 = i;  ++r1;
                if (r1 != down.end()) {
                        set<pt>::iterator r2 = r1;  ++r2;
                        if (r2 != down.end())
                                if (! ccwise (p, *r1, *r2)) {
                                        down.erase (r1);
                                        continue;
                                }
                }

                set<pt>::iterator l1 = i;
                if (l1 != down.begin()) {
                        --l1;
                        set<pt>::iterator l2 = l1;
                        if (l2 != down.begin()) {
                                --l2;
                                if (! ccwise (*l2, *l1, p)) {
                                        down.erase (l1);
                                        continue;
                                }
                        }
                }

                break;
        }
}

void include (pt p) {
        bool in_x = p.x >= up.begin()->x && p.x <= up.rbegin()->x;
        if (in_x && p.y < get_y (down, p) - EPS)
                include_down (p);
        else if (in_x && p.y > get_y (up, p) + EPS)
                include_up (p);
        else {
                include_up (p);
                include_down (p);
        }
}


void solve() {
        up.clear();
        down.clear();

        pt a[3];
        for (int i=0; i<3; ++i) {
                int tmp;
                scanf ("%d%d%d", &tmp, &a[i].x, &a[i].y);
                if (tmp != 1)  throw;
        }
        sort (a, a+3);
        if (a[0].x == a[1].x) {
                down.insert (a[0]);
                down.insert (a[2]);
                up.insert (a[1]);
                up.insert (a[2]);
        }
        else if (a[1].x == a[2].x) {
                down.insert (a[0]);
                down.insert (a[1]);
                up.insert (a[0]);
                up.insert (a[2]);
        }
        else {
                down.insert (a[0]);
                up.insert (a[0]);
                if (cwise (a[0], a[1], a[2]))
                        up.insert (a[1]);
                else
                        down.insert (a[1]);
                down.insert (a[2]);
                up.insert (a[2]);
        }

        for (int i=3; i<q; ++i) {
                int tp;
                pt p;
                scanf ("%d%d%d", &tp, &p.x, &p.y);

                bool in = inside (p);
                if (tp == 1) {
                        if (!in)
                                include (p);
                }
                else
                        puts (in ? "YES" : "NO");
        }
}


int main() {
#ifndef ONLINE_JUDGE
        freopen ("input.txt", "rt", stdin);
        freopen ("output.txt", "wt", stdout);
#endif

        while (read())
                solve();

}