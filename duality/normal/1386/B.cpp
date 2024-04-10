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

int Sf,Pf,Gf;
int S[100000],P[100000],G[100000];
struct point { LLI x,y; };
class comp {
    public:
        bool operator()(point a,point b) const {
            return (long double) a.x*b.y > (long double) a.y*b.x;
        }
};
point angle(int S,int P,int G) {
    return (point){(LLI) S*(Sf+Pf+Gf)-(LLI) Sf*(S+P+G),(LLI) P*(Sf+Pf+Gf)-(LLI) Pf*(S+P+G)};
}
int quad(point p) {
    if ((p.x == 0) && (p.y == 0)) return -1;
    else if ((p.x > 0) && (p.y >= 0)) return 0;
    else if ((p.x <= 0) && (p.y > 0)) return 1;
    else if ((p.x < 0) && (p.y <= 0)) return 2;
    else return 3;
}
multiset<point,comp> SS[4];
int main() {
    int i;
    int N;
    int b = 0,r;
    char c;
    int o = 0,oo = 0;
    scanf("%d %d %d %d",&Sf,&Pf,&Gf,&N);
    for (i = 0; i < N; i++) {
        scanf(" %c",&c);
        if (c == 'A') {
            scanf("%d %d %d",&S[b],&P[b],&G[b]);
            point d = angle(S[b],P[b],G[b]);
            b++;
            int q = quad(d);
            if (q == -1) oo++;
            else {
                if (SS[q].find(d) == SS[q].end()) {
                    d.x *= -1,d.y *= -1;
                    if (SS[q^2].find(d) != SS[q^2].end()) o++;
                    d.x *= -1,d.y *= -1;
                }
                SS[q].insert(d);
            }
        }
        else {
            scanf("%d",&r),r--;
            point d = angle(S[r],P[r],G[r]);
            int q = quad(d);
            if (q == -1) oo--;
            else {
                SS[q].erase(SS[q].find(d));
                if (SS[q].find(d) == SS[q].end()) {
                    d.x *= -1,d.y *= -1;
                    if (SS[q^2].find(d) != SS[q^2].end()) o--;
                }
            }
        }
        if (oo > 0) printf("1\n");
        else if (o > 0) printf("2\n");
        else {
            int q;
            for (q = 0; q < 4; q++) {
                if (SS[q].empty()) {
                    if (SS[(q+1) & 3].empty() || SS[(q+3) & 3].empty()) break;
                    else if (comp()(*SS[(q+1) & 3].begin(),*SS[(q+3) & 3].rbegin())) break;
                }
            }
            printf((q < 4) ? "0\n":"3\n");
        }
    }

    return 0;
}