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
const double PI = acos(-1.0);

int n;
struct point {
    int x,y;
    double a,d;
};
point p[100000];
struct event {
    double x,l,r;
    int n;
};
bool comp(event a,event b) {
    return a.x < b.x;
}
int bit[100001];
int update(int i,int num) {
    for (i++; i <= n; i += i & (-i)) bit[i] += num;
    return 0;
}
int query(int i) {
    int sum = 0;
    for (i++; i > 0; i -= i & (-i)) sum += bit[i];
    return sum;
}
event events[200000];
double all[100000];
int main() {
    int i;
    LLI k;
    scanf("%d %I64d",&n,&k);
    for (i = 0; i < n; i++) {
        scanf("%d %d",&p[i].x,&p[i].y);
        p[i].a = atan2(p[i].y,p[i].x);
        p[i].d = sqrt(p[i].x*p[i].x+p[i].y*p[i].y);
    }

    int t = 0;
    double l = 0,r = 1.5e4;
    while (t < 40) {
        t++;
        double m = (l+r) / 2;

        LLI num = 0;
        int c = 0,c2 = 0;
        for (i = 0; i < n; i++) {
            if (p[i].d > m) {
                double t = acos(m/p[i].d);
                double a1 = p[i].a-t,a2 = p[i].a+t;
                while (a1 < -PI) a1 += 2*PI;
                while (a2 > PI) a2 -= 2*PI;
                if (a1 > a2) swap(a1,a2);
                events[c++] = (event){a1,a2,a2,0},all[c2++] = a2;
                events[c++] = (event){a1-1e-12,a1+1e-12,a2-1e-12,1};
            }
        }
        fill(bit,bit+n+1,0);
        sort(events,events+c,comp);
        sort(all,all+c2);
        for (i = 0; i < c; i++) {
            if (events[i].n == 0) {
                int p = lower_bound(all,all+c2,events[i].l)-all;
                update(p,1);
            }
            else {
                int q = upper_bound(all,all+c2,events[i].r)-all-1;
                int p = lower_bound(all,all+c2,events[i].l)-all;
                num += events[i].n*(query(q)-query(p-1));
            }
        }
        num = (LLI) n*(n-1)/2-num;
        if (num < k) l = m;
        else r = m;
    }
    printf("%.12lf\n",l);

    return 0;
}