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
#define B 150
#pragma GCC optimize("Ofast")

int n;
int p[200000];
vi adjList[200000];
int a[200000],b[200000];
int A[200000],m[200000];
int disc[200000],fin[200000],inv[200000],num = 0;
int doDFS(int u,int aa,int bb) {
    int i;
    A[num] = aa,m[num] = abs(bb);
    disc[u] = num++,inv[num-1] = u;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        doDFS(v,aa+a[v],bb+b[v]);
    }
    fin[u] = num;
    return 0;
}
int toAdd[200000];
LLI val[200000];
struct line { LLI m,b; };
LLI eval(line l,int x) {
    return l.m*x+l.b;
}
int bad(line a,line b,line c) {
    return (long double) (c.b-b.b)*(a.m-b.m) <= (long double) (b.b-a.b)*(b.m-c.m);
}
vi order[200000];
bool comp(int a,int b) {
    if (m[a] == m[b]) return a < b;
    else return m[a] > m[b];
}
line hull[200000/B+5][2*B+5];
int len[200000],pos[200000];
int rebuild(int b) {
    int i;
    len[b] = 0;
    for (i = 0; i < order[b].size(); i++) {
        int u = order[b][i];
        A[u] += toAdd[b];
        line l = (line){-m[u],(LLI) -m[u]*A[u]};
        if ((len[b] >= 1) && (hull[b][len[b]-1].m == l.m) && (hull[b][len[b]-1].b >= l.b)) continue;
        while ((len[b] >= 1) && (hull[b][len[b]-1].m == l.m)) len[b]--;
        while ((len[b] >= 2) && bad(hull[b][len[b]-2],hull[b][len[b]-1],l)) len[b]--;
        hull[b][len[b]++] = l;
    }
    for (i = order[b].size()-1; i >= 0; i--) {
        int u = order[b][i];
        line l = (line){m[u],(LLI) m[u]*A[u]};
        if ((len[b] >= 1) && (hull[b][len[b]-1].m == l.m) && (hull[b][len[b]-1].b >= l.b)) continue;
        while ((len[b] >= 1) && (hull[b][len[b]-1].m == l.m)) len[b]--;
        while ((len[b] >= 2) && bad(hull[b][len[b]-2],hull[b][len[b]-1],l)) len[b]--;
        hull[b][len[b]++] = l;
    }
    toAdd[b] = pos[b] = 0;
    return 0;
}
int recalc(int b) {
    while ((pos[b] <= len[b]-2) && (eval(hull[b][pos[b]],toAdd[b]) \
        <= eval(hull[b][pos[b]+1],toAdd[b]))) pos[b]++;
    val[b] = eval(hull[b][pos[b]],toAdd[b]);
    return 0;
}
int main() {
    int i,j;
    int q;
    int t,v,x;
    scanf("%d %d",&n,&q);
    for (i = 1; i < n; i++) scanf("%d",&p[i]),adjList[--p[i]].pb(i);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    for (i = 0; i < n; i++) scanf("%d",&b[i]);
    doDFS(0,a[0],b[0]);
    for (i = 0; i < (n+B-1)/B; i++) {
        for (j = i*B; j < min((i+1)*B,n); j++) order[i].pb(j);
        sort(order[i].begin(),order[i].end(),comp);
        rebuild(i),recalc(i);
    }
    for (i = 0; i < q; i++) {
        scanf("%d",&t);
        if (t == 1) {
            scanf("%d %d",&v,&x),v--;
            int l = disc[v],r = fin[v]-1;
            if (l/B == r/B) {
                for (j = l; j <= r; j++) A[j] += x;
                rebuild(l/B);
            }
            else {
                for (j = l; j < (l/B+1)*B; j++) A[j] += x;
                rebuild(l/B);
                for (j = (r/B)*B; j <= r; j++) A[j] += x;
                rebuild(r/B);
                for (j = l/B+1; j < r/B; j++) toAdd[j] += x;
            }
            for (j = l/B; j <= r/B; j++) recalc(j);
        }
        else {
            scanf("%d",&v),v--;
            int l = disc[v],r = fin[v]-1;
            LLI ans = 0;
            if (l/B == r/B) {
                for (j = l; j <= r; j++) ans = max(ans,(LLI) m[j]*abs(A[j]+toAdd[l/B]));
            }
            else {
                for (j = l; j < (l/B+1)*B; j++) ans = max(ans,(LLI) m[j]*abs(A[j]+toAdd[l/B]));
                for (j = (r/B)*B; j <= r; j++) ans = max(ans,(LLI) m[j]*abs(A[j]+toAdd[r/B]));
                for (j = l/B+1; j < r/B; j++) ans = max(ans,val[j]);
            }
            printf("%I64d\n",ans);
        }
    }

    return 0;
}