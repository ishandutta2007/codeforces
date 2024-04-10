#include <cstdio>
#include <set>
static const int MAXQ = 2e5 + 4;
static const int TUT = 1087665544;

/**
     l |- w -
    + + +|+ + + +  
    + + +|+ + + +  |
    + + +|+ + + +
    + + +|+ + + +  h
    + + +|+ + +
    + + +|+ +      |
    + + +|+        
           col
**/
struct plate {
    int col, wid, hig, left;
    plate(int col = -1, int wid = 0, int hig = 0, int left = 0)
    : col(col), wid(wid), hig(hig), left(left) { }
};
inline bool operator < (const plate &lhs, const plate &rhs) {
    return (lhs.col == rhs.col) ? (
        lhs.wid == rhs.wid ? lhs.hig < rhs.hig : lhs.wid > rhs.wid
    ) : (lhs.col < rhs.col);
}

int n, q;
std::set<plate> p;

inline void add_plate(const int col, const int wid, const int hig, const int left) {
    if (wid > 0) p.insert(plate(col, wid, hig, left));
}
int main()
{
    scanf("%d%d", &n, &q);
    p.insert(plate(1, n, n, 0));

    int c; char dir;
    do {
        scanf("%d%*d %c", &c, &dir);
        std::set<plate>::iterator i = p.upper_bound(plate(c)); --i;
        if (i->hig == TUT) { puts("0"); continue; }
        if (dir == 'U') {
            add_plate(i->col, c - i->col, i->hig, i->left);
            add_plate(c + 1, i->wid - (c - i->col) - 1, i->hig - (c - i->col) - 1, 0);
            printf("%d\n", i->hig - (c - i->col));
        } else {    // dir == 'L'
            add_plate(i->col, c - i->col, c - i->col, i->left);
            add_plate(c + 1, i->wid - (c - i->col) - 1, i->hig - (c - i->col) - 1, i->left + (c - i->col) + 1);
            printf("%d\n", i->left + (c - i->col) + 1);
        }
        add_plate(c, 1, TUT, TUT);
        p.erase(i);
    } while (--q);

    return 0;
}