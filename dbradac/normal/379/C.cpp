#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 300100;

struct str {
    int val, ind;
    str (int val, int ind) : val(val), ind(ind) {}
    str () {}
} p[MAX];

bool operator < (str a, str b)
{
    return a.val < b.val;
}

ll rje[MAX];

int main()
{
    int n, i, tmp;
    ll minn=1;

    scanf("%d", &n);

    for (i=0; i<n; i++) {
        scanf("%d", &tmp);
        p[i] = str(tmp, i);
    }

    sort(p, p+n);

    for (i=0; i<n; i++) {
        rje[p[i].ind] = max(minn, (ll) p[i].val);
        minn = rje[p[i].ind] + 1;
    }

    for (i=0; i<n; i++)
        printf("%I64d ", rje[i]);

    return 0;
}