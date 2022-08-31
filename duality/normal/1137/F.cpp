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

struct node {
    node *l,*r,*p;
    int c,k,s,f;
};
node *nodes[200000];
int bit[400001];
int update(int i,int num) {
    for (i++; i <= 400000; i += i & (-i)) bit[i] += num;
    return 0;
}
int query(int i) {
    int sum = 0;
    for (i++; i > 0; i -= i & (-i)) sum += bit[i];
    return sum;
}
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
    update(r),update(n),n->c = r->c;
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
    update(r),update(n),n->c = r->c;
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
int cc = 0,yes = 0;
int access(node *n) {
    splay(n);
    if (yes) {
        update(n->c,-(size(n->l)+1));
        if (n->r != NULL) n->r->c = n->c;
    }
    n->r = NULL,update(n);
    while (n->p != NULL) {
        splay(n->p);
        if (yes) update(n->p->c,-(size(n->p->l)+1));
        if (n->p->r != NULL) n->p->r->c = n->p->c;
        n->p->r = n;
        splay(n);
    }
    return 0;
}
int evert(node *n) {
    access(n),n->f ^= 1;
    if (yes) n->c = cc++,update(cc-1,n->s);
    return 0;
}
int link(int a,int b) {
    evert(nodes[a]);
    nodes[a]->p = nodes[b];
    access(nodes[a]);
    return 0;
}
int when(int a) {
    splay(nodes[a]);
    return query(nodes[a]->c-1)+size(nodes[a]->r)+1;
}

int main() {
    int i;
    int n,q,u,v;
    char s[8];
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) {
        nodes[i] = new node;
        nodes[i]->l = nodes[i]->r = nodes[i]->p = NULL;
        nodes[i]->k = i,nodes[i]->s = 1,nodes[i]->f = 0,nodes[i]->c = -1;
    }
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        link(u,v);
    }
    for (i = 0; i < n; i++) evert(nodes[i]);
    for (i = 0; i < n; i++) cc += isRoot(nodes[i]);
    int c = 0;
    for (i = n-1; i >= 0; i--) {
        splay(nodes[i]);
        if (nodes[i]->c == -1) {
            nodes[i]->c = cc-(++c);
            update(nodes[i]->c,nodes[i]->s);
        }
    }
    yes = 1;
    for (i = 0; i < q; i++) {
        scanf("%s",s);
        if (s[0] == 'u') {
            scanf("%d",&u),u--;
            evert(nodes[u]);
        }
        else if (s[0] == 'w') {
            scanf("%d",&u),u--;
            printf("%d\n",when(u));
        }
        else {
            scanf("%d %d",&u,&v),u--,v--;
            printf("%d\n",(when(u) < when(v)) ? u+1:v+1);
        }
    }

    return 0;
}