#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

char inp[1<<24];

int n;
int A[1<<20];

long long ps[1<<20];

struct pt {
    long long x, y, id;
};
 
inline bool cmp_x (const pt & a, const pt & b) {
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}
 
inline bool cmp_y (const pt & a, const pt & b) {
    return a.y < b.y;
}
 
pt a[1 << 20];

long long mindist;
int ansa, ansb;
 
inline void upd_ans (const pt & a, const pt & b) {
    long long dist = ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    if (dist < mindist)
        mindist = dist,  ansa = a.id,  ansb = b.id;
}

pt t[1 << 20];

void rec (int l, int r) {
    if (r - l <= 3) {
        for (int i=l; i<=r; ++i)
            for (int j=i+1; j<=r; ++j)
                upd_ans (a[i], a[j]);
        sort (a+l, a+r+1, &cmp_y);
        return;
    }
 
    int m = (l + r) >> 1;
    int midx = a[m].x;
    rec (l, m),  rec (m+1, r);
    merge (a+l, a+m+1, a+m+1, a+r+1, t, &cmp_y);
    memcpy(a + l, t, sizeof(a[0]) * (r - l + 1));
    // copy (t, t+r-l+1, a+l);
 
    int tsz = 0;
    for (int i=l; i<=r; ++i)
        if (abs (a[i].x - midx) * abs(a[i].x - midx) < mindist) {
            for (int j=tsz-1; j>=0 && (a[i].y - t[j].y) * (a[i].y - t[j].y) < mindist; --j)
                upd_ans (a[i], t[j]);
            t[tsz++] = a[i];
        }
}

int pp = 0;
inline int getInt()
{
    while (inp[pp] < '0' || inp[pp] > '9')
        ++pp;
    int r = 0;
    int sp = pp - 1;
    while (inp[pp] >= '0' && inp[pp] <= '9')
    {
        r = r * 10 + inp[pp] - '0';
        ++pp;
    }
    if (sp >= 0 && inp[sp] == '-')
        r = -r;
    return r;
}


int main()
{
    fread(inp, 1<<24, 1, stdin);
    n = getInt();
    //~ scanf("%d", &n);
    ps[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        A[i] = getInt();
        //~ scanf("%d", &A[i]);
        ps[i] = ps[i-1] + A[i];
        a[i-1].x = i;
        a[i-1].y = ps[i];
    }

    sort (a, a+n, &cmp_x);
    mindist = 1LL<<62;
    rec (0, n-1);

    printf("%d\n", (int) mindist);
    return 0;
}