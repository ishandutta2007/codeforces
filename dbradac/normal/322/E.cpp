#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1<<17;

vector <int> V[MAX];
int najv[MAX], rje[MAX], done[MAX], minn, ind;

int RekKolko(int node, int prosli)
{
    int r = 1;
    vector <int> :: iterator it;

    najv[node] = 0;

    for (it=V[node].begin(); it!=V[node].end(); it++)
        if (!done[*it] && *it != prosli)
            r += RekKolko(*it, node);

    return r;
}

int Rek(int node, int prosli, int kolko)
{
    int r = 1, tmp;
    vector <int> :: iterator it;

    for (it=V[node].begin(); it!=V[node].end(); it++)
        if (!done[*it] && *it != prosli) {
            tmp = Rek(*it, node, kolko);
            najv[node] = max(najv[node], tmp);
            r += tmp;
        }

    najv[node] = max(najv[node], kolko - r);
    if (najv[node] < minn) {
        minn = najv[node];
        ind = node;
    }

    return r;
}

void RekPovecaj(int node, int prosli)
{
    vector <int> :: iterator it;

    if (node != ind)
        rje[node]++;

    for (it=V[node].begin(); it!=V[node].end(); it++)
        if (!done[*it] && *it != prosli)
            RekPovecaj(*it, node);
}

int main()
{
    int n, i, a, b, kolko;

    scanf("%d", &n);

    for (i=0; i<n-1; i++) {
        scanf("%d%d", &a, &b); a--; b--;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    for (i=0; i<n; ) {
        if (done[i]) {
            i++;
            continue;
        }

        minn = MAX; ind = -1;
        kolko = RekKolko(i, -1);
        Rek(i, -1, kolko);
        RekPovecaj(i, -1);
        done[ind] = 1;
    }

    for (i=0; i<n; i++)
        printf("%c ", 'A' + rje[i]);
    printf("\n");

    return 0;
}