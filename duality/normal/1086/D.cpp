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

char s[200000];
set<int> S[3];
int bit[3][200001];
int update(int t,int i,int num) {
    for (i++; i <= 200000; i += i & (-i)) bit[t][i] += num;
    return 0;
}
int query(int t,int i) {
    int sum = 0;
    for (i++; i > 0; i -= i & (-i)) sum += bit[t][i];
    return sum;
}
int solve(int n) {
    int i,ans = 0;
    for (i = 0; i < 3; i++) {
        int x = (i+2) % 3,y = (i+1) % 3;
        if (S[x].empty()) {
            if (S[y].empty()) ans += S[i].size();
        }
        else {
            if (S[y].empty()) ans += S[i].size();
            else {
                ans += S[i].size();
                int r = *S[x].begin()-1;
                int l = *S[y].begin()+1;
                if (l <= r) ans -= query(i,r)-query(i,l-1);
                l = *(--S[x].end())+1;
                r = *(--S[y].end())-1;
                if (l <= r) ans -= query(i,r)-query(i,l-1);
            }
        }
    }
    return ans;
}
int main() {
    int i;
    int n,q,p;
    char c;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) {
        scanf(" %c",&s[i]);
        if (s[i] == 'R') S[0].insert(i),update(0,i,1);
        else if (s[i] == 'P') S[1].insert(i),update(1,i,1);
        else S[2].insert(i),update(2,i,1);
    }
    printf("%d\n",solve(n));
    for (i = 0; i < q; i++) {
        scanf("%d %c",&p,&c),p--;
        if (s[p] == 'R') S[0].erase(p),update(0,p,-1);
        else if (s[p] == 'P') S[1].erase(p),update(1,p,-1);
        else S[2].erase(p),update(2,p,-1);
        s[p] = c;
        if (s[p] == 'R') S[0].insert(p),update(0,p,1);
        else if (s[p] == 'P') S[1].insert(p),update(1,p,1);
        else S[2].insert(p),update(2,p,1);
        printf("%d\n",solve(n));
    }

    return 0;
}