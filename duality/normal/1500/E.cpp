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

LLI s[200000],a[200000];
int t[200000];
vlli poss;
LLI num[1 << 20],sum[1 << 20],sum2[1 << 20];
int update(int s,int e,int ai,int i,int t) {
    if ((s > ai) || (e < ai)) return 0;
    else if (s == e) {
        if (t == 0) num[i] = sum[i] = sum2[i] = 0;
        else num[i] = 1,sum[i] = poss[s],sum2[i] = 0;
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,ai,2*i+1,t),update(mid+1,e,ai,2*i+2,t);
    num[i] = num[2*i+1] + num[2*i+2];
    sum[i] = sum[2*i+1] + sum[2*i+2];
    sum2[i] = sum2[2*i+1] + sum2[2*i+2] + num[2*i+1]*sum[2*i+2];
    return 0;
}
LLI x,y,z;
int query(int s,int e,int qs,int qe,int i) {
    if (i == 0) x = y = z = 0;
    if ((s > qe) || (e < qs)) return 0;
    else if ((s >= qs) && (e <= qe)) {
        z += sum2[i] + x*sum[i];
        y += sum[i],x += num[i];
        return 0;
    }

    int mid = (s+e) / 2;
    query(s,mid,qs,qe,2*i+1),query(mid+1,e,qs,qe,2*i+2);
    return 0;
}
int kth(int s,int e,int i,int k) {
    if (s == e) return s;

    int mid = (s+e) / 2;
    if (k <= num[2*i+1]) return kth(s,mid,2*i+1,k);
    else return kth(mid+1,e,2*i+2,k-num[2*i+1]);
}
LLI getAns() {
    query(0,poss.size()-1,0,poss.size()-1,0);
    int n = x;
    LLI ans = y;
    int l = 1,r = (n+1)/2;
    while (l < r) {
        int m = (l+r+1) / 2;

        int a = kth(0,poss.size()-1,0,m);
        query(0,poss.size()-1,0,a,0);
        LLI aa = y;
        a = kth(0,poss.size()-1,0,n-m+2);
        query(0,poss.size()-1,a,poss.size()-1,0);
        if (y >= aa) r = m-1;
        else l = m;
    }
    int a = kth(0,poss.size()-1,0,l);
    query(0,poss.size()-1,0,a,0);
    LLI L = l*y-z,R = 0;
    if (l > 1) {
        a = kth(0,poss.size()-1,0,n-l+2);
        query(0,poss.size()-1,a,poss.size()-1,0);
        R = y+z;
    }
    ans -= 2*(L-R);
    if ((n & 1) && (l == (n+1)/2)) {
        int a = kth(0,poss.size()-1,0,l);
        query(0,poss.size()-1,0,a,0);
        LLI aa = y;
        y = 0;
        if (l > 1) {
            a = kth(0,poss.size()-1,0,n-l+2);
            query(0,poss.size()-1,a,poss.size()-1,0);
        }
        ans += aa-y;
    }
    return ans;
}
int main() {
    int i;
    int n,q;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) scanf("%I64d",&s[i]),poss.pb(s[i]);
    for (i = 0; i < q; i++) {
        scanf("%d %I64d",&t[i],&a[i]);
        poss.pb(a[i]);
    }
    sort(poss.begin(),poss.end());
    poss.resize(unique(poss.begin(),poss.end())-poss.begin());

    for (i = 0; i < n; i++) {
        int p = lower_bound(poss.begin(),poss.end(),s[i])-poss.begin();
        update(0,poss.size()-1,p,0,1);
    }
    printf("%I64d\n",getAns());
    for (i = 0; i < q; i++) {
        int p = lower_bound(poss.begin(),poss.end(),a[i])-poss.begin();
        update(0,poss.size()-1,p,0,2-t[i]);
        printf("%I64d\n",getAns());
    }

    return 0;
}