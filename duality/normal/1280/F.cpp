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

int k,a[2][31];
string ans;
int doP() {
    ans += 'P';
    swap(a[0][k-1],a[0][k]);
    swap(a[0][k],a[0][k+1]);
    return 0;
}
int doQ() {
    ans += 'Q';
    swap(a[0][k+1],a[0][k]);
    swap(a[0][k],a[0][k-1]);
    return 0;
}
int doR() {
    ans += 'R';
    rotate(a[0],a[0]+2*k,a[0]+2*k+1);
    rotate(a[1],a[1]+1,a[1]+2*k);
    swap(a[0][0],a[1][2*k-1]);
    return 0;
}
int main() {
    int i;
    int t;
    char s[3];
    scanf("%d",&t);
    while (t--) {
        int x,y;
        scanf("%d",&k);
        for (i = 0; i < 2*k+1; i++) {
            scanf("%s",s);
            if (s[0] == 'E') a[0][i] = -1,x = 0,y = i;
            else a[0][i] = atoi(s)-1;
        }
        for (i = 0; i < 2*k+1; i++) {
            scanf("%s",s);
            if (s[0] == 'E') a[1][i] = -1,x = 1,y = i;
            else a[1][i] = atoi(s)-1;
        }

        while (y < 2*k) swap(a[x][y],a[x][y+1]),ans += 'r',y++;
        if (x == 0) swap(a[0][y],a[1][y]),ans += 'd',x = 1;
        string A = string(k,'l') + 'u' + string(k,'r') + 'd';
        string B = string(k,'l') + 'u' + string(k,'l') + 'd' + string(2*k,'r');
        string C = 'u' + string(k,'l') + 'd' + string(k,'r');
        string D = string(2*k,'l') + 'u' + string(k,'r') + 'd' + string(k,'r');
        string P = A + B + C + D;
        string Q = B + A + D + C;
        string R = 'u' + string(2*k,'l') + 'd' + string(2*k,'r');
        for (i = 1; i < 2*k+1; i++) {
            while (1) {
                while (a[0][k] != i) doR();
                if (a[0][k-1] != i-1) {
                    if (a[0][k+1] == 0) doR(),doQ();
                    else doP();
                }
                else break;
            }
        }
        for (i = 4*k; i > 2*k+2; i--) {
            while (1) {
                while (a[0][k] != i) doR();
                if (a[0][k-1] != ((i == 4*k) ? 2*k:i+1)) {
                    if (a[0][k+1] == 0) doR(),doQ();
                    else doP();
                }
                else break;
            }
        }
        while (a[0][0] != 0) doR();
        for (i = 0; i < 2*k+1; i++) {
            if (a[0][i] != i) break;
            if ((i < 2*k) && (a[1][i] != i+2*k+1)) break;
        }
        if (i == 2*k+1) {
            printf("SURGERY COMPLETE\n%s\n",ans.c_str());
            printf("P %s\nQ %s\nR %s\n",P.c_str(),Q.c_str(),R.c_str());
            printf("DONE\n");
        }
        else printf("SURGERY FAILED\n");
        ans.clear();
    }

    return 0;
}