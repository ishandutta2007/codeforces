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

int l[100000],r[100000],x[100000];
int a[100000],b[100000];
int process(int n,LLI t) {
    int i,s = 0,e = 1e5;
    while (s < e) {
        int mid = (s+e+1) / 2;

        LLI ss = 0;
        for (i = 0; i < n; i++) {
            ss += clamp(mid,l[i],r[i]);
            if (ss > t) break;
        }
        if (ss <= t) s = mid;
        else e = mid-1;
    }
    LLI ss = 0;
    for (i = 0; i < n; i++) {
        l[i] = clamp(s,l[i],r[i]);
        ss += l[i];
    }
    for (i = 0; i < n; i++) {
        if ((ss < t) && (l[i] == s) && (l[i] < r[i])) l[i]++,ss++;
    }
    return ss == t;
}
struct line { LLI m,b; };
int bad(line a,line b,line c) {
    return (a.b-b.b)*(c.m-b.m) >= (b.b-c.b)*(b.m-a.m);
}
vector<line> hull;
int possible(int n,int m) {
    int i;
    LLI s = 0,t = 0;
    for (i = 0; i < n; i++) {
        if (a[i] > m) return 0;
        s += a[i];
    }
    for (i = 0; i < m; i++) {
        if (b[i] > n) return 0;
        t += b[i];
    }
    if (s != t) return 0;
    s = 0;
    int j = hull.size()-1;
    for (i = 0; i <= m; i++) {
        int x = m-i;
        while ((j >= 1) && (hull[j-1].m*x+hull[j-1].b < hull[j].m*x+hull[j].b)) j--;
        if (hull[j].m*x+hull[j].b+s < t) return 0;
        if (i < m) s += b[m-i-1];
    }
    return 1;
}
int main() {
    int i;
    int n,m,q,p,s;
    LLI t;
    scanf("%d %d",&n,&m),fill(x,x+m,-1);
    for (i = 0; i < n; i++) scanf("%d %d",&l[i],&r[i]);
    scanf("%d",&q);
    for (i = 0; i < q; i++) scanf("%d %d",&p,&s),x[p-1] = s;
    scanf("%I64d",&t);

    LLI sl = 0,sr = 0;
    for (i = 0; i < n; i++) sl += l[i],sr += r[i];
    if ((t < sl) || (t > sr)) {
        printf("-1 -1\n");
        return 0;
    }
    process(n,t);
    for (i = 0; i < n; i++) a[i] = l[i];
    sort(a,a+n);
    LLI ss = 0;
    for (i = 0; i <= n; i++) {
        line l = (line){n-i,ss};
        while ((hull.size() >= 2) && bad(hull[hull.size()-2],hull.back(),l)) hull.pop_back();
        hull.pb(l);
        if (i < n) ss += a[i];
    }
    s = 0;
    int e = m;
    while (s < e) {
        int mid = (s+e+1) / 2;

        int must = -1;
        for (i = 0; i < mid; i++) {
            if (x[i] != -1) {
                if (must == -1) must = x[i];
                else if (x[i] != must) break;
            }
        }
        if (i < mid) e = mid-1;
        else {
            if (must == -1) {
                p = n+1;
                int f;
                LLI ss = 0;
                for (i = 0; i < m; i++) {
                    if (x[i] != -1) {
                        if (p == n+1) ss += (LLI) i*x[i],f = i;
                        p = min(p,x[i]);
                    }
                    if (p != n+1) ss += p;
                }
                LLI need;
                if (p == n+1) need = (t+m-1)/m;
                else need = x[f]+max((t-ss+f-1)/f,0LL);
                must = min(need,(LLI) n);
            }
            p = 0;
            for (i = m-1; i >= 0; i--) {
                if (x[i] != -1) p = max(p,x[i]);
                if (i < mid) p = max(p,must);
                l[i] = p;
            }
            p = must;
            for (i = 0; i < m; i++) {
                if (x[i] != -1) p = min(p,x[i]);
                r[i] = p;
            }
            if (!process(m,t)) e = mid-1;
            else {
                for (i = 0; i < m; i++) b[i] = l[i];
                if (possible(n,m)) s = mid;
                else e = mid-1;
            }
        }
    }
    if (s == 0) {
        printf("-1 -1\n");
        return 0;
    }
    int ans1 = s,must = -1;
    for (i = 0; i < s; i++) {
        if (x[i] != -1) {
            if (must == -1) must = x[i];
        }
    }
    if (must == -1) {
        p = n+1;
        int f;
        LLI ss = 0;
        for (i = 0; i < m; i++) {
            if (x[i] != -1) {
                if (p == n+1) ss += (LLI) i*x[i],f = i;
                p = min(p,x[i]);
            }
            if (p != n+1) ss += p;
        }
        LLI need;
        if (p == n+1) need = (t+m-1)/m;
        else need = x[f]+max((t-ss+f-1)/f,0LL);
        s = need,e = n;
        while (s < e) {
            int mid = (s+e+1) / 2;

            p = 0;
            int must = mid;
            for (i = m-1; i >= 0; i--) {
                if (x[i] != -1) p = max(p,x[i]);
                if (i < ans1) p = max(p,must);
                l[i] = p;
            }
            p = must;
            for (i = 0; i < m; i++) {
                if (x[i] != -1) p = min(p,x[i]);
                r[i] = p;
            }
            if (!process(m,t)) e = mid-1;
            else {
                for (i = 0; i < m; i++) b[i] = l[i];
                if (possible(n,m)) s = mid;
                else e = mid-1;
            }
        }
        printf("%d %d\n",ans1,s);
    }
    else printf("%d %d\n",ans1,must);

    return 0;
}