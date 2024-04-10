#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

const int MAX = 1<<5;

struct str {
    int red, stup;
    str (int red, int stup) : red(red), stup(stup) {}
    str () {}
};

bool operator == (str a, str b) {
    return a.red == b.red && a.stup == b.stup;
}

int brred, brstup, polje[MAX][MAX], kraj[MAX][MAX], k1[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, k2[8] = {0, 1, 1, 1, 0, -1, -1, -1}, tmpred, tmpstup;
int taken[MAX][MAX], bio[MAX][MAX], odakle1[MAX][MAX], odakle2[MAX][MAX], polje2[MAX][MAX];
queue <str> Q;
vector <str> R;
map <int, int> M;

void Pomak(int smjer)
{
    int nred, nstup;

    nred = tmpred + k1[smjer];
    nstup = tmpstup + k2[smjer];

    swap(polje[tmpred][tmpstup], polje[nred][nstup]);
    R.push_back(str(nred, nstup));
    tmpred = nred;
    tmpstup = nstup;
}

str Nadi(int val)
{
    int i, j;

    for (i=1; i<=brred; i++)
        for (j=1; j<=brstup; j++)
            if (!taken[i][j] && polje[i][j] == val && (i != tmpred || j != tmpstup))
                return str(i, j);

    return str(-1, -1);
}

int Moze(int red, int stup)
{
    if (red < 1 || stup < 1 || red > brred || stup > brstup || taken[red][stup] || bio[red][stup])
        return 0;
    return 1;
}

void BfsPom(str to)
{
    int i, nred, nstup, da=0;
    str from, tmp;

    from = str(tmpred, tmpstup);

    for (; !Q.empty(); Q.pop());
    memset(bio, 0, sizeof bio);

    Q.push(to);
    bio[to.red][to.stup] = 1;

    for (; !Q.empty(); ) {
        tmp = Q.front();
        Q.pop();

        if (tmp == from) {
            da = 1;
            break;
        }

        for (i=0; i<8; i++) {
            nred = tmp.red + k1[i];
            nstup = tmp.stup + k2[i];
            if (Moze(nred, nstup)) {
                Q.push(str(nred, nstup));
                bio[nred][nstup] = 1;
                odakle1[nred][nstup] = (i+4) % 8;
            }
        }
    }

    for (; tmpred != to.red || tmpstup != to.stup;)
        Pomak(odakle1[tmpred][tmpstup]);

    if (!da)
        printf("NIJE NASO BFSPOM\n");
}

void Bfs(str from, str to)
{
    int i, nred, nstup, da=0;
    str tmp, slj;

    for (; !Q.empty(); Q.pop());
    memset(bio, 0, sizeof bio);

    Q.push(to);
    bio[to.red][to.stup] = 1;

    for (; !Q.empty(); ) {
        tmp = Q.front();
        Q.pop();

        if (tmp == from) {
            da = 1;
            break;
        }

        for (i=0; i<8; i++) {
            nred = tmp.red + k1[i];
            nstup = tmp.stup + k2[i];
            if (Moze(nred, nstup)) {
                Q.push(str(nred, nstup));
                bio[nred][nstup] = 1;
                odakle2[nred][nstup] = (i+4) % 8;
            }
        }
    }

    for (tmp=from; !(tmp == to);) {
        taken[tmp.red][tmp.stup] = 1;
        slj = str(tmp.red + k1[odakle2[tmp.red][tmp.stup]], tmp.stup + k2[odakle2[tmp.red][tmp.stup]]);
        BfsPom(slj);
        Pomak((4 + odakle2[tmp.red][tmp.stup]) % 8);
        taken[tmp.red][tmp.stup] = 0;
        tmp = slj;
    }

    if (!da)
        printf("NIJE NASO BFS\n");
}

void IspisPot()
{
    int i;

    printf("%u\n", R.size() - 1);
    for (i=0; (unsigned) i<R.size(); i++)
        printf("%d %d\n", R[i].red, R[i].stup);
}

void IspisPloce(char s[10], int p[MAX][MAX])
{
    int i, j;

    printf("%s\n", s);
    for (i=1; i<=brred; i++) {
        for (j=1; j<=brstup; j++)
            printf("%d ", p[i][j]);
        printf("\n");
    }
    printf("\n");
}

int Done()
{
    int i, j;

    for (i=1; i<=brred; i++)
        for (j=1; j<=brstup; j++)
            if (polje[i][j] != kraj[i][j])
                return 0;
    return 1;
}
void RijesiKraj()
{
    int sm, nred, nstup, i, j, ne;

    memset(bio, 0, sizeof bio);

    for (;;) {
        ne = 0;
        for (i=brred-1; i<=brred; i++)
            for (j=brstup-1; j<=brstup; j++)
                if (polje[i][j] != kraj[i][j])
                    ne = 1;
        if (!ne)
            return;
        sm = rand() % 8;
        nred = tmpred + k1[sm];
        nstup = tmpstup + k2[sm];
        if (Moze(nred, nstup))
            Pomak(sm);
    }
}

int main()
{
    int i, j, sm, da=0;
    str pocetak;
    map <int, int> :: iterator it;

    scanf("%d%d", &brred, &brstup);

    for (i=1; i<=brred; i++)
        for (j=1; j<=brstup; j++) {
            scanf("%d", &polje[i][j]);
            M[polje[i][j]]++;
        }

    for (i=1; i<=brred; i++)
        for (j=1; j<=brstup; j++) {
            scanf("%d", &kraj[i][j]);
            M[kraj[i][j]]--;
        }

    for (it=M.begin(); it!=M.end(); it++)
        if (it->second) {
            printf("-1\n");
            return 0;
        }

    if (brred > 1 && brstup > 1) {
        pocetak = Nadi(kraj[brred][brstup]);
        tmpred = pocetak.red;
        tmpstup = pocetak.stup;

        R.push_back(pocetak);

        for (i=1; i<=brred-2; i++) {
            for (j=1; j<=brstup; j++) {
                Bfs(Nadi(kraj[i][j]), str(i, j));
                taken[i][j] = 1;
            }
        }

        for (j=1; j<=brstup-2; j++) {
            for (i=brred-1; i<=brred; i++) {
                Bfs(Nadi(kraj[i][j]), str(i, j));
                taken[i][j] = 1;
            }
        }

        RijesiKraj();
        da = 1;
        IspisPot();
    }
    else if (brred == 1) {
        memcpy(polje2, polje, sizeof polje);
        tmpred = 1;
        for (i=1; i<=brstup; i++) {
            for (j=1; j<=brstup; j++) {
                memcpy(polje, polje2, sizeof polje);
                R.clear();
                tmpstup = i;
                if (j > i)
                    sm = 2;
                else
                    sm = 6;

                R.push_back(str(1, i));
                for (; tmpstup != j; Pomak(sm));

                if (Done()) {
                    da = 1;
                    IspisPot();
                    break;
                }
            }
            if (da)
                break;
        }
    }
    else {
        memcpy(polje2, polje, sizeof polje);
        tmpstup = 1;
        for (i=1; i<=brred; i++) {
            for (j=1; j<=brred; j++) {
                memcpy(polje, polje2, sizeof polje);
                R.clear();
                tmpred = i;
                if (j > i)
                    sm = 4;
                else
                    sm = 0;

                R.push_back(str(i, 1));
                for (; tmpred != j; Pomak(sm));

                if (Done()) {
                    da = 1;
                    IspisPot();
                    break;
                }
            }
            if (da)
                break;
        }
    }

    if (!da)
        printf("-1\n");

    return 0;
}