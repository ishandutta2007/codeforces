#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100100, INF = 1000000001, DEBUG = 0;

struct str {
    int abl, cij, ind;
    str (int abl, int cij, int ind) : abl(abl), cij(cij), ind(ind) {}
    str () {}
} stud[MAX];

bool operator < (str a, str b)
{
    if (a.cij != b.cij)
        return a.cij > b.cij;
    return a.ind < b.ind;
}

bool VeciAbl (str a, str b)
{
    if (a.abl != b.abl)
        return a.abl > b.abl;
    if (a.cij != b.cij)
        return a.cij < b.cij;
    return a.ind < b.ind;
}

struct strb {
    int val, ind;
    strb (int val, int ind) : val(val), ind(ind) {}
    strb () {}
} bug[MAX];

bool operator < (strb a, strb b)
{
    if (a.val != b.val)
        return a.val > b.val;
    return a.ind < b.ind;
}

int cijene[MAX], abl[MAX], tmp[MAX], rje[MAX], brstud, brbug, plat, taken[MAX];
priority_queue <str> Q;

int Moze(int brdan)
{
    int i, j, k, r=0, minn;

    for (;!Q.empty();)
        Q.pop();

    for (i=0, j=0; i<brbug; i+=brdan) {
        //if (!brdan)
            //printf("II %d\n", i);
        for (; j<brstud && stud[j].abl >= bug[i].val; j++)
            Q.push(stud[j]);

        if (Q.empty())
            return 0;
        minn = Q.top().ind;
        r += Q.top().cij;
        if (r > plat)
            return 0;
        for (k=i; k<i+brdan && k<brbug; k++) {
            tmp[bug[k].ind] = minn;
            //if (bug[k].val > abl[minn])
                //printf("NOOOOOO\n");
        }
        Q.pop();
    }

    if (r <= plat) {
        memcpy(rje, tmp, sizeof rje);
        //printf("CCC %d\n", brdan);
    }

    return r <= plat;
}

int main()
{
    int i, tmp, lo, mid, hi;

    scanf("%d%d%d", &brstud, &brbug, &plat);
    if (DEBUG) printf("%d %d %d\n", brstud, brbug, plat);

    for (i=0; i<brbug; i++) {
        scanf("%d", &tmp);
        if (DEBUG) printf("%d ", tmp);
        bug[i] = strb(tmp, i);
    }
    if (DEBUG) printf("\n");

    sort(bug, bug+brbug);

    for (i=0; i<brstud; i++) {
        scanf("%d", &abl[i]);
        if (DEBUG) printf("%d ", abl[i]);
    }
    if (DEBUG) printf("\n");

    for (i=0; i<brstud; i++) {
        scanf("%d", &cijene[i]);
        if (DEBUG) printf("%d ", cijene[i]);
        stud[i] = str(abl[i], cijene[i], i);
    }
    if (DEBUG) printf("\n");

    sort(stud, stud+brstud, VeciAbl);

    for (lo=1, hi=INF; lo<hi; ) {
        mid = (lo+hi) / 2;
        //printf("%d %d %d\n", lo, hi, mid);
        if (Moze(mid))
            hi = mid;
        else
            lo = mid + 1;
    }

    if (DEBUG) {
        if (lo == INF)
            printf("-1\n");
        else {
            printf("%d\n", lo);
            for (i=0; i<brbug; i++) {
                printf("%d ", rje[i] + 1);
                taken[rje[i]]++;
                //if (abl[rje[i]] < bug[i].val)
                    //printf("KAAAJ %d\n", rje[i]);
                /*if (taken[rje[i]] > lo)
                    printf("WTF %d\n", rje[i]);*/
            }
            //printf("\n");
        }
    }
    else {
        if (lo == INF)
            printf("NO\n");
        else {
            printf("YES\n");
            for (i=0; i<brbug; i++)
                printf("%d ", rje[i] + 1);
            printf("\n");
        }
    }

    return 0;
}