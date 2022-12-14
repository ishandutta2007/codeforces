#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct el
{
    el() {}
    el(int r, bool v) {row = r; val = v;}
    int row;
    bool val;

    bool operator<(const el& e) const
    {
        return row < e.row;
    }
};

int n, k;

vector<el> els[200020];

int par[400020];

int ufind(int v)
{
    // printf("UFIND %d %d\n", v, par[v]);
    if (par[v] == -1)
        return v;
    return (par[v] = ufind(par[v]));
}

int uno(int v)
{
    if (v < 200001)
        return v + 200001;
    return v - 200001;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int sm = 0; sm <= n + n; ++sm)
    {
        els[sm].push_back(el(sm, 0));
    }

    for (int i = 0; i < k; ++i)
    {
        int x, y;
        char v;
        char s[8];
        scanf("%d %d %s", &x, &y, s);
        v = s[0];

        int d = x + y;
        if (d > n + 1)
            d = n + n + 2 - d;
        int a = x - y;
        if (a < 0)
            a = -a;
        el e;
        e.row = d;
        e.val = (v == 'o');
        // printf("CELL %d %d %c -> %d %d %d\n", x, y, v, x - y + n, e.row, e.val);
        els[a].push_back(e);
    }

    memset(par, -1, sizeof(par));
    int bound = 0;
    for (int sm = 0; sm <= n; ++sm)
    {
        sort(els[sm].begin(), els[sm].end());
        for (int i = 1; i < (int) els[sm].size(); ++i)
        {
            // Add edge for els[sm][i], els[sm][i-1]
            
            int a = els[sm][i].row;
            int b = els[sm][i - 1].row;
            int para = ufind(a);
            int parb = ufind(b);
            // printf("OP %d %d\n", sm, i);
            // printf("AA %d %d\n", els[sm][i].row, els[sm][i - 1].row);
            // printf("EDGE %d %d :: %d %d\n", a, b, els[sm][i].val, els[sm][i - 1].val);

            if (para == parb && els[sm][i].val != els[sm][i - 1].val)
            {
                printf("0\n");
                return 0;
            }
            else if (para == uno(parb) && els[sm][i].val == els[sm][i - 1].val)
            {
                printf("0\n");
                return 0;
            }

            if (els[sm][i - 1].val == els[sm][i].val)
            {
                if (para != parb)
                {
                    ++bound;
                    // printf("SET PAR %d %d\n", para, parb);
                    par[para] = parb;
                    // printf("SET PAR %d %d\n", uno(para), uno(parb));
                    par[uno(para)] = uno(parb);
                }
            }
            else
            {
                if (para != uno(parb))
                {
                    ++bound;
                    // printf("SET PAR %d %d\n", para, uno(parb));
                    par[para] = uno(parb);
                    // printf("SET PAR %d %d\n", uno(para), parb);
                    par[uno(para)] = parb;
                }
            }
        }
    }
    int mod = 1000000007;
    int sl = 1;
    // printf("BOUND %d\n", bound);
    for (int i = 0; i < n - bound; ++i)
    {
        sl = sl + sl;
        if (sl >= mod)
            sl -= mod;
    }
    printf("%d\n", sl);
    return 0;
}