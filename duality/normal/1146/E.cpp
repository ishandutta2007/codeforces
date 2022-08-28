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
#define MAX 100010

int a[100000],a2[100000];
int arr[2*MAX+10],arr2[2*MAX+10];
vi sw[MAX+10];
int num[2*MAX+10];
int bit[MAX+20];
int update(int i) {
    for (i++; i < MAX+20; i += i & (-i)) bit[i] ^= 1;
    return 0;
}
int query(int i) {
    int s = 0;
    for (i++; i > 0; i -= i & (-i)) s ^= bit[i];
    return s;
}
int main() {
    int i;
    int n,q,x;
    char s;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),a2[i] = a[i];
    for (i = 0; i < q; i++) {
        scanf(" %c %d",&s,&x);
        /*for (int j = 0; j < n; j++) {
            if (s == '>') {
                if (a2[j] > x) a2[j] = -a2[j];
            }
            else {
                if (a2[j] < x) a2[j] = -a2[j];
            }
        }*/

        if (s == '>') {
            x++;
            if (x >= 0) arr[x+MAX] = max(arr[x+MAX],i+1);
            else {
                arr[-x+1+MAX] = max(arr[-x+1+MAX],i+1);
                sw[-x].pb(i+1);
            }
        }
        else {
            x--;
            if (x <= 0) arr2[x+MAX] = max(arr2[x+MAX],i+1);
            else {
                arr2[-x-1+MAX] = max(arr2[-x-1+MAX],i+1);
                sw[x].pb(i+1);
            }
        }
    }

    for (i = -MAX+1; i <= MAX; i++) arr[i+MAX] = max(arr[i+MAX],arr[i-1+MAX]);
    for (i = MAX-1; i >= -MAX; i--) arr2[i+MAX] = max(arr2[i+MAX],arr2[i+1+MAX]);
    for (i = MAX; i >= 0; i--) {
        int j;
        for (j = 0; j < sw[i].size(); j++) update(MAX+10-sw[i][j]);
        int m = max(arr[i+MAX],arr2[-i+MAX]);
        if (m == 0) num[i+MAX] = i,num[-i+MAX] = -i;
        else if (arr[i+MAX] == m) num[i+MAX] = num[-i+MAX] = -i;
        else num[i+MAX] = num[-i+MAX] = i;
        if (query(MAX+10-m)) num[i+MAX] *= -1,num[-i+MAX] *= -1;
    }

    for (i = 0; i < n; i++) {
        printf("%d",num[a[i]+MAX]);
        if (i < n-1) printf(" ");
        else printf("\n");
    }
    //for (i = 0; i < n; i++) printf("%d ",a2[i]);
    //printf("\n");

    return 0;
}