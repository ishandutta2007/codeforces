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

int n,B;
LLI a[100000],toadd[100000];
int update(int s,int e,int num) {
    int i;
    if (s/B == e/B) {
        for (i = s; i <= e; i++) a[i] += num;
    }
    else {
        for (i = s; i < (s/B+1)*B; i++) a[i] += num;
        for (i = (e/B)*B; i <= e; i++) a[i] += num;
        for (i = s/B+1; i < e/B; i++) toadd[i] += num;
    }
    return 0;
}
int query(int i) {
    return min(a[i]+toadd[i/B],(LLI) n);
}
set<int> S;
int jump[100000];
int main() {
    int i,j;
    int q;
    int t,l,r,x,u,v;
    scanf("%d %d",&n,&q);
    B = sqrt(n);
    for (i = 1; i < n; i++) {
        scanf("%I64d",&a[i]),a[i] = i-a[i]+1;
        if ((i+B-1)/B == (i-a[i]+B-1)/B) {
            S.insert(i);
            if (jump[i-a[i]] == -1) jump[i] = i-a[i];
            else jump[i] = jump[i-a[i]];
        }
        else jump[i] = -1;
    }
    for (i = 0; i < q; i++) {
        scanf("%d",&t);
        if (t == 1) {
            scanf("%d %d %d",&l,&r,&x);
            l--,r--;
            update(l,r,x);
            auto it = S.lower_bound(l);
            while ((it != S.end()) && (*it <= r)) {
                int q = query(*it);
                if ((*it+B-1)/B != (*it-q+B-1)/B) {
                    jump[*it] = -1;
                    it = S.erase(it);
                }
                else {
                    if (jump[*it-q] == -1) jump[*it] = *it-q;
                    else jump[*it] = jump[*it-q];
                    it++;
                }
            }
            for (j = r; j < min((r/B+1)*B+2,n); j++) {
                if ((j+B-1)/B == (j-query(j)+B-1)/B) {
                    if (jump[j-query(j)] == -1) jump[j] = j-query(j);
                    else jump[j] = jump[j-query(j)];
                }
                else jump[j] = -1;
            }
        }
        else {
            scanf("%d %d",&u,&v);
            u--,v--;
            while (u != v) {
                if (u < v) swap(u,v);
                if (jump[u] == -1) u = max(u-query(u),0);
                else {
                    if ((u+B-1)/B != (v+B-1)/B) u = max(jump[u]-query(jump[u]),0);
                    else {
                        int pu = max(jump[u]-query(jump[u]),0);
                        int pv = (jump[v] == -1) ? max(v-query(v),0):max(jump[v]-query(jump[v]),0);
                        if (pu != pv) u = pu,v = pv;
                        else {
                            while (u > v) u = max(u-query(u),0);
                        }
                    }
                }
            }
            printf("%d\n",u+1);
        }
    }

    return 0;
}