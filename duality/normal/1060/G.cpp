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

int a[100000];
struct event { int x,k,i; };
bool comp(event a,event b) {
    if (a.x == b.x) return a.k < b.k;
    else return a.x < b.x;
}
vector<event> events;
LLI ans[100000];
struct node {
    node *l,*r;
    int p,k,s,c,lazy;
    LLI x,m;
};
node *root = NULL;
int size(node *n) {
    if (n != NULL) return n->s;
    else return 0;
}
LLI mm(node *n) {
    if (n != NULL) return n->m;
    else return 5e18;
}
int update(node *n) {
    if (n != NULL) {
        n->s = size(n->l) + size(n->r) + n->c;
        n->m = min(n->x,min(mm(n->l),mm(n->r)));
    }
    return 0;
}
int prop(node *n) {
    if (n != NULL) {
        n->x += n->lazy,n->m += n->lazy;
        if (n->l != NULL) n->l->lazy += n->lazy;
        if (n->r != NULL) n->r->lazy += n->lazy;
        n->lazy = 0;
    }
    return 0;
}
int split(node *n,node *&l,node *&r,int s) {
    prop(n);
    if (n == NULL) l = r = NULL;
    else if (s >= size(n->l)+n->c) prop(n->l),split(n->r,n->r,r,s-size(n->l)-n->c),l = n;
    else prop(n->r),split(n->l,l,n->l,s),r = n;
    update(l),update(r);
    return 0;
}
int merge(node *l,node *r,node *&n) {
    prop(l),prop(r);
    if (l == NULL) n = r;
    else if (r == NULL) n = l;
    else if (l->p > r->p) prop(l->l),merge(l->r,r,l->r),n = l;
    else prop(r->r),merge(l,r->l,r->l),n = r;
    if (n != NULL) prop(n->l),prop(n->r),assert(n->lazy == 0);
    update(n);
    return 0;
}
int main() {
    int i;
    int n,m,x,k;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),events.pb((event){a[i],-1,-1});
    for (i = 0; i < m; i++) {
        scanf("%d %d",&x,&k);
        if ((x < a[0]) || (k == 0)) ans[i] = x;
        else events.pb((event){x,k,i});
    }
    sort(events.begin(),events.end(),comp);

    int j,c = 0;
    for (i = 0; i < events.size(); i++) {
        if (i > 0) {
            int t = ((events[i].k == -1) ? events[i].x-1:events[i].x)-events[i-1].x;
            node *l,*r;
            int a = events[i-1].x;
            while (1) {
                split(root,l,r,t % c);
                if (mm(l) == 1) {
                    merge(l,r,root);
                    node *n = root;
                    int s = 0;
                    vector<node *> vv;
                    while (1) {
                        vv.pb(n),prop(n),prop(n->l),prop(n->r);
                        if (mm(n->l) == 1) n = n->l;
                        else if (mm(n->r) == 1) s += size(n->l)+n->c,n = n->r;
                        else {
                            s += size(n->l);
                            break;
                        }
                    }
                    ans[n->k] = a-c+(LLI) c*mm(n)+s;
                    node *n2;
                    merge(n->l,n->r,n2);
                    if (vv.size() == 1) root = n2;
                    else {
                        if (vv[vv.size()-2]->l == vv.back()) vv[vv.size()-2]->l = n2;
                        else vv[vv.size()-2]->r = n2;
                        for (j = vv.size()-2; j >= 0; j--) update(vv[j]);
                    }
                }
                else {
                    if (l != NULL) l->lazy--;
                    merge(r,l,root);
                    a += t % c,t -= t % c;
                    break;
                }
            }
            assert((t % c) == 0);
            while (mm(root) <= t/c) {
                node *n = root;
                int s = 0;
                vector<node *> vv;
                while (1) {
                    vv.pb(n),prop(n),prop(n->l),prop(n->r);
                    if (mm(n->l) == mm(n)) n = n->l;
                    else if (mm(n->r) == mm(n)) s += size(n->l)+n->c,n = n->r;
                    else {
                        s += size(n->l);
                        break;
                    }
                }
                ans[n->k] = a-c+(LLI) c*mm(n)+s;
                node *n2;
                merge(n->l,n->r,n2);
                if (vv.size() == 1) root = n2;
                else {
                    if (vv[vv.size()-2]->l == vv.back()) vv[vv.size()-2]->l = n2;
                    else vv[vv.size()-2]->r = n2;
                    for (j = vv.size()-2; j >= 0; j--) update(vv[j]);
                }
            }
            root->lazy -= t/c;
            prop(root);
        }
        if (events[i].k == -1) {
            node *n = new node;
            n->l = n->r = NULL,n->p = rand(),n->s = n->c = 1,n->lazy = 0;
            n->k = -1,n->x = n->m = 5e18,c++;
            merge(root,n,root);
        }
        else {
            node *n = new node;
            n->l = n->r = NULL,n->p = rand(),n->s = n->c = 0,n->lazy = 0;
            n->k = events[i].i,n->x = n->m = events[i].k;
            merge(root,n,root);
        }
    }
    int a = events.back().x;
    while (mm(root) < 2e18) {
        node *n = root;
        int s = 0;
        vector<node *> vv;
        while (1) {
            vv.pb(n),prop(n),prop(n->l),prop(n->r);
            if (mm(n->l) == mm(n)) n = n->l;
            else if (mm(n->r) == mm(n)) s += size(n->l)+n->c,n = n->r;
            else {
                s += size(n->l);
                break;
            }
        }
        ans[n->k] = a-c+(LLI) c*mm(n)+s;
        node *n2;
        merge(n->l,n->r,n2);
        if (vv.size() == 1) root = n2;
        else {
            if (vv[vv.size()-2]->l == vv.back()) vv[vv.size()-2]->l = n2;
            else vv[vv.size()-2]->r = n2;
            for (j = vv.size()-2; j >= 0; j--) update(vv[j]);
        }
    }
    for (i = 0; i < m; i++) printf("%I64d\n",ans[i]);

    return 0;
}