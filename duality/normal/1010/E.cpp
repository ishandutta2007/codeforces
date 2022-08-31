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

struct event { int x,ly,ry,lz,rz,t,i; };
bool comp(event a,event b) {
    if (a.x == b.x) return a.t > b.t;
    else return a.x < b.x;
}
int cx[100000],cy[100000],cz[100000];
int ans[100000];
struct node {
    node *l,*r;
    int sum;
};
int update(int s,int e,int ai,node *n,int num) {
    if (s == e) {
        n->sum += num;
        return 0;
    }

    int mid = (s+e) / 2;
    if (ai <= mid) {
        if (n->l == NULL) n->l = new node,n->l->l = n->l->r = NULL,n->l->sum = 0;
        update(s,mid,ai,n->l,num);
    }
    else {
        if (n->r == NULL) n->r = new node,n->r->l = n->r->r = NULL,n->r->sum = 0;
        update(mid+1,e,ai,n->r,num);
    }
    n->sum = ((n->l == NULL) ? 0:n->l->sum)+((n->r == NULL) ? 0:n->r->sum);
    return 0;
}
int query(int s,int e,int qs,int qe,node *n) {
    if (n == NULL) return 0;
    else if ((s > qe) || (e < qs)) return 0;
    else if ((s >= qs) && (e <= qe)) return n->sum;

    int mid = (s+e) / 2;
    return query(s,mid,qs,qe,n->l)+query(mid+1,e,qs,qe,n->r);
}
node *bit[100001];
vector<event> events;
int main() {
    int i;
    int n,m,k;
    int x,y,z;
    int lx,rx,ly,ry,lz,rz;
    scanf("%*d %*d %*d %d %d %d",&n,&m,&k);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d",&x,&y,&z);
        if (i == 0) lx = rx = x,ly = ry = y,lz = rz = z;
        else {
            lx = min(lx,x),rx = max(rx,x);
            ly = min(ly,y),ry = max(ry,y);
            lz = min(lz,z),rz = max(rz,z);
        }
    }
    for (i = 0; i < m; i++) {
        scanf("%d %d %d",&x,&y,&z);
        if ((x >= lx) && (x <= rx) && (y >= ly) && (y <= ry) && (z >= lz) && (z <= rz)) {
            printf("INCORRECT\n");
            return 0;
        }
        else {
            cx[i] = x,cy[i] = y,cz[i] = z;
            events.pb((event){x,y,y,z,z,0,-1});
        }
    }
    for (i = 0; i < k; i++) {
        scanf("%d %d %d",&x,&y,&z);
        if ((x >= lx) && (x <= rx) && (y >= ly) && (y <= ry) && (z >= lz) && (z <= rz)) ans[i] = -1;
        else {
            events.pb((event){min(x,lx),min(y,ly),max(y,ry),min(z,lz),max(z,rz),1,i});
            events.pb((event){max(x,rx),min(y,ly),max(y,ry),min(z,lz),max(z,rz),-1,i});
        }
    }

    int j;
    sort(events.begin(),events.end(),comp);
    for (i = 1; i <= 100000; i++) bit[i] = new node,bit[i]->l = bit[i]->r = NULL,bit[i]->sum = 0;
    for (i = 0; i < events.size(); i++) {
        if (events[i].t == 0) {
            for (j = events[i].ly; j <= 100000; j += j & (-j)) update(1,100000,events[i].lz,bit[j],1);
        }
        else {
            for (j = events[i].ry; j > 0; j -= j & (-j)) ans[events[i].i] -= events[i].t*query(1,100000,events[i].lz,events[i].rz,bit[j]);
            for (j = events[i].ly-1; j > 0; j -= j & (-j)) ans[events[i].i] += events[i].t*query(1,100000,events[i].lz,events[i].rz,bit[j]);
        }
    }
    printf("CORRECT\n");
    for (i = 0; i < k; i++) {
        if (ans[i] == -1) printf("OPEN\n");
        else if (ans[i] == 0) printf("UNKNOWN\n");
        else printf("CLOSED\n");
    }

    return 0;
}