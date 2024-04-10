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

pii p[100000];
LLI dp[100000];
LLI tree[1 << 18],tree2[1 << 18];
int update(int s,int e,int ai,int i,LLI num) {
    if ((s > ai) || (e < ai)) return 0;
    else if (s == e) {
        tree[i] = num,tree2[i] = num+p[s].first;
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,ai,2*i+1,num),update(mid+1,e,ai,2*i+2,num);
    tree[i] = min(tree[2*i+1],tree[2*i+2]);
    tree2[i] = min(tree2[2*i+1],tree2[2*i+2]);
    return 0;
}
LLI query(int s,int e,int qs,int qe,int i) {
    if ((s > qe) || (e < qs)) return 1e18;
    else if ((s >= qs) && (e <= qe)) return tree[i];

    int mid = (s+e) / 2;
    return min(query(s,mid,qs,qe,2*i+1),query(mid+1,e,qs,qe,2*i+2));
}
LLI query2(int s,int e,int qs,int qe,int i) {
    if ((s > qe) || (e < qs)) return 1e18;
    else if ((s >= qs) && (e <= qe)) return tree2[i];

    int mid = (s+e) / 2;
    return min(query2(s,mid,qs,qe,2*i+1),query2(mid+1,e,qs,qe,2*i+2));
}
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d",&p[i].first,&p[i].second);
    sort(p,p+n);

    LLI sum = 0;
    for (i = 0; i < n; i++) sum += p[i].second;
    dp[n-1] = 0;
    update(0,n-1,n-1,0,dp[n-1]);
    for (i = n-2; i >= 0; i--) {
        int x = upper_bound(p,p+n,mp(p[i].first+p[i].second,(int) 2e9))-p-1;
        if (x > i) dp[i] = query(0,n-1,i+1,x,0);
        else dp[i] = 1e18;
        dp[i] = min(dp[i],query2(0,n-1,x+1,n-1,0)-p[i].first-p[i].second);
        update(0,n-1,i,0,dp[i]);
    }
    printf("%lld\n",sum+dp[0]);

    return 0;
}