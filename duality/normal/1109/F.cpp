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

int n,m;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int f[1000][1000],rr[200000],cc[200000];

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
            if (!conn(a,b)) return -1;
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
link_cut lct(200000);

int L[200000];
int tree[1 << 19],lazy[1 << 19],times[1 << 19];
int build(int s,int e,int i) {
    if (s == e) {
        times[i] = 1;
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    times[i] = 1;
    return 0;
}
int prop(int s,int e,int i) {
    tree[i] += lazy[i];
    if (s != e) lazy[2*i+1] += lazy[i],lazy[2*i+2] += lazy[i];
    lazy[i] = 0;
    return 0;
}
int update(int s,int e,int as,int ae,int i,int num) {
    prop(s,e,i);
    if ((s > ae) || (e < as)) return 0;
    else if ((s >= as) && (e <= ae)) {
        lazy[i] += num;
        prop(s,e,i);
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1,num),update(mid+1,e,as,ae,2*i+2,num);
    tree[i] = min(tree[2*i+1],tree[2*i+2]),times[i] = 0;
    if (tree[i] == tree[2*i+1]) times[i] += times[2*i+1];
    if (tree[i] == tree[2*i+2]) times[i] += times[2*i+2];
    return 0;
}
int mm,t;
int query(int s,int e,int qs,int qe,int i) {
    prop(s,e,i);
    if ((s > qe) || (e < qs)) return 0;
    else if ((s >= qs) && (e <= qe)) {
        int nm = min(mm,tree[i]),nt = 0;
        if (nm == mm) nt += t;
        if (nm == tree[i]) nt += times[i];
        mm = nm,t = nt;
        return 0;
    }

    int mid = (s+e) / 2;
    query(s,mid,qs,qe,2*i+1),query(mid+1,e,qs,qe,2*i+2);
    return 0;
}
int main() {
    int i,j;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) scanf("%d",&f[i][j]),f[i][j]--,rr[f[i][j]] = i,cc[f[i][j]] = j;
    }

    LLI ans = 0;
    int l = 0;
    for (i = 0; i < n*m; i++) {
        while (1) {
            for (j = 0; j < 4; j++) {
                int x = cc[i]+dx[j],y = rr[i]+dy[j];
                if ((x >= 0) && (x < m) && (y >= 0) && (y < n) && (f[y][x] >= l) && (f[y][x] < i)) {
                    if (lct.conn(f[y][x],i)) break;
                    else lct.link(f[y][x],i);
                }
            }
            if (j < 4) {
                for (j--; j >= 0; j--) {
                    int x = cc[i]+dx[j],y = rr[i]+dy[j];
                    if ((x >= 0) && (x < m) && (y >= 0) && (y < n) && (f[y][x] >= l) && (f[y][x] < i)) lct.cut(f[y][x],i);
                }
                for (j = 0; j < 4; j++) {
                    int x = cc[l]+dx[j],y = rr[l]+dy[j];
                    if ((x >= 0) && (x < m) && (y >= 0) && (y < n) && (f[y][x] > l) && (f[y][x] < i)) lct.cut(f[y][x],l);
                }
                l++;
            }
            else break;
        }
        L[i] = l;
    }
    build(0,n*m-1,0);
    for (i = 0; i < n*m; i++) {
        update(0,n*m-1,0,i,0,1);
        for (j = 0; j < 4; j++) {
            int x = cc[i]+dx[j],y = rr[i]+dy[j];
            if ((x >= 0) && (x < m) && (y >= 0) && (y < n) && (f[y][x] < i)) update(0,n*m-1,0,f[y][x],0,-1);
        }
        mm = 1e9,t = 1;
        query(0,n*m-1,L[i],i,0);
        ans += t;
    }
    printf("%I64d\n",ans);

    return 0;
}