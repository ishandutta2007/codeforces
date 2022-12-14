#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;

struct T {
    int nr;
    int next;
    int son[2];
    int suf;
    int id;
    T () {
   	 nr = 0;
   	 next = 0;
     suf = 0;
     id = 0;
   	 for ( int i = 0 ; i < 2; ++i )    son[i] = 0;
    }
};

int lnd = 2;
T nds[10 << 20];
int R = 1;
int where[800], C[10 << 20];

void insert ( int nod , char *p , int ind ){
    int ch = (*p) - 'a';
    if ( !(ch >= 0 && ch < 2) ){
        where[ind] = nod;
        nds[nod].id = ind;
        nds[nod].suf = ind;
        return;
    }
    if ( nds[nod].son[ch] == 0) {
        nds[nod].son[ch] = lnd++;
    }
    insert(nds[nod].son[ch], p + 1, ind);
}

int n;
char buf[10 << 20];
vector<string> vs;

set<int> to[800];

bool us[800];

int fr[800];

int ml[800];
int zl[800];
int zr[800];

vector<int> ac;

bool augment(int v) {
    if (us[v]) {
        return false;
    }
    us[v] = 1;
    for (set<int>::iterator it = to[v].begin(); it != to[v].end(); ++it) {
        if (!fr[*it] || augment(fr[*it])) {
            fr[*it] = v;
            ml[v] = *it;
            return true;
        }
    }
    return false;
}

void genz(int v) {
    if (zl[v]) {
        return;
    }
    zl[v] = 1;
    for (set<int>::iterator it = to[v].begin(); it != to[v].end(); ++it) {
        int u = *it;
        if (fr[u] != v) {
            zr[u] = 1;
            genz(fr[u]);
        }
    }
}

int match() {
    int ma = 0;
    memset(fr, 0, sizeof(fr));
    memset(ml, 0, sizeof(ml));
    for (int i = 1; i <= n; ++i) { 
        memset(us, 0, sizeof(us));
        if (augment(i)) {
            ++ma;
        }
    }
    memset(zl, 0, sizeof(zl));
    memset(zr, 0, sizeof(zr));
    for (int i = 1; i <= n; ++i) {
        if (!ml[i]) {
            genz(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (zl[i] && !zr[i]) {
            ac.push_back(i);
        }
    }
    return ma;
}

int dsuf(int nd) {
    if (nds[nd].suf) {
        return nds[nd].suf;
    }
    if (nd == R) {
        return -1;
    }
    return (nds[nd].suf = dsuf(nds[nd].next));
}

void maketo(int v) {
    if (us[v]) return;
    us[v] = 1;
    int nd = R;
    int k = dsuf(nds[where[v]].next);
    if (k != -1) {
        maketo(k);
        to[v] = to[k];
        to[v].insert(k);
    }
    for (int i = 0; i < (int) vs[v - 1].size(); ++i) {
        nd = nds[nd].son[vs[v - 1][i] - 'a'];
        if (nd == where[v]) {
            break;
        }
        int k = dsuf(nd);
        if (k != -1) {
            maketo(k);
            if (to[v].find(k) == to[v].end()) {
                to[v].insert(k);
                for (set<int>::iterator it = to[k].begin();
                        it != to[k].end(); ++it) {
                    to[v].insert(*it);
                }
            }
        }
    }
}

int main () {
    scanf("%d", &n);
    for ( int i = 0 ; i < n ; ++i ){
        scanf("%s", buf);
        vs.push_back(buf);
        insert(R, buf, i + 1);
    }
    
    int p = 1,u = 0;    C[++u] = R; nds[R].next = R;
    for ( ; p <= u ; ++p ) {
        int nod = C[p];
        dsuf(nod);
        for (int ch = 0 ; ch < 2; ++ch) {
            if ( nds[nod].son[ch] == 0 )    continue ;

            int suffix = nds[nod].next;
            while ( suffix != R && nds[suffix].son[ch] == 0 ) {
                suffix = nds[suffix].next;
            }
            if (nds[suffix].son[ch] != 0 &&
                    nds[suffix].son[ch] != nds[nod].son[ch])
                nds[nds[nod].son[ch]].next = nds[suffix].son[ch];
            else
                nds[nds[nod].son[ch]].next = R;
            C[++u] = nds[nod].son[ch];
        }
    }

    memset(us, 0, sizeof(us));
    for (int i = 1; i <= n; ++i) {
        if (!us[i]) {
            maketo(i);
        }
    }
    int ma = match();
    printf("%d\n", n - ma);
    for (int i = 0; i < (int) ac.size(); ++i) {
        printf("%d ", ac[i]);
    }
    printf("\n");
    return 0;
}