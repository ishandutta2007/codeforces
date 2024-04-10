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

vi fact[100001];
int gcd(int a,int b) {
    int t;
    while (a > 0) t = b % a,b = a,a = t;
    return b;
}
int good[8][8][8],x[3],m[500],num[8],num2[8];
unordered_map<LLI,int> M;
int main() {
    int i,j,k;
    for (i = 1; i <= 100000; i++) {
        for (j = i; j <= 100000; j += i) fact[j].pb(i);
    }
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            for (k = 0; k < 8; k++) {
                int f = 0;
                x[0] = 0,x[1] = 1,x[2] = 2;
                do {
                    if ((i & (1 << x[0])) && (j & (1 << x[1])) && (k & (1 << x[2]))) f = 1;
                } while (next_permutation(x,x+3));
                good[i][j][k] = f;
            }
        }
    }
    int t,a[3];
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d %d",&a[0],&a[1],&a[2]);
        sort(a,a+3);
        if (M.count(a[0]*((LLI) 1e12)+a[1]*((LLI) 1e6)+a[2])) {
            printf("%d\n",M[a[0]*((LLI) 1e12)+a[1]*((LLI) 1e6)+a[2]]);
            continue;
        }

        vi v(fact[a[0]].size()+fact[a[1]].size());
        vi v2(fact[a[0]].size()+fact[a[1]].size()+fact[a[2]].size());
        merge(fact[a[0]].begin(),fact[a[0]].end(),fact[a[1]].begin(),fact[a[1]].end(),v.begin());
        merge(v.begin(),v.end(),fact[a[2]].begin(),fact[a[2]].end(),v2.begin());
        v2.resize(unique(v2.begin(),v2.end())-v2.begin());
        for (i = 0; i < v2.size(); i++) {
            m[i] = 0;
            for (j = 0; j < 3; j++) {
                if ((a[j] % v2[i]) == 0) m[i] |= (1 << j);
            }
            num2[m[i]]++;
        }
        int ans = 0;
        for (i = 0; i < v2.size(); i++) {
            num[m[i]]++;
            for (j = 0; j < 8; j++) {
                for (k = 0; k < 8; k++) {
                    if (good[m[i]][j][k]) ans += num[j]*num2[k];
                }
            }
            num2[m[i]]--;
        }
        M[a[0]*((LLI) 1e12)+a[1]*((LLI) 1e6)+a[2]] = ans;
        printf("%d\n",ans);
        memset(num,0,sizeof(num)),memset(num2,0,sizeof(num2));
    }

    return 0;
}