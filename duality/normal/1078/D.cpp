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

int n;
int a[300000];
int tree[19][1 << 20],tree2[19][1 << 20];
int arr[300000],arr2[300000];
int build(int s,int e,int i,int *tree,int *arr) {
    for (i = 0; i < 3*n; i++) tree[i+3*n] = arr[i];
    for (i = 3*n-1; i > 0; i--) tree[i] = max(tree[i << 1],tree[(i << 1) | 1]);
    return 0;
}
int query(int s,int e,int qs,int qe,int i,int *tree) {
    int ans = -1e9;
    qs += 3*n,qe += 3*n+1;
    while (qs < qe) {
        if (qs & 1) ans = max(ans,tree[qs++]);
        if (qe & 1) ans = max(ans,tree[--qe]);
        qs >>= 1,qe >>= 1;
    }
    return ans;
}
int ans[100000];
int main() {
    int i;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),a[i+n] = a[i+2*n] = a[i];
    if (n == 1) {
        printf("0\n");
        return 0;
    }

    int j;
    for (i = 0; i < 3*n; i++) arr[i] = -max(i-a[i],0),arr2[i] = min(i+a[i],3*n-1);
    build(0,3*n-1,0,tree[0],arr),build(0,3*n-1,0,tree2[0],arr2);
    for (i = 1; (1 << i) < 3*n; i++) {
        for (j = 0; j < 3*n; j++) {
            int ll = -arr[j],rr = arr2[j];
            arr[j] = query(0,3*n-1,ll,rr,0,tree[i-1]);
            arr2[j] = query(0,3*n-1,ll,rr,0,tree2[i-1]);
        }
        build(0,3*n-1,0,tree[i],arr),build(0,3*n-1,0,tree2[i],arr2);
    }
    int logn = i,p = -1;
    for (i = n; i < 2*n; i++) {
        int l = i,r = i,c = 0;
        if (p == -1) {
            for (j = logn-1; j >= 0; j--) {
                int ll = -query(0,3*n-1,l,r,0,tree[j]),rr = query(0,3*n-1,l,r,0,tree2[j]);
                if (rr-ll+1 < n) c |= (1 << j),l = ll,r = rr;
            }
            c++;
        }
        else {
            p = max(p-1,0);
            for (j = logn-1; j >= 0; j--) {
                if (p & (1 << j)) {
                    int ll = -query(0,3*n-1,l,r,0,tree[j]),rr = query(0,3*n-1,l,r,0,tree2[j]);
                    c |= (1 << j),l = ll,r = rr;
                }
            }
            if (r-l+1 < n) {
                j = 0;
                int ll = -query(0,3*n-1,l,r,0,tree[j]),rr = query(0,3*n-1,l,r,0,tree2[j]);
                c++,l = ll,r = rr;
            }
            if (r-l+1 < n) {
                j = 0;
                int ll = -query(0,3*n-1,l,r,0,tree[j]),rr = query(0,3*n-1,l,r,0,tree2[j]);
                c++,l = ll,r = rr;
            }
        }
        p = ans[i-n] = c;
    }
    for (i = 0; i < n; i++) printf("%d ",ans[i]);
    printf("\n");

    return 0;
}