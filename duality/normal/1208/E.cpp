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

vi arr[1000000];
vi tree[1000000];
int pos[1000000];
int m[1000000];
vi vv[1000000];
int build(int s,int e,int i,int p) {
    if (s == e) {
        tree[p][i] = arr[p][s];
        return tree[p][i];
    }

    int mid = (s+e) / 2;
    tree[p][i] = max(build(s,mid,2*i+1,p),build(mid+1,e,2*i+2,p));
    return tree[p][i];
}
int query(int s,int e,int qs,int qe,int i,int p) {
    if ((s > qe) || (e < qs)) return -1e9;
    else if ((s >= qs) && (e <= qe)) return tree[p][i];

    int mid = (s+e) / 2;
    return max(query(s,mid,qs,qe,2*i+1,p),query(mid+1,e,qs,qe,2*i+2,p));
}
int main() {
    int i,j;
    int n,w,l;
    scanf("%d %d",&n,&w);
    for (i = 0; i < n; i++) {
        scanf("%d",&l);
        arr[i].resize(l);
        for (j = 0; j < l; j++) scanf("%d",&arr[i][j]);
    }

    LLI s = 0;
    for (i = 0; i < n; i++) {
        pos[i] = 0;
        for (j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] > arr[i][pos[i]]) pos[i] = j;
        }
        if (arr[i][pos[i]] < 0) {
            int l = arr[i].size();
            for (j = w-l; j < l; j++) vv[j].pb(i);
            m[i] = 0;
        }
        else {
            for (j = 0; j < pos[i]; j++) vv[j].pb(i);
            for (j = w-(arr[i].size()-pos[i]-1); j < w; j++) vv[j].pb(i);
            m[i] = arr[i][pos[i]];
        }
        s += m[i];
        tree[i].resize(4*arr[i].size());
        build(0,arr[i].size()-1,0,i);
    }
    for (i = 0; i < w; i++) {
        LLI ans = s;
        for (j = 0; j < vv[i].size(); j++) {
            int p = vv[i][j];
            ans -= m[p];
            int q = query(0,arr[p].size()-1,(int) arr[p].size()-(w-i),i,0,p);
            if (q < 0) {
                if (i >= arr[p].size()) q = 0;
                else if (w-i-1 >= arr[p].size()) q = 0;
            }
            ans += q;
        }
        printf("%I64d ",ans);
    }
    printf("\n");

    return 0;
}