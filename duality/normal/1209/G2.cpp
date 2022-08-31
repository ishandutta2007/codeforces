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

int a[200000];
struct node { int max,lmax,rmax,smax,min; };
node tree[1 << 19];
int lazy[1 << 19];
node com(node a,node b) {
    node c;
    c.max = max(a.max,b.max),c.min = min(a.min,b.min);
    c.lmax = (c.min == a.min) ? a.lmax:max(a.max,b.lmax);
    c.rmax = (c.min == b.min) ? b.rmax:max(b.max,a.rmax);
    if ((c.min == a.min) && (c.min == b.min)) c.smax = a.smax+b.smax-min(a.rmax,b.lmax);
    else if (c.min == a.min) c.smax = a.smax+b.max-min(a.rmax,b.max);
    else c.smax = b.smax+a.max-min(b.lmax,a.max);
    return c;
}
int prop(int s,int e,int i) {
    tree[i].min += lazy[i];
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
    tree[i] = com(tree[2*i+1],tree[2*i+2]);
    return 0;
}
int update2(int s,int e,int ai,int i,int num) {
    prop(s,e,i);
    if ((s > ai) || (e < ai-1)) return 0;
    else if (s == e) {
        if (s == ai) tree[i].lmax = num;
        else tree[i].rmax = num;
        tree[i].max = max(tree[i].lmax,tree[i].rmax),tree[i].smax = tree[i].lmax+tree[i].rmax;
        return 0;
    }

    int mid = (s+e) / 2;
    update2(s,mid,ai,2*i+1,num),update2(mid+1,e,ai,2*i+2,num);
    tree[i] = com(tree[2*i+1],tree[2*i+2]);
    return 0;
}
set<int> pos[200001];
int main() {
    int i;
    int n,q,p,x;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),pos[a[i]].insert(i);
    if (n == 1) {
        for (i = 0; i <= q; i++) printf("1\n");
        return 0;
    }
    for (i = 1; i <= 200000; i++) {
        if (!pos[i].empty()) {
            update2(0,n-2,*pos[i].begin(),0,pos[i].size());
            if (pos[i].size() >= 2) update(0,n-2,*pos[i].begin(),*(--pos[i].end())-1,0,1);
        }
    }
    prop(0,n-2,0);
    printf("%d\n",n-((tree[0].min == 0) ? tree[0].smax:tree[0].max));
    for (i = 0; i < q; i++) {
        scanf("%d %d",&p,&x),p--;
        update2(0,n-2,*pos[a[p]].begin(),0,0);
        if (pos[a[p]].size() >= 2) update(0,n-2,*pos[a[p]].begin(),*(--pos[a[p]].end())-1,0,-1);
        pos[a[p]].erase(p);
        if (!pos[a[p]].empty()) {
            update2(0,n-2,*pos[a[p]].begin(),0,pos[a[p]].size());
            if (pos[a[p]].size() >= 2) update(0,n-2,*pos[a[p]].begin(),*(--pos[a[p]].end())-1,0,1);
        }
        a[p] = x;
        if (!pos[a[p]].empty()) {
            update2(0,n-2,*pos[a[p]].begin(),0,0);
            if (pos[a[p]].size() >= 2) update(0,n-2,*pos[a[p]].begin(),*(--pos[a[p]].end())-1,0,-1);
        }
        pos[a[p]].insert(p);
        update2(0,n-2,*pos[a[p]].begin(),0,pos[a[p]].size());
        if (pos[a[p]].size() >= 2) update(0,n-2,*pos[a[p]].begin(),*(--pos[a[p]].end())-1,0,1);
        prop(0,n-2,0);
        printf("%d\n",n-((tree[0].min == 0) ? tree[0].smax:tree[0].max));
    }

    return 0;
}