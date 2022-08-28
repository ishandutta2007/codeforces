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

int n;
int p[200000],pos[200001],L[1000000],R[1000000],order[1000000];
LLI ans[1000000];
int l[200000],r[200000];
vi S;
struct event { int x,l,r; };
vector<event> ver,hor;
LLI bit1[200001],bit2[200001];
int update(int i,LLI num,LLI *bit) {
    for (i++; i <= n; i += i & (-i)) bit[i] += num;
    return 0;
}
LLI query(int i,LLI *bit) {
    LLI sum = 0;
    for (i++; i > 0; i -= i & (-i)) sum += bit[i];
    return sum;
}
int main() {
    int i;
    int q;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) scanf("%d",&p[i]),pos[p[i]] = i;
    for (i = 0; i < q; i++) scanf("%d %d",&L[i],&R[i]),L[i]--,R[i]--,order[i] = i;

    int j;
    for (i = 0; i < n; i++) {
        while (!S.empty() && (p[S.back()] < p[i])) S.pop_back();
        if (S.empty()) l[i] = -1;
        else l[i] = S.back();
        S.pb(i);
    }
    S.clear();
    for (i = n-1; i >= 0; i--) {
        while (!S.empty() && (p[S.back()] < p[i])) S.pop_back();
        if (S.empty()) r[i] = n;
        else r[i] = S.back();
        S.pb(i);
    }
    for (i = 0; i < n; i++) {
        if (p[i] == 1) continue;
        if (i-l[i] < r[i]-i) {
            int rr = 1e9;
            for (j = 1; j*j < p[i]; j++) {
                if ((p[i] % j) == 0) {
                    int c = p[i]/j;
                    if ((pos[j] > i) && (pos[j] < r[i]) && (pos[c] > i) && (pos[c] < r[i])) rr = min(rr,max(pos[j],pos[c]));
                }
            }
            for (j = i; j > l[i]; j--) {
                if ((p[i] % p[j]) == 0) {
                    int c = p[i]/p[j];
                    if ((pos[c] > j) && (pos[c] < r[i])) rr = min(rr,max(pos[c],i));
                }
                if (rr < 1e9) ver.pb((event){j,rr,r[i]-1});
            }
        }
        else {
            int ll = -1;
            for (j = 1; j*j < p[i]; j++) {
                if ((p[i] % j) == 0) {
                    int c = p[i]/j;
                    if ((pos[j] < i) && (pos[j] > l[i]) && (pos[c] < i) && (pos[c] > l[i])) ll = max(ll,min(pos[j],pos[c]));
                }
            }
            for (j = i; j < r[i]; j++) {
                if ((p[i] % p[j]) == 0) {
                    int c = p[i]/p[j];
                    if ((pos[c] > l[i]) && (pos[c] < j)) ll = max(ll,min(pos[c],i));
                }
                if (ll > -1) hor.pb((event){j,l[i]+1,ll});
            }
        }
    }
    j = 0;
    sort(ver.begin(),ver.end(),[](event a,event b) { return a.x > b.x; });
    sort(hor.begin(),hor.end(),[](event a,event b) { return a.x < b.x; });
    sort(order,order+q,[&](int a,int b) { return L[a] > L[b]; });
    for (i = 0; i < q; i++) {
        int u = order[i];
        while ((j < ver.size()) && (ver[j].x >= L[u])) {
            update(ver[j].l,1,bit2);
            update(ver[j].r+1,-1,bit2);
            update(ver[j].l,1-ver[j].l,bit1);
            update(ver[j].r+1,ver[j].r-ver[j].l+1-(1-ver[j].l),bit1);
            j++;
        }
        ans[u] += query(R[u],bit1)+query(R[u],bit2)*R[u];
    }
    sort(order,order+q,[&](int a,int b) { return R[a] < R[b]; });
    j = 0;
    fill(bit1,bit1+n+1,0);
    fill(bit2,bit2+n+1,0);
    for (i = 0; i < q; i++) {
        int u = order[i];
        while ((j < hor.size()) && (hor[j].x <= R[u])) {
            swap(hor[j].l,hor[j].r);
            hor[j].l = n-hor[j].l-1;
            hor[j].r = n-hor[j].r-1;
            update(hor[j].l,1,bit2);
            update(hor[j].r+1,-1,bit2);
            update(hor[j].l,1-hor[j].l,bit1);
            update(hor[j].r+1,hor[j].r-hor[j].l+1-(1-hor[j].l),bit1);
            j++;
        }
        ans[u] += query(n-L[u]-1,bit1)+query(n-L[u]-1,bit2)*(n-L[u]-1);
    }
    for (i = 0; i < q; i++) printf("%lld\n",ans[i]);

    return 0;
}