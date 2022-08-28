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

int a[1000000],occ[500000];
vi S,S2;
int seen[500000],inStack[500000];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < 2*n-1; i++) scanf("%d",&a[i]),a[i]--;

    if ((a[0] != -1) || (a[2*n-2] != -1)) {
        if ((a[0] != -1) && (a[2*n-2] != -1) && (a[0] != a[2*n-2])) {
            printf("no\n");
            return 0;
        }
        else if (a[2*n-2] != -1) a[0] = a[2*n-2];
    }
    for (i = 0; i < 2*n-2; i++) {
        if (a[i] != -1) break;
    }
    if (i == 2*n-2) {
        printf("yes\n");
        for (i = 1; i <= n; i++) printf("%d ",i);
        for (i = n-1; i >= 1; i--) printf("%d ",i);
        return 0;
    }
    int p = i;
    for (i = 0; i < 2*n-2; i++) {
        if (a[i] != -1) occ[a[i]]++;
    }
    int j,k,x = 0;
    for (i = 0; i < 2*n-2; i++) {
        j = (p+i) % (2*n-2);
        if (a[j] != -1) {
            if (seen[a[j]]) break;
            else if (!inStack[a[j]]) inStack[a[j]] = 1,S.pb(j);
            else {
                vi v;
                v.pb(j);
                int c = 0;
                while (a[S.back()] != a[j]) {
                    v.pb(S.back());
                    if (a[S.back()] != -1) inStack[a[S.back()]] = 0,seen[a[S.back()]] = 1,c++;
                    S.pop_back();
                }
                if (v.size() & 1) break;
                else if (c > v.size()/2) break;
                else {
                    reverse(v.begin(),v.end());
                    for (k = 0; k < v.size(); k++) {
                        if ((a[v[k]] == -1) && (c < v.size()/2)) {
                            while (occ[x] > 0) x++;
                            a[v[k]] = x++,c++;
                        }
                    }
                    int s = 0,m = 1e9,mi = -1;
                    for (k = 0; k < v.size(); k++) {
                        s += (a[v[k]] != -1) ? 1:-1;
                        if (s <= m) m = s,mi = k;
                    }
                    int q = (mi+1) % v.size();
                    for (k = 0; k < v.size(); k++) {
                        if (a[v[q]] != -1) S2.pb(a[v[q]]);
                        else a[v[q]] = S2[S2.size()-2],S2.pop_back();
                        q = (q+1) % v.size();
                    }
                    S2.clear();
                }
            }
        }
        else S.pb(j);
    }
    if (i < 2*n-2) printf("no\n");
    else {
        vi v;
        int c = -1;
        while (!S.empty()) {
            v.pb(S.back());
            if (a[S.back()] != -1) inStack[a[S.back()]] = 0,seen[a[S.back()]] = 1,c++;
            S.pop_back();
        }
        if (v.size() & 1) i = -1;
        else if (c > v.size()/2) i = -1;
        else {
            reverse(v.begin(),v.end());
            for (k = 0; k < v.size(); k++) {
                if ((a[v[k]] == -1) && (c < v.size()/2)) {
                    while (occ[x] > 0) x++;
                    a[v[k]] = x++,c++;
                }
            }
            int s = 0,m = 1e9,mi = -1;
            for (k = 0; k < v.size(); k++) {
                s += (a[v[k]] != -1) ? 1:-1;
                if (s <= m) m = s,mi = k;
            }
            int q = (mi+1) % v.size();
            for (k = 0; k < v.size(); k++) {
                if (a[v[q]] != -1) S2.pb(a[v[q]]);
                else a[v[q]] = S2[S2.size()-2],S2.pop_back();
                q = (q+1) % v.size();
            }
            S2.clear();
        }
        if (i < 2*n-2) printf("no\n");
        else {
            printf("yes\n");
            for (i = 0; i < 2*n-2; i++) printf("%d ",a[i]+1);
            printf("%d\n",a[0]+1);
        }
    }

    return 0;
}