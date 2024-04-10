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

int n,pos[200001];
struct node {
    node *l,*r;
    LLI lazy,lazy2;
};
node *root[200001];
int build(int s,int e,node *n) {
    if (s == e) {
        n->l = n->r = NULL;
        n->lazy = -1,n->lazy2 = 1;
        return 0;
    }

    int mid = (s+e) / 2;
    n->l = new node,n->r = new node;
    build(s,mid,n->l),build(mid+1,e,n->r);
    n->lazy = n->lazy2 = 0;
    return 0;
}
plli query(int s,int e,int q,node *n) {
    if (s == e) return mp(n->lazy,n->lazy2);

    int mid = (s+e) / 2;
    plli p;
    if (q <= mid) p = query(s,mid,q,n->l);
    else p = query(mid+1,e,q,n->r);
    return mp(p.first+n->lazy,p.second+n->lazy2);
}
int update(int s,int e,int as,int ae,node *o,node *n,int x,int t) {
    if ((s >= as) && (e <= ae)) {
        n->l = o->l,n->r = o->r;
        n->lazy = o->lazy+x,n->lazy2 = o->lazy2+(LLI) x*t;
        return 0;
    }

    int mid = (s+e) / 2;
    if (ae <= mid) {
        n->r = o->r,n->l = new node;
        update(s,mid,as,ae,o->l,n->l,x,t);
    }
    else if (as > mid) {
        n->l = o->l,n->r = new node;
        update(mid+1,e,as,ae,o->r,n->r,x,t);
    }
    else {
        n->l = new node,n->r = new node;
        update(s,mid,as,ae,o->l,n->l,x,t);
        update(mid+1,e,as,ae,o->r,n->r,x,t);
    }
    n->lazy = o->lazy,n->lazy2 = o->lazy2;
    return 0;
}
int tree[1 << 19];
int build2(int s,int e,int i) {
    if (s == e) {
        tree[i] = -1;
        return 0;
    }

    int mid = (s+e) / 2;
    build2(s,mid,2*i+1),build2(mid+1,e,2*i+2);
    tree[i] = -1;
    return 0;
}
int query2(int s,int e,int qs,int qe,int i) {
    if ((s > qe) || (e < qs)) return 1e9;
    else if ((s >= qs) && (e <= qe)) return tree[i];

    int mid = (s+e) / 2;
    return min(query2(s,mid,qs,qe,2*i+1),query2(mid+1,e,qs,qe,2*i+2));
}
int update2(int s,int e,int ai,int i,int num) {
    if ((s > ai) || (e < ai)) return 0;
    else if (s == e) {
        tree[i] = num;
        return 0;
    }

    int mid = (s+e) / 2;
    update2(s,mid,ai,2*i+1,num),update2(mid+1,e,ai,2*i+2,num);
    tree[i] = min(tree[2*i+1],tree[2*i+2]);
    return 0;
}
int update3(int s,int e,int as,int ae,int i,int ol,int nl,int t) {
    if ((s > ae) || (e < as)) return 0;
    else if (ol == nl) return 0;
    else if ((s >= as) && (e <= ae)) {
        if (s == e) {
            nl = min(nl,tree[i]),ol = min(ol,tree[i]);
            if (nl > ol) {
                node *r2 = new node;
                update(0,n,s,e,root[t+1],r2,nl-ol,t);
                root[t+1] = r2;
            }
            return 0;
        }
        else if (nl <= tree[i]) {
            node *r2 = new node;
            update(0,n,s,e,root[t+1],r2,nl-ol,t);
            root[t+1] = r2;
            return 0;
        }
    }

    int mid = (s+e) / 2;
    update3(s,mid,as,ae,2*i+1,ol,nl,t);
    update3(mid+1,e,as,ae,2*i+2,min(ol,tree[2*i+1]),min(nl,tree[2*i+1]),t);
    return 0;
}
LLI getAns(int l,int r,int k) {
    if (k == -1) return (LLI) (r-l+1)*(r-l+2)/2;
    int s = 0,e = r+1;
    while (s < e) {
        int m = (s+e) / 2;

        plli p = query(0,n,k,root[m+1]);
        if (p.first < l) s = m+1;
        else e = m;
    }
    if (s > r) return 0;
    else {
        plli p = query(0,n,k,root[r+1]);
        plli p2 = query(0,n,k,root[s]);
        return (p.first*(r+1)-p.second)-(p2.first*s-p2.second)-(LLI) (r-s+1)*(l-1);
    }
}
int main() {
    int i;
    int a,l,r,k;
    LLI lans = 0;
    scanf("%d",&n);
    for (i = 0; i <= n; i++) pos[i] = -1;
    root[0] = new node;
    build(0,n,root[0]),build2(0,n,0);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d %d",&a,&l,&r,&k);
        a = (a+lans) % (n+1);
        l = (l+lans) % (i+1);
        r = (r+lans) % (i+1);
        if (l > r) swap(l,r);
        k = (k+lans) % (n+1);

        int q = query2(0,n,0,a,0);
        if (q != pos[a]) pos[a] = i,update2(0,n,a,0,i),root[i+1] = root[i];
        else {
            pos[a] = i,update2(0,n,a,0,i);
            int q2 = query2(0,n,0,a,0);
            root[i+1] = root[i];
            update3(0,n,a,n,0,q,q2,i);
        }

        lans = getAns(l,r,k-1)-getAns(l,r,k);
        printf("%I64d\n",lans);
    }

    return 0;
}