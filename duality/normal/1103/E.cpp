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

struct num {
    ULLI a[5];
    ULLI &operator[](int i) { return a[i]; }
    num operator+(num o) {
        int i;
        num n;
        for (i = 0; i < 5; i++) n[i] = a[i]+o[i];
        return n;
    }
    num operator-(num o) {
        int i;
        num n;
        for (i = 0; i < 5; i++) n[i] = a[i]-o[i];
        return n;
    }
    num operator*(num o) {
        int i,j;
        num n;
        fill(n.a,n.a+5,0);
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) n[(i+j >= 5) ? i+j-5:i+j] += a[i]*o[j];
        }
        return n;
    }
    num operator*(int e) {
        int i;
        e %= 10;
        if (e < 0) e += 10;
        num n;
        for (i = 0; i < 5; i++) n[i] = a[i];
        if (e & 1) {
            for (i = 0; i < 5; i++) n[i] *= -1LLU;
            e = (e+5) >> 1;
            if (e >= 5) e -= 5;
        }
        else e >>= 1;
        if (e > 0) rotate(n.a,n.a+e,n.a+5);
        return n;
    }
};
num a[100000];
int trans(int inv) {
    int i,j,k,l,m;
    for (i = 1; i < 100000; i *= 10) {
        for (j = 0; j < 100000; j += 10*i) {
            for (k = 0; k < i; k++) {
                num b[10];
                for (l = 0; l < 10; l++) b[l] = a[j+k+l*i];
                for (l = 0; l < 10; l++) {
                    fill(a[j+k+l*i].a,a[j+k+l*i].a+5,0);
                    for (m = 0; m < 10; m++) a[j+k+l*i] = a[j+k+l*i]+b[m]*(inv ? l*m:-l*m);
                }
            }
        }
    }
    return 0;
}
int main() {
    int i;
    int n,x;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&x),a[x][0]++;

    trans(0);
    for (i = 0; i < 100000; i++) {
        int e = n-1;
        num b = a[i];
        while (e > 0) {
            if (e & 1) a[i] = a[i]*b;
            e >>= 1;
            b = b*b;
        }
    }
    trans(1);
    for (i = 0; i < n; i++) printf("%llu\n",(((a[i][0]-a[i][1]) >> 5)*6723469279985657373LLU) & ((1LLU << 58)-1));

    return 0;
}