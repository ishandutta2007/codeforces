#define DEBUG 1

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
#pragma GCC optimize("Ofast")

int e[100000];
int ds[100000];
int find(int n) {
    if (ds[n] != n) ds[n] = find(ds[n]);
    return ds[n];
}
int pos[100000],seen[100000],num[100000];
vi alive,a2;
int tt[100000];
vi tri[100000];
int e2[100000];
int main() {
    int n,m,s;
    LLI t;
    cin >> n >> m >> s >> t,s--;
    int sw = 0;
    if (m > n/2) sw = 1,m = n-m,s = n-1-s;

    int i,j,k;
    if (m >= 20) {
        alive.resize(n),a2.resize(n);
        for (i = 0; i < n; i++) ds[i] = pos[i] = i,alive[i] = i;
        int as = n;
        for (i = n-1; i >= 0; i--) {
            int as2 = 0;
            for (j = 0; j < as; j++) {
                int u = pos[alive[j]];
                if (u < m) {
                    u += i;
                    if (u >= n) u -= n;
                }
                else {
                    u -= i;
                    if (u < 0) u += n;
                }
                pos[alive[j]] = u;
                if (seen[u] == i+1) ds[find(alive[j])] = find(num[u]);
                else seen[u] = i+1,num[u] = alive[j],a2[as2++] = alive[j];
            }
            swap(alive,a2);
            as = as2;
        }
        for (i = 0; i < as; i++) e[find(alive[i])] = pos[alive[i]];
        for (i = 0; i < n; i++) e[i] = e[find(i)];
    }
    else {
        int sum = 0;
        for (i = 0; i < n; i++) {
            sum += i,sum %= n;
            tt[i] = sum;
            tri[sum].pb(i);
        }
        for (i = 0; i < n; i++) {
            int u = i;
            j = n-1;
            while (j > 0) {
                if (u < m) {
                    u += j;
                    if (u >= n) u -= n;
                    j--;
                }
                else {
                    int mm = 0;
                    for (k = 0; k < m; k++) {
                        int x = (k-u+tt[j]+n) % n;
                        int p = lower_bound(tri[x].begin(),tri[x].end(),j)-tri[x].begin()-1;
                        if (p >= 0) mm = max(mm,tri[x][p]);
                    }
                    u -= tt[j],u += tt[mm];
                    if (u < 0) u += n;
                    if (u >= n) u -= n;
                    j = mm;
                }
            }
            //if((i % 1000)==0)cout<<i<<endl;
            e[i] = u;
        }
    }
    //printArr(e,n);
/*
    debug "here";
    for (i = 0; i < n; i++) {
        int u = i;
        for (j = n-1; j >= 0; j--) {
            if (u < m) {
                u += j;
                if (u >= n) u -= n;
            }
            else {
                u -= j;
                if (u < 0) u += n;
            }
        }
        assert(e[i]==u);
        e[i] = u;
    }
    //printArr(e,n);
    set<int>S;
    for (i=0;i<n;i++)S.insert(e[i]);
    cout<<S.size()<<endl;*/

    int u = s;
    while ((t >= 0) && ((t % n) != (n-1))) {
        if (u < m) {
            u += t % n;
            if (u >= n) u -= n;
        }
        else {
            u -= t % n;
            if (u < 0) u += n;
        }
        t--;
    }
    LLI c = (t+1)/n;
    for (i = 0; i < 50; i++) {
        if (c & (1LL << i)) u = e[u];
        for (j = 0; j < n; j++) e2[j] = e[e[j]];
        for (j = 0; j < n; j++) e[j] = e2[j];
    }
    if (sw) u = n-1-u;
    cout << u+1 << endl;

    return 0;
}