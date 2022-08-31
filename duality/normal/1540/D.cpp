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
#pragma GCC optimize("Ofast")

int n,B,inv[100000];
vi vv[100000];
pii tree[1 << 10];
int lazy[1 << 10];
int build(int s,int e,int i) {
    if (s == e) {
        tree[i] = mp(inv[s],-s),lazy[i] = 0;
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    tree[i] = min(tree[2*i+1],tree[2*i+2]),lazy[i] = 0;
    return 0;
}
int prop(int s,int e,int i) {
    if (lazy[i] != 0) {
        tree[i].first += lazy[i];
        if (s != e) lazy[2*i+1] += lazy[i],lazy[2*i+2] += lazy[i];
        lazy[i] = 0;
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
    tree[i] = min(tree[2*i+1],tree[2*i+2]);
    return 0;
}
int rebuild(int b) {
    int i,j,e = min((b+1)*B,n),c = 0;
    vv[b].clear();
    build(b*B,e-1,0);
    while (tree[0].first < 1e8) {
        int p = -tree[0].second;
        vv[b].pb((vv[b].empty() ? -1:vv[b].back())+tree[0].first-c+1);
        c = tree[0].first;
        update(b*B,e-1,p+1,e-1,0,-1);
        update(b*B,e-1,p,p,0,1e9);
    }
    return 0;
}
int main() {
    int i,j;
    int q,t,p,x;
    scanf("%d",&n),B = max((int) sqrt(n)/2,1);
    for (i = 0; i < n; i++) scanf("%d",&inv[i]),inv[i] = i-inv[i];
    for (i = 0; i < (n+B-1)/B; i++) rebuild(i);
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d",&t);
        if (t == 1) {
            scanf("%d %d",&p,&x),p--;
            inv[p] = p-x,rebuild(p/B);
        }
        else {
            scanf("%d",&p),p--;
            int ans = inv[p];
            for (j = p+1; j < min((p/B+1)*B,n); j++) {
                if (ans >= inv[j]) ans++;
            }
            for (j = p/B+1; j < (n+B-1)/B; j++) {
                int e = min((j+1)*B,n);
                int l = 0,r = vv[j].size();
                while (l < r) {
                    int m = (l+r) / 2;
                    if (vv[j][m]-m > ans) r = m;
                    else l = m+1;
                }
                ans += l;
            }
            printf("%d\n",ans+1);
        }
    }

    return 0;
}