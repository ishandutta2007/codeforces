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

pii parent[400005];
pii find(int n) {
    if (parent[n].first != n) {
        pii p = find(parent[n].first);
        parent[n] = mp(p.first,p.second^parent[n].second);
    }
    return parent[n];
}
map<int,int> M;
int num = 1;
int merge(int a,int b,int x) {
    pii p = find(a),q = find(b);
    if (p.first == q.first) return 0;
    parent[p.first] = mp(q.first,x^p.second^q.second);
    return 0;
}
int main() {
    int i;
    int q,t,l,r,x,last = 0;
    scanf("%d",&q);
    for (i = 0; i < 400005; i++) parent[i] = mp(i,0);
    M[0] = 0;
    for (i = 0; i < q; i++) {
        scanf("%d",&t);
        if (t == 1) {
            scanf("%d %d %d",&l,&r,&x);
            l ^= last,r ^= last,x ^= last;
            if (l > r) swap(l,r);
            if (!M.count(l)) M[l] = num++;
            if (!M.count(r+1)) M[r+1] = num++;
            merge(M[l],M[r+1],x);
        }
        else {
            scanf("%d %d",&l,&r);
            l ^= last,r ^= last;
            if (l > r) swap(l,r);
            if (!M.count(l)) M[l] = num++;
            if (!M.count(r+1)) M[r+1] = num++;
            if (find(M[l]).first == find(M[r+1]).first) {
                int a = find(M[l]).second^find(M[r+1]).second;
                printf("%d\n",a),last = a;
            }
            else printf("-1\n"),last = 1;
        }
    }

    return 0;
}