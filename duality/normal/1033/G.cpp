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

LLI v[100];
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) scanf("%I64d",&v[i]);

    int j,k;
    LLI wa = 0,wb = 0,wf = 0,ws = 0;
    for (i = 2; i <= 2*m; i++) {
        if (!(i & 1)) {
            int c = 0,c2 = 0;
            for (j = 0; j < n; j++) {
                int t = v[j] % i;
                if (t >= i/2) c++;
            }
            if (c & 1) wf--;
            else ws--;
        }
        int x = i-m;
        vi c,c2;
        for (j = 0; j < n; j++) {
            int t = v[j] % i;
            x = max(x,min(i-t,t+1));
            c.pb(i-t),c2.pb(t/2);
        }
        x = min(x,i/2+1);
        wa += x-max(i-m,1),wb += x-max(i-m,1);
        sort(c.begin(),c.end()),sort(c2.begin(),c2.end(),greater<int>());
        while (c2.size() > 2) c2.pop_back();
        for (j = 0; j <= c2.size(); j++) {
            int l = (j == c2.size()) ? x:c2[j]+1;
            int r = (j == 0) ? i/2:c2[j-1];
            l = max(l,x),r = min(r,i/2);
            for (k = 0; k <= c.size(); k++) {
                int ll = (k == 0) ? x:c[k-1],rr = (k == c.size()) ? i/2:c[k]-1;
                if (max(l,ll) <= min(r,rr)) {
                    int d = min(r,rr)-max(l,ll)+1;
                    if (k & 1) {
                        if (j > 1) wa += d,wb += d;
                        else wf += 2*d;
                    }
                    else {
                        if (j > 0) wa += d,wb += d;
                        else ws += 2*d;
                    }
                }
            }
        }
        /*
        for (j = 1; j <= min(i-1,m); j++) {
            if ((i-j >= 1) && (i-j <= m)) {
                int c = 0,c2 = 0;
                for (k = 0; k < n; k++) {
                    int t = v[k] % i;
                    if ((t >= min(j,i-j)) && (t < max(j,i-j))) break;
                    else if (t >= max(j,i-j)) {
                        c++;
                        if (t >= 2*min(j,i-j)) c2++;
                    }
                }
                if (k < n) {
                    if (j > i-j) wb++;
                    else wa++;
                }
                else if (!(c & 1)) {
                    if (c2 > 0) {
                        if (j > i-j) wb++;
                        else wa++;
                    }
                    else ws++;
                }
                else {
                    if (c2 > 1) {
                        if (j > i-j) wb++;
                        else wa++;
                    }
                    else wf++;
                }
            }
        }*/
    }
    printf("%I64d %I64d %I64d %I64d\n",wa,wb,wf,ws);

    return 0;
}