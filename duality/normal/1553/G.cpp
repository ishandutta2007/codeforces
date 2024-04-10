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

int f[1000005];
int a[150000];
vi v[1000005];
int root[1000005];
int parent[150000];
int find(int n) {
    if (parent[n] != n) parent[n] = find(parent[n]);
    return parent[n];
}
vpii all;
int main() {
    int i,j,k;
    for (i = 2; i <= 1000004; i++) {
        if (f[i] == 0) {
            for (j = i; j <= 1000004; j += i) f[j] = i;
        }
    }
    
    int n,q;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) {
        scanf("%d",&a[i]);
        int t = a[i];
        while (t > 1) {
            v[f[t]].pb(i);
            t /= f[t];
        }
    }
    
    for (i = 0; i < n; i++) parent[i] = i;
    for (i = 2; i <= 1000004; i++) {
        for (j = 1; j < v[i].size(); j++) {
            int x = find(v[i][j]),y = find(v[i][j-1]);
            if (x != y) parent[x] = y;
        }
    }
    memset(root,-1,sizeof(root));
    for (i = 0; i < n; i++) {
        int t = a[i];
        while (t > 1) {
            root[f[t]] = find(i);
            t /= f[t];
        }
    }
    for (i = 0; i < n; i++) {
        int t = a[i];
        vi p;
        while (t > 1) {
            p.pb(root[f[t]]);
            t /= f[t];
        }
        t = a[i]+1;
        while (t > 1) {
            p.pb(root[f[t]]);
            t /= f[t];
        }
        sort(p.begin(),p.end());
        p.resize(unique(p.begin(),p.end())-p.begin());
        for (j = 0; j < p.size(); j++) {
            for (k = j+1; k < p.size(); k++) all.pb(mp(p[j],p[k]));
        }
    }
    sort(all.begin(),all.end());
    all.resize(unique(all.begin(),all.end())-all.begin());
    
    int s,t;
    for (i = 0; i < q; i++) {
        scanf("%d %d",&s,&t);
        s--,t--;
        if (find(s) == find(t)) printf("0\n");
        else if (binary_search(all.begin(),all.end(),mp(min(find(s),find(t)),max(find(s),find(t))))) printf("1\n");
        else printf("2\n");
    }
    
    return 0;
}