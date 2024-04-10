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

int l[100000],r[100000],order[100000];
bool comp(int a,int b) {
    return r[a]-l[a] > r[b]-l[b];
}
int ans[50001];
set<pii> bit[50001];
queue<pii> Q;
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) scanf("%d %d",&l[i],&r[i]),l[i]--,r[i]--;

    int j = 0,k;
    for (i = 0; i < m; i++) order[i] = i;
    sort(order,order+m,comp);
    for (i = n; i >= 1; i--) {
        while ((j < m) && (r[order[j]]-l[order[j]]+1 >= i)) {
            for (k = r[order[j]]+1; k <= n; k += k & (-k)) {
                auto it = bit[k].lower_bound(mp(l[order[j]],0));
                if ((it != bit[k].end()) && (it->second <= order[j])) continue;
                it = bit[k].upper_bound(mp(l[order[j]],1e9));
                while (it != bit[k].begin()) {
                    it--;
                    if (it->second >= order[j]) it = bit[k].erase(it);
                    else break;
                }
                bit[k].insert(mp(l[order[j]],order[j]));
            }
            j++;
        }
        int sum = 0;
        Q.push(mp(0,n-1));
        while (!Q.empty()) {
            int L = Q.front().first,R = Q.front().second;
            Q.pop();
            if (R-L+1 < i) continue;

            int b = m;
            for (k = R+1; k > 0; k -= k & (-k)) {
                auto it = bit[k].lower_bound(mp(L,0));
                if ((it != bit[k].end()) && (it->second < b)) b = it->second;
            }
            if (b != m) {
                sum += r[b]-l[b]+1;
                Q.push(mp(L,l[b]-1));
                Q.push(mp(r[b]+1,R));
            }
        }
        ans[i] = sum;
    }
    for (i = 1; i <= n; i++) printf("%d\n",ans[i]);

    return 0;
}