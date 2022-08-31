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

int a[150000],pos[150000];
int l[150000],r[150000];
vpii tree[1 << 19];
int update(int s,int e,int as,int ae,int i,pii p) {
    if ((s > ae) || (e < as)) return 0;
    else if ((s >= as) && (e <= ae)) {
        tree[i].pb(p);
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1,p),update(mid+1,e,as,ae,2*i+2,p);
    return 0;
}
vpii cand;
int query(int s,int e,int q,int i) {
    if ((s > q) || (e < q)) return 0;
    else if (s == e) {
        while (!tree[i].empty()) cand.pb(tree[i].back()),tree[i].pop_back();
        return 0;
    }

    int mid = (s+e) / 2;
    query(s,mid,q,2*i+1),query(mid+1,e,q,2*i+2);
    while (!tree[i].empty()) cand.pb(tree[i].back()),tree[i].pop_back();
    return 0;
}

LLI ans = 1;
struct node {
    node *l,*r,*p;
    int k,s,size,vir;
};
node *nodes[150000];
int size(node *r) {
    if (r == NULL) return 0;
    else return r->s;
}
int ssize(node *r) {
    if (r == NULL) return 0;
    else return r->size;
}
int update(node *r) {
    if (r != NULL) {
        r->s = size(r->l)+size(r->r)+1;
        r->size = ssize(r->l)+ssize(r->r)+r->vir+1;
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
            if (n == n->p->l) rotR(n->p);
            else rotL(n->p);
        }
        else if ((n->p->l == n) && (n->p->p->l == n->p)) rotR(n->p->p),rotR(n->p);
        else if ((n->p->r == n) && (n->p->p->r == n->p)) rotL(n->p->p),rotL(n->p);
        else if ((n->p->l == n) && (n->p->p->r == n->p)) rotR(n->p),rotL(n->p);
        else rotL(n->p),rotR(n->p);
    }
    return 0;
}
int access(node *n) {
    node *p = NULL,*o = n;
    while (n != NULL) {
        splay(n);
        n->vir -= ssize(p),n->vir += ssize(n->r);
        n->r = p,update(n),p = n,n = n->p;
    }
    splay(o);
    //for (splay(n),n->r = NULL,update(n); n->p != NULL; splay(n)) splay(n->p),n->p->r = n;
    return 0;
}
int find(int k) {
    node *n = nodes[k];
    access(n);
    while (n->l != NULL) n = n->l;
    splay(n);
    return n->k;
}
int depth(int k) {
    access(nodes[k]);
    return nodes[k]->s-1;
}
int getSize(int a) {
    if (a == -1) return 0;
    else return getSize(l[a])+getSize(r[a])+1;
}
int link(int a,int b) {
    access(nodes[a]);
    ans += (LLI) (depth(b)+1)*nodes[a]->size;
    nodes[a]->p = nodes[b],nodes[b]->vir += nodes[a]->size;
    access(nodes[a]);
    return 0;
}
int cut(int k) {
    node *n = nodes[k];
    access(n);
    int d = n->s-1;
    n->l->p = NULL;
    n->l = NULL;
    update(n);
    ans -= (LLI) d*n->size;
    return 0;
}
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),pos[--a[i]] = i;

    int j;
    for (i = 0; i < n; i++) {
        l[i] = r[i] = -1;
        nodes[i] = new node;
        nodes[i]->l = nodes[i]->r = nodes[i]->p = NULL;
        nodes[i]->k = i,nodes[i]->s = 1,nodes[i]->size = 1,nodes[i]->vir = 0;
    }
    printf("1\n");
    int sum = 0;
    for (i = 1; i < n; i++) {
        cand.clear(),query(0,n-1,pos[i],0);
        vi L,R;
        for (j = 0; j < cand.size(); j++) {
            if (cand[j].second > cand[j].first) {
                if (r[cand[j].first] == cand[j].second) {
                    cut(cand[j].second),r[cand[j].first] = -1;
                    L.pb(cand[j].first),R.pb(cand[j].second);
                }
            }
            else {
                if (l[cand[j].first] == cand[j].second) {
                    cut(cand[j].second),l[cand[j].first] = -1;
                    R.pb(cand[j].first),L.pb(cand[j].second);
                }
            }
        }
        sum += L.size()+R.size();
        sort(L.begin(),L.end()),sort(R.begin(),R.end(),greater<int>());
        for (j = (pos[i-1] < pos[i]) ? 0:1; j+1 < L.size(); j += 2) {
            r[L[j]] = (L[j] == L[j+1]) ? -1:L[j+1];
            if (r[L[j]] != -1) {
                link(r[L[j]],L[j]);
                update(0,n-1,L[j],r[L[j]],0,mp(L[j],r[L[j]]));
            }
        }
        for (j = (pos[i-1] > pos[i]) ? 0:1; j+1 < R.size(); j += 2) {
            l[R[j]] = (R[j] == R[j+1]) ? -1:R[j+1];
            if (l[R[j]] != -1) {
                link(l[R[j]],R[j]);
                update(0,n-1,l[R[j]],R[j],0,mp(R[j],l[R[j]]));
            }
        }
        int ll = -1,rr = -1;
        if (pos[i-1] < pos[i]) ll = pos[i-1],rr = R.empty() ? -1:R[0];
        else rr = pos[i-1],ll = L.empty() ? -1:L[0];
        l[pos[i]] = ll,r[pos[i]] = rr;
        if (ll != -1) {
            link(ll,pos[i]);
            update(0,n-1,ll,pos[i],0,mp(pos[i],ll));
        }
        if (rr != -1) {
            link(rr,pos[i]);
            update(0,n-1,pos[i],rr,0,mp(pos[i],rr));
        }
        ans++;

        printf("%I64d\n",ans);
    }

    return 0;
}