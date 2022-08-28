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

int x[1000][4];
int p[1000];
vector<bitset<2001> > aug;
int num(char c) {
    if (c == 'R') return 1;
    else if (c == 'Y') return 2;
    else if (c == 'B') return 3;
    else return 0;
}

// from https://cp-algorithms.com/linear_algebra/linear-system-gauss.html
const int N = 2001;
int gauss (vector < bitset<N> > a, int n, int m, bitset<N> & ans) {
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        for (int i=row; i<n; ++i)
            if (a[i][col]) {
                swap (a[i], a[row]);
                break;
            }
        if (! a[row][col])
            continue;
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row && a[i][col])
                a[i] ^= a[row];
        ++row;
    }

    ans.reset();
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] & a[where[i]][i];
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] & a[i][j];
        if ((sum-a[i][m]) & 1)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return 2;
    return 1;
}

int main() {
    int i,j;
    int n,k,m;
    char s[4];
    char c;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; i++) x[i][1] = 1,x[i][2] = 2,x[i][3] = 3;
    for (i = 0; i < k; i++) {
        scanf("%s %d",s,&m);
        for (j = 0; j < m; j++) scanf("%d",&p[j]),p[j]--;
        if (s[0] == 'm') {
            scanf(" %c",&c);
            bitset<2001> a,b;
            a.reset(),b.reset();
            for (j = 0; j < m; j++) {
                pii pp = mp(x[p[j]][2],x[p[j]][3]);
                if (pp.first > pp.second) swap(pp.first,pp.second);
                if (pp == mp(1,2)) a[2*p[j]] = a[2*p[j]+1] = 1;
                else if (pp == mp(1,3)) a[2*p[j]] = 1;
                else a[2*p[j]+1] = 1;
                pp = mp(x[p[j]][1],x[p[j]][3]);
                if (pp.first > pp.second) swap(pp.first,pp.second);
                if (pp == mp(1,2)) b[2*p[j]] = b[2*p[j]+1] = 1;
                else if (pp == mp(1,3)) b[2*p[j]] = 1;
                else b[2*p[j]+1] = 1;
            }
            a[2*n] = (c == 'Y') || (c == 'B');
            b[2*n] = (c == 'R') || (c == 'B');
            aug.pb(a),aug.pb(b);
        }
        else if ((s[0] == 'R') && (s[1] == 'Y')) {
            for (j = 0; j < m; j++) swap(x[p[j]][1],x[p[j]][2]);
        }
        else if ((s[0] == 'R') && (s[1] == 'B')) {
            for (j = 0; j < m; j++) swap(x[p[j]][1],x[p[j]][3]);
        }
        else {
            for (j = 0; j < m; j++) swap(x[p[j]][2],x[p[j]][3]);
        }
    }

    bitset<2001> ans;
    if (gauss(aug,aug.size(),2*n,ans) == 0) {
        printf("NO\n");
        return 0;
    }
    else {
        printf("YES\n");
        for (i = 0; i < 2*n; i += 2) {
            if (ans[i] && ans[i+1]) printf("B");
            else if (ans[i] && !ans[i+1]) printf("R");
            else if (!ans[i] && ans[i+1]) printf("Y");
            else printf(".");
        }
        printf("\n");
    }

    return 0;
}