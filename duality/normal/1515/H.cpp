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
    node *l,*r;
    int z,f,s;
    int a,b;
    node() { l = r = NULL,z = f = a = b = 0,s = 1; }
};
int c = 0;
node mem[1 << 22];
node *all = NULL;
node *newNode() {
    if (all != NULL) {
        node *t = all;
        all = all->l;
        t->l = t->r = NULL,t->z = t->f = t->a = t->b = 0,t->s = 1;
        return t;
    }
    else return &mem[c++];
}
int delNode(node *n) {
    n->l = all,all = n;
    return 0;
}

node *root = NULL;
int size(node *n) {
    if (n != NULL) return n->s;
    else return 0;
}
int update(node *n,int d) {
    if (n != NULL) {
        n->s = size(n->l) + size(n->r);
        if (n->s == 0) n->s = 1;
        n->a = ((n->l == NULL) ? 0:n->l->a|(1 << d)) | ((n->r == NULL) ? 0:n->r->a);
        n->b = ((n->r == NULL) ? 0:n->r->b|(1 << d)) | ((n->l == NULL) ? 0:n->l->b);
    }
    return 0;
}
int prop(node *n,int d);
int merge2(node *l,node *r,node *&n,int d) {
    prop(l,d),prop(r,d);
    if (l == NULL) n = r;
    else if (r == NULL) n = l;
    else {
        if (n == NULL) n = newNode();
        merge2(l->l,r->l,n->l,d-1);
        merge2(l->r,r->r,n->r,d-1);
        delNode(l);
        delNode(r);
    }
    update(n,d);
    return 0;
}
int merge(node *l,node *r,node *&n,int d) {
    node *t = NULL;
    merge2(l,r,t,d);
    n = t;
    return 0;
}
int prop(node *n,int d) {
    if (n != NULL) {
        if (n->l != NULL) {
            n->l->f &= ~n->z;
            n->l->z |= n->z;
            n->l->f ^= n->f;
        }
        if (n->r != NULL) {
            n->r->f &= ~n->z;
            n->r->z |= n->z;
            n->r->f ^= n->f;
        }
        if (d >= 0) {
            if (n->z & (1 << d)) merge(n->l,n->r,n->l,d-1),n->r = NULL;
            if (n->f & (1 << d)) swap(n->l,n->r);
        }
        if ((n->a & n->b & n->z) & ((1 << (d+1))-1)) prop(n->l,d-1),prop(n->r,d-1);
        n->z = n->f = 0;
        update(n,d);
    }
    return 0;
}
int split(node *n,node *&l,node *&r,int s,int d) {
    prop(n,d);
    if (n == NULL) l = r = NULL;
    else if (d < 0) l = n,r = NULL;
    else if (s & (1 << d)) {
        split(n->r,n->r,r,s,d-1);
        if ((n->l == NULL) && (n->r == NULL)) {
            delNode(n);
            l = NULL;
        }
        else l = n;
        if (r != NULL) {
            node *t = newNode();
            t->r = r,r = t;
        }
    }
    else {
        split(n->l,l,n->l,s,d-1);
        if ((n->l == NULL) && (n->r == NULL)) {
            delNode(n);
            r = NULL;
        }
        else r = n;
        if (l != NULL) {
            node *t = newNode();
            t->l = l,l = t;
        }
    }
    update(l,d),update(r,d);
    return 0;
}
int main() {
    int i,j;
    int n,q,a;
    int t,l,r,x;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) {
        scanf("%d",&a);
        node *n = newNode(),*r = n;
        for (j = 19; j >= 0; j--) {
            if (a & (1 << j)) n->r = newNode(),n = n->r;
            else n->l = newNode(),n = n->l;
        }
        merge(root,r,root,19);
    }
    for (i = 0; i < q; i++) {
        scanf("%d",&t);
        if (t == 1) {
            scanf("%d %d %d",&l,&r,&x);
            node *L,*M,*R;
            if (l > 0) split(root,L,M,l-1,19);
            else L = NULL,M = root;
            split(M,M,R,r,19);
            if (M != NULL) M->z = ~x,M->f = 0;
            merge(L,M,M,19);
            merge(M,R,root,19);
        }
        else if (t == 2) {
            scanf("%d %d %d",&l,&r,&x);
            if (l > r) swap(l,r);
            node *L,*M,*R;
            if (l > 0) split(root,L,M,l-1,19);
            else L = NULL,M = root;
            split(M,M,R,r,19);
            if (M != NULL) M->z = x,M->f = x;
            merge(L,M,M,19);
            merge(M,R,root,19);
        }
        else if (t == 3) {
            scanf("%d %d %d",&l,&r,&x);
            node *L,*M,*R;
            if (l > 0) split(root,L,M,l-1,19);
            else L = NULL,M = root;
            split(M,M,R,r,19);
            if (M != NULL) M->z = 0,M->f = x;
            merge(L,M,M,19);
            merge(M,R,root,19);
        }
        else {
            scanf("%d %d",&l,&r);
            if (l > r) swap(l,r);
            node *L,*M,*R;
            if (l > 0) split(root,L,M,l-1,19);
            else L = NULL,M = root;
            split(M,M,R,r,19);
            printf("%d\n",size(M));
            merge(L,M,M,19);
            merge(M,R,root,19);
        }
    }

    return 0;
}