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

char s[200001],f[200001];
int l[200000],r[200000];
int tree[1 << 19];
int lazy[1 << 19];
int build(int s,int e,int i) {
    if (s == e) {
        tree[i] = f[s]-'0',lazy[i] = -1;
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    tree[i] = tree[2*i+1] + tree[2*i+2],lazy[i] = -1;
    return 0;
}
int prop(int s,int e,int i) {
    if (lazy[i] != -1) {
        tree[i] = lazy[i] ? e-s+1:0;
        if (s != e) lazy[2*i+1] = lazy[2*i+2] = lazy[i];
        lazy[i] = -1;
    }
    return 0;
}
int update(int s,int e,int as,int ae,int i,int num) {
    prop(s,e,i);
    if ((s > ae) || (e < as)) return 0;
    else if ((s >= as) && (e <= ae)) {
        lazy[i] = num;
        prop(s,e,i);
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1,num),update(mid+1,e,as,ae,2*i+2,num);
    tree[i] = tree[2*i+1] + tree[2*i+2];
    return 0;
}
int query(int s,int e,int qs,int qe,int i) {
    prop(s,e,i);
    if ((s > qe) || (e < qs)) return 0;
    else if ((s >= qs) && (e <= qe)) return tree[i];

    int mid = (s+e) / 2;
    return query(s,mid,qs,qe,2*i+1) + query(mid+1,e,qs,qe,2*i+2);
}
int main() {
    int i;
    int t,n,q;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&q);
        scanf("%s %s",s,f);
        for (i = 0; i < q; i++) scanf("%d %d",&l[i],&r[i]),l[i]--,r[i]--;

        build(0,n-1,0);
        for (i = q-1; i >= 0; i--) {
            int x = query(0,n-1,l[i],r[i],0);
            if (2*x < r[i]-l[i]+1) update(0,n-1,l[i],r[i],0,0);
            else if (2*x > r[i]-l[i]+1) update(0,n-1,l[i],r[i],0,1);
            else break;
        }
        if (i < 0) {
            for (i = 0; i < n; i++) {
                if (query(0,n-1,i,i,0) != s[i]-'0') break;
            }
            if (i == n) printf("YES\n");
            else printf("NO\n");
        }
        else printf("NO\n");
    }

    return 0;
}