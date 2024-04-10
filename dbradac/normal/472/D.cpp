#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1<<11;

struct str {
    int node, val;
    str (int node, int val) : node(node), val(val) {}
    str () {}
} e[MAX][MAX];

bool operator < (str a, str b)
{
    if (a.val != b.val)
        return a.val < b.val;
    return a.node < b.node;
}

int poc[MAX][MAX], bio[MAX], n, ne;
vector <str> V[MAX];

void Rek(int node, int prosli)
{
    int i, sljn;

    bio[node] = 1;

    for (i=0; i<n; i++) {
        sljn = e[node][i].node;
        if (!bio[sljn]) {
            if (prosli == -1 || poc[node][sljn] < poc[prosli][sljn]) {
                V[node].push_back(str(sljn, poc[node][sljn]));
                V[sljn].push_back(str(node, poc[node][sljn]));
                Rek(sljn, node);
            }
        }
    }
}

void RekProv(int prvi, int node, int prosli, int dist)
{
    int i;

    if (poc[prvi][node] != dist)
        ne = 1;

    for (i=0; (unsigned) i<V[node].size(); i++)
        if (V[node][i].node != prosli)
            RekProv(prvi, V[node][i].node, node, dist + V[node][i].val);
}

int main()
{
    int i, j, tmp;

    scanf("%d", &n);

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            scanf("%d", &poc[i][j]);
            e[i][j] = str(j, poc[i][j]);
        }
        sort(e[i], e[i]+n);
    }

    Rek(0, -1);

    for (i=tmp=0; i<n; i++)
        tmp += (int) V[i].size();

    for (i=0; i<n; i++)
        for (j=0; (unsigned) j<V[i].size(); j++)
            if (V[i][j].val <= 0)
                ne = 1;

    /*for (i=0; i<n; i++) {
        for (j=0; (unsigned) j<V[i].size(); j++) {
            printf("%d %d    ", V[i][j].node, V[i][j].val);
        }
        printf("\n");
    }*/

    if (tmp != 2 * (n - 1))
        ne = 1;

    for (i=0; i<n; i++)
        RekProv(i, i, -1, 0);

    if (ne)
        printf("NO\n");
    else
        printf("YES\n");

    return 0;
}