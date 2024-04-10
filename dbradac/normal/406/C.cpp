#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100100;

int dub[MAX], bio[MAX];
vector <int> V[MAX], T[MAX];

int Rek(int node, int prosli)
{
    int tmp, i;
    vector <int> :: iterator it;

    bio[node] = 1;
    dub[node] = dub[prosli] + 1;

    for (it=V[node].begin(); it!=V[node].end(); it++) {
        if (bio[*it]) {
            if (*it != prosli && dub[*it] < dub[node])
                T[node].push_back(*it);
        }
        else {
            tmp = Rek(*it, node);
            if (tmp)
                T[node].push_back(*it);
        }
    }

    if (node)
        T[node].push_back(prosli);

    for (i=0; (unsigned) i < T[node].size() - (T[node].size() & 1); i+=2)
        printf("%d %d %d\n", T[node][i]+1, node+1, T[node][i+1]+1);

    return T[node].size() & 1;
}

int main()
{
    int n, e, i, a, b;

    scanf("%d%d", &n, &e);

    if (e & 1)
        printf("No solution\n");
    else {
        for (i=0; i<e; i++) {
            scanf("%d%d", &a, &b); a--; b--;
            V[a].push_back(b);
            V[b].push_back(a);
        }
        Rek(0, 0);
    }

    return 0;
}