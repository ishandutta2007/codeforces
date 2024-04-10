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

int d,p;
int num = 5;
int mult(int cell,int c) {
    if (c == 0) c = p;
    if (c == 1) return cell;
    int cell2 = num++;
    cout << "+ " << cell << " " << cell << " " << cell2 << endl;
    c -= 2;
    while (c > 0) {
        if (c & 1) cout << "+ " << cell << " " << cell2 << " " << cell2 << endl;
        c >>= 1;
        if (c > 0) cout << "+ " << cell << " " << cell << " " << cell << endl;
    }
    return cell2;
}
int aug[100][101];
int sol[100];
int inv(LLI n) {
    int e = p-2;
    LLI r = 1;
    while (e > 0) {
        if (e & 1) r *= n,r %= p;
        e >>= 1;
        n *= n,n %= p;
    }
    return r;
}
int solve(int n) {
    print2dArr2(aug,n,n+1,3);
    int i,j,k;
    for (j = 0; j < (n-1); j++) {
        for (k = j; k < n; k++) {
            if (aug[k][j] != 0) break;
        }
        int r = k;
        for (k = 0; k <= n; k++) swap(aug[j][k],aug[r][k]);
        assert(aug[j][j] != 0);
        printVar(j);
        print2dArr2(aug,n,n+1,3);
        for (i = j+1; i < n; i++) {
            int f = ((LLI) aug[i][j]*inv(aug[j][j])) % p;
            for (k = j; k <= n; k++) {
                aug[i][k] = (aug[i][k]-(LLI) f*aug[j][k]) % p;
                if (aug[i][k] < 0) aug[i][k] += p;
            }
        }
    }
    print2dArr2(aug,n,n+1,3);
    for (i = n-1; i >= 0; i--) {
        if (aug[i][i] == 0) return 0;
        int s = 0;
        for (j = i+1; j < n; j++) s += ((LLI) aug[i][j] * sol[j]) % p,s %= p;
        sol[i] = ((LLI) (aug[i][n]-s+p)*inv(aug[i][i])) % p;
    }

    return 1;
}
vi vv[100];
int square(int cell) {
    int i,j;
    vi v;
    v.pb(cell);
    for (i = 1; i <= d; i++) {
        v.pb(num);
        cout << "+ " << cell << " " << 3 << " " << num++ << endl;
        cell = v.back();
    }
    for (i = 0; i < v.size(); i++) cout << "^ " << v[i] << " " << v[i] << endl;
    int k,n = d+1;
    for (i = 0; i <= d; i++) {
        vv[i].resize(d+1);
        for (j = 0; j <= d; j++) vv[i][j] = 0;
        vv[i][0] = 1;
        for (k = 0; k < d; k++) {
            for (j = d; j >= 0; j--) vv[i][j] = (((j == 0) ? 0:vv[i][j-1])+(LLI) i*vv[i][j]) % p;
        }
        printArr(vv[i],vv[i].size());
    }
    for (i = 0; i <= d; i++) {
        aug[i][n] = (i == 2) ? 1:0;
        for (j = 0; j <= d; j++) aug[i][j] = vv[j][i];
    }
    assert(solve(n));
    printArr(sol,n);
    for (i = 0; i <= d; i++) v[i] = mult(v[i],sol[i]);
    printArr(v,v.size());
    for (i = 1; i <= d; i++) cout << "+ " << v[i-1] << " " << v[i] << " " << v[i] << endl;
    return v[d];
}
int main() {
    cin >> d >> p;
    cout << "+ 1 2 4" << endl;
    int a = square(1),b = square(2),c = square(4);
    printVar(a);
    printVar(b);
    a = mult(a,p-1),b = mult(b,p-1);
    debug "here";
    cout << "+ " << a << " " << b << " " << b << endl;
    cout << "+ " << b << " " << c << " " << c << endl;
    c = mult(c,(p+1)/2);
    cout << "f " << c << endl;

    return 0;
}