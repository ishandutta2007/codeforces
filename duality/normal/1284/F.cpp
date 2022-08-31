#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------

class link_cut {
    private:
        int N;
        struct node {
            node *l,*r,*p;
            int k,s,f;
        };
        node **nodes;
        int size(node *r) {
            if (r == NULL) return 0;
            else return r->s;
        }
        int update(node *r) {
            if (r != NULL) r->s = size(r->l)+size(r->r)+1;
            return 0;
        }
        int prop(node *r) {
            if (r->f) {
                swap(r->l,r->r);
                if (r->l != NULL) r->l->f ^= 1;
                if (r->r != NULL) r->r->f ^= 1;
                r->f = 0;
            }
            return 0;
        }
        int isRoot(node *r) {
            return (r->p == NULL) || ((r->p->l != r) && (r->p->r != r));
        }
        int rotL(node *r) {
            node *n = r->r;
            r->r = n->l;
            if (n->l != NULL) n->l->p = r;
            n->p = r->p;
            if (r->p != NULL) {
                if (r->p->l == r) r->p->l = n;
                else if (r->p->r == r) r->p->r = n;
            }
            n->l = r,r->p = n;
            update(r),update(n);
            return 0;
        }
        int rotR(node *r) {
            node *n = r->l;
            r->l = n->r;
            if (n->r != NULL) n->r->p = r;
            n->p = r->p;
            if (r->p != NULL) {
                if (r->p->l == r) r->p->l = n;
                else if (r->p->r == r) r->p->r = n;
            }
            n->r = r,r->p = n;
            update(r),update(n);
            return 0;
        }
        int splay(node *n) {
            if (n == NULL) return 0;
            while (!isRoot(n)) {
                if (isRoot(n->p)) {
                    prop(n->p),prop(n);
                    if (n == n->p->l) rotR(n->p);
                    else rotL(n->p);
                }
                else {
                    prop(n->p->p),prop(n->p),prop(n);
                    if ((n->p->l == n) && (n->p->p->l == n->p)) rotR(n->p->p),rotR(n->p);
                    else if ((n->p->r == n) && (n->p->p->r == n->p)) rotL(n->p->p),rotL(n->p);
                    else if ((n->p->l == n) && (n->p->p->r == n->p)) rotR(n->p),rotL(n->p);
                    else rotL(n->p),rotR(n->p);
                }
            }
            prop(n);
            return 0;
        }
        int access(node *n) {
            for (splay(n),n->r = NULL,update(n); n->p != NULL; splay(n)) splay(n->p),n->p->r = n;
            return 0;
        }
        int evert(node *n) {
            access(n),n->f ^= 1;
            return 0;
        }
    public:
        link_cut(int n) {
            int i;
            N = n;
            nodes = new node*[N];
            for (i = 0; i < N; i++) {
                nodes[i] = new node;
                nodes[i]->l = nodes[i]->r = nodes[i]->p = NULL;
                nodes[i]->k = i,nodes[i]->s = 1;
            }
        }
        ~link_cut() {
            int i;
            for (i = 0; i < N; i++) delete nodes[i];
            delete nodes;
        }

        int conn(int a,int b) {
            if (a == b) return 1;
            access(nodes[a]),access(nodes[b]);
            return nodes[a]->p != NULL;
        }
        int link(int a,int b) {
            evert(nodes[a]);
            nodes[a]->p = nodes[b];
            access(nodes[a]);
            return 0;
        }
        int cut(int a,int b) {
            node *n = nodes[a];
            evert(nodes[b]);
            access(n);
            n->l->p = NULL;
            n->l = NULL;
            update(n);
            return 0;
        }
        int dist(int a,int b) {
            evert(nodes[a]);
            access(nodes[b]);
            return nodes[b]->s-1;
        }
};
link_cut tree(250000);
vi adjList[250000];
pii edges[250000];
int parent[250000][18],depth[250000];
int doDFS(int u,int p,int d) {
    int i;
    parent[u][0] = p,depth[u] = d;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u,d+1);
    }
    return 0;
}
int logn;
int lca(int u,int v) {
    int i;
    if (depth[u] < depth[v]) swap(u,v);
    for (i = logn-1; i >= 0; i--) {
        if ((parent[u][i] != -1) && (depth[parent[u][i]] >= depth[v])) u = parent[u][i];
    }
    if (u == v) return u;
    for (i = logn-1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) u = parent[u][i],v = parent[v][i];
    }
    return parent[u][0];
}
int kth(int u,int v,int l,int k) {
    int i;
    if (k <= depth[u]-depth[l]) {
        for (i = logn-1; i >= 0; i--) {
            if (k & (1 << i)) u = parent[u][i];
        }
        return u;
    }
    else {
        k = depth[u]+depth[v]-2*depth[l]-k;
        for (i = logn-1; i >= 0; i--) {
            if (k & (1 << i)) v = parent[v][i];
        }
        return v;
    }
}
int main() {
    int i,j;
    int n,a,b;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&a,&b);
        a--,b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&a,&b);
        a--,b--;
        edges[i] = mp(a,b);
        tree.link(a,b);
    }
    doDFS(0,-1,0);
    for (i = 1; (1 << i) < n; i++) {
        for (j = 0; j < n; j++) {
            if (parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
            else parent[j][i] = -1;
        }
    }
    logn = i;

    printf("%d\n",n-1);
    for (i = 0; i < n-1; i++) {
        a = edges[i].first,b = edges[i].second;
        tree.cut(a,b);
        int l = lca(a,b),u;
        if (!tree.conn(a,l)) {
            u = a;
            for (j = logn-1; j >= 0; j--) {
                if ((parent[u][j] != -1) && (depth[parent[u][j]] >= depth[l])) {
                    if (!tree.conn(l,parent[u][j])) u = parent[u][j];
                }
            }
        }
        else {
            u = b;
            for (j = logn-1; j >= 0; j--) {
                if ((parent[u][j] != -1) && (depth[parent[u][j]] >= depth[l])) {
                    if (!tree.conn(l,parent[u][j])) u = parent[u][j];
                }
            }
        }
        int c = u,d = parent[u][0];
        tree.link(c,d);
        printf("%d %d %d %d\n",c+1,d+1,a+1,b+1);
    }

    return 0;
}