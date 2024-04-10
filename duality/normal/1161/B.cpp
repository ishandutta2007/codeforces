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

vi diff[100000];
map<int,int> trie[400000];
int leaf[400000],num = 0;
int s[200000];
int lps[200001];
int main() {
    int i;
    int n,m,a,b;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&a,&b);
        a--,b--;
        diff[a].pb((b-a+n) % n);
        diff[b].pb((a-b+n) % n);
    }

    int j,x = 0;
    leaf[0] = -1;
    for (i = 0; i < n; i++) {
        sort(diff[i].begin(),diff[i].end());
        int c = 0;
        for (j = 0; j < diff[i].size(); j++) {
            if (!trie[c].count(diff[i][j])) {
                trie[c][diff[i][j]] = ++num;
                leaf[num] = -1;
            }
            c = trie[c][diff[i][j]];
        }
        if (leaf[c] == -1) leaf[c] = x++;
        s[i] = s[i+n] = leaf[c];
        //cout<<s[i]<<" ";
    }//cout<<endl;

    j = -1,lps[0] = -1;
    for (i = 0; i < 2*n-1; i++) {
        while ((j >= 0) && (s[i] != s[j])) j = lps[j];
        lps[i+1] = ++j;
        //cout<<lps[i+1]<<endl;
        if (lps[i+1] >= n) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");

    return 0;
}