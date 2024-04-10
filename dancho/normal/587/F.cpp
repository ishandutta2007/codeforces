#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int lim = 320;

int ln = 0;
struct T {
    int next, son[26], id;
};

int lnd = 2, R = 1;
T nds[1 << 17];
int where[100020], C[100020];

int fin[100020];
vector<int> a[100020];

vector<int> son[100020];
int ag[100020];

void insert ( int nod , char *p , int ind ){
    // printf("PUSHING %d %d\n", nod, nds[nod].nr);
    a[ind].push_back(nod);
    int ch = (*p) - 'a';
    if ( !(ch >= 0 && ch < 26) ){
        fin[ind] = nod;
        where[ind] = nod;
        nds[nod].id = ind;
        return;
    }
    if ( nds[nod].son[ch] == 0) {
        nds[nod].son[ch] = lnd++;
        // printf("SET SN %d %d\n", nod, nds[nod].son[ch]);
    }
    insert(nds[nod].son[ch], p + 1, ind);
}

struct event {
    int tp;  // add node || query
    int time;  // event time.
    int v;
    int si;  // which sign for query.
    int id;  // which out to inc/dec
    bool operator<(const event &e) const {
        if (time == e.time) {
            // add node comes first
            return tp < e.tp;
        }
        return time < e.time;
    }
};

vector<event> ve;

int ci = 0;
int fi[1 << 17];
int li[1 << 17];

long long ssm[1 << 17];
long long bsm[1 << 17];

void increment(int l, int r) {
    for (int i = l; i <= r;) {
        if (i % lim == 0 && i + lim - 1 <= r) {
            ++bsm[i / lim];
            i += lim;
        } else {
            ++ssm[i];
            ++i;
        }
    }
}

void buildind(int v) {
    fi[v] = ++ci;
    for (int i = 0; i < (int) son[v].size(); ++i) {
        buildind(son[v][i]);
    }
    li[v] = ci;
}

int n, q;
char buf[1 << 20];
long long out[1 << 20];

void build(int v) {
    if (!v) {
        return;
    }
    if (nds[v].next != v) {
        son[nds[v].next].push_back(v);
    }
    for (int i = 0; i < 26; ++i) {
        build(nds[v].son[i]);
    }
}

void cag(int v) {
    for (int i = 0; i < (int) son[v].size(); ++i) {
        cag(son[v][i]);
        ag[v] += ag[son[v][i]];
    }
}

int main () {
    scanf("%d %d", &n, &q);
    for ( int i = 1 ; i <= n ; ++i ){
   	 scanf("%s", buf);
   	 insert(R, buf, i);
    }
    
    int p = 1,u = 0;    C[++u] = R; nds[R].next = R;
    for ( ; p <= u ; ++p ) {
        int nod = C[p];
        for (int ch = 0 ; ch < 26; ++ch) {
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

    build(R);

    for (int i = 0; i < q; ++i) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        event e;
        e.tp = 1;
        e.time = l - 1;
        e.v = k;
        e.si = -1;
        e.id = i;
        ve.push_back(e);

        e.tp = 1;
        e.time = r;
        e.v = k;
        e.si = 1;
        e.id = i;
        ve.push_back(e);
    }
    for (int i = 1; i <= n; ++i) {
        event e;
        e.tp = 0;
        e.time = i;
        e.v = i;
        ve.push_back(e);
    }
    sort(ve.begin(), ve.end());
    
    for (int i = 1; i <= n; ++i) {
        if (a[i].size() >= lim) {
            // Solve for large.
            memset(ag, 0, sizeof(ag));
            for (int j = 0; j < (int) a[i].size(); ++j) {
                ++ag[ a[i][j] ];
            }
            cag(R);
            long long num = 0;
            for (int j = 0; j < (int) ve.size(); ++j) {
                if (ve[j].tp == 0) {
                    num += ag[ fin[ve[j].v] ];
                } else if (ve[j].v == i) {
                    out[ ve[j].id ] += num * ve[j].si;
                }
            }
        }
    }

    buildind(R);
    memset(ssm, 0, sizeof(ssm));
    memset(bsm, 0, sizeof(bsm));
    // now do all the small.
    for (int j = 0; j < (int) ve.size(); ++j) {
        if (ve[j].tp == 0) {
            // printf("INC %d -> %d %d\n", ve[j].v,
            //         fi[ fin[ve[j].v] ], li[ fin[ve[j].v] ]);
            increment(fi[ fin[ve[j].v] ], li[ fin[ve[j].v] ]);
        } else {
            int i = ve[j].v;
            if (a[i].size() >= lim) {
                continue;
            }
            for (int k = 0; k < (int) a[i].size(); ++k) {
                int u = a[i][k];
                u = fi[u];
                // printf("QUE %d %d\n", ve[j].id, u);
                out[ ve[j].id ] += (ssm[ u ] + bsm[ u / lim ]) * ve[j].si;
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        printf("%lld\n", out[i]);
    }
    return 0;
}