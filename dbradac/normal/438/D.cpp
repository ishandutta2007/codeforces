#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int TOUR = 1<<17;

struct tour {
    int maxx, ind;
    ll zbroj;
    tour (int maxx, int ind, ll zbroj) : maxx(maxx), ind(ind), zbroj(zbroj) {}
    tour () {}
} t[2*TOUR];

struct str {
    int pos, maxx;
    str (int pos, int maxx) : pos(pos), maxx(maxx) {}
    str () {}
};

bool operator < (str a, str b)
{
    return a.maxx < b.maxx;
}

void Stavi(int pos, int val)
{
    pos += TOUR;
    t[pos] = tour(val, pos-TOUR, (ll) val);
    for (pos /= 2; pos; pos /= 2) {
        t[pos].zbroj = t[2*pos].zbroj + t[2*pos+1].zbroj;
        if (t[2*pos].maxx > t[2*pos+1].maxx)
            t[pos].ind = t[2*pos].ind;
        else
            t[pos].ind = t[2*pos+1].ind;
        t[pos].maxx = max(t[2*pos].maxx, t[2*pos+1].maxx);
    }
}

ll VratiZbroj(int pos, int lo, int hi, int begin, int end)
{
    if (lo >= end || hi <= begin)
        return 0;
    if (lo >= begin && hi <= end)
        return t[pos].zbroj;
    return VratiZbroj(2*pos+0, lo, (lo+hi)/2, begin, end) +
           VratiZbroj(2*pos+1, (lo+hi)/2, hi, begin, end);
}

str VratiMaxx(int pos, int lo, int hi, int begin, int end)
{
    if (lo >= end || hi <= begin)
        return str(-1, -1);
    if (lo >= begin && hi <= end)
        return str(t[pos].ind, t[pos].maxx);
    return max(VratiMaxx(2*pos+0, lo, (lo+hi)/2, begin, end),
               VratiMaxx(2*pos+1, (lo+hi)/2, hi, begin, end));
}

int main()
{
    int n, q, i, st, l, r, mod, tmp;
    str maxx;

    scanf("%d%d", &n, &q);

    for (i=0; i<n; i++) {
        scanf("%d", &tmp);
        Stavi(i, tmp);
    }

    for (i=0; i<q; i++) {
        scanf("%d", &st);
        if (st == 1) {
            scanf("%d%d", &l, &r); l--; r--;
            printf("%I64d\n", VratiZbroj(1, 0, TOUR, l, r+1));
        }
        else if (st == 2) {
            scanf("%d%d%d", &l, &r, &mod); l--; r--;
            for (;;) {
                maxx = VratiMaxx(1, 0, TOUR, l, r+1);
                if (maxx.maxx >= mod)
                    Stavi(maxx.pos, maxx.maxx % mod);
                else
                    break;
            }
        }
        else {
            scanf("%d%d", &l, &tmp); l--;
            Stavi(l, tmp);
        }
    }

    return 0;
}