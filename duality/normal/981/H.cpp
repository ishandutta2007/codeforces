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
#define MOD 998244353

namespace NTT {
    int mbase,base,root;
    int w[1 << 19];
    int rev[1 << 19];
    int modPow(int b,int e) {
        int r = 1;
        while (e > 0) {
            if (e & 1) r = ((LLI) r*b) % MOD;
            e >>= 1;
            b = ((LLI) b*b) % MOD;
        }
        return r;
    }
    int setBase(int nbase) {
        int i,j;
        mbase = 1;
        while (!(MOD & (1 << mbase))) mbase++;
        root = 2;
        while ((modPow(root,1 << mbase) != 1) || (modPow(root,1 << (mbase-1)) == 1)) root++;
        base = nbase;
        for (i = 0; i < (1 << base); i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (base-1));
        w[0] = 0,w[1] = 1;
        for (i = 1; i < nbase; i++) {
            int z = modPow(root,1 << (mbase-i-1));
            for (j = (1 << (i-1)); j < (1 << i); j++) w[j << 1] = w[j],w[(j << 1)|1] = ((LLI) w[j]*z) % MOD;
        }
        return 0;
    }
    int FFT(vector<int> &a,int inv) {
        int i,j,k;
        int l = 0;
        while ((1 << l) < a.size()) l++;
        int s = base - l;
        for (i = 0; i < a.size(); i++) {
            if (i < (rev[i] >> s)) swap(a[i],a[rev[i] >> s]);
        }
        for (k = 1; k < a.size(); k <<= 1) {
            for (i = 0; i < a.size(); i += (k << 1)) {
                for (j = 0; j < k; j++) {
                    int z = ((LLI) a[i+j+k]*w[j+k]) % MOD;
                    a[i+j+k] = a[i+j]-z,a[i+j] += z;
                    if (a[i+j+k] < 0) a[i+j+k] += MOD;
                    if (a[i+j] >= MOD) a[i+j] -= MOD;
                }
            }
        }
        return 0;
    }
    vector<int> multiply(vector<int> A,vector<int> B) {
        int i,n = 1;
        while (n < A.size()+B.size()-1) n <<= 1;
        vector<int> a(n,0),b(n,0);
        for (i = 0; i < A.size(); i++) a[i] = A[i];
        for (i = 0; i < B.size(); i++) b[i] = B[i];
        FFT(a,0),FFT(b,0);
        int x = modPow(n,MOD-2);
        for (i = 0; i < n; i++) a[i] = ((((LLI) a[i]*b[i]) % MOD)*x) % MOD;
        reverse(a.begin()+1,a.end()),FFT(a,1),a.resize(A.size()+B.size()-1);
        return a;
    }
}

vi adjList[100000];
int parent[100000],size[100000];
int doDFS(int u,int p) {
    int i;
    parent[u] = p,size[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) size[u] += doDFS(v,u);
    }
    return size[u];
}
int down[100000],up[100000];
vi mult(vector<vi> &v,int l,int r) {
    if (l == r) return v[l];
    else if (l > r) return vi(1,1);
    int i;
    int mid = (l+r) / 2;
    vi ll = mult(v,l,mid),rr = mult(v,mid+1,r),ans;
    vi temp = NTT::multiply(ll,rr);
    for (i = 0; i < temp.size(); i++) ans.pb(temp[i] % MOD);
    return ans;
}
vi p[100000];
int ans = 0;
int doDFS2(int u,int p) {
    int i;
    int s = 0;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            doDFS2(v,u);
            down[u] += down[v],down[u] %= MOD;
            ans += ((LLI) down[v]*up[v]) % MOD,ans %= MOD;
            ans += ((LLI) s*down[v]) % MOD,ans %= MOD;
            s += down[v],s %= MOD;
        }
    }
    return 0;
}
int main() {
    int i;
    int n,k,a,b;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&a,&b);
        a--,b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    if (k == 1) {
        printf("%d\n",((LLI) n*(n-1)/2) % MOD);
        return 0;
    }

    int j,l;
    doDFS(0,-1);
    NTT::setBase(17);
    for (i = 0; i < n; i++) {
        vector<vi> vv;
        for (j = 0; j < adjList[i].size(); j++) {
            int v = adjList[i][j];
            if (v != parent[i]) {
                vi vvv(2);
                vvv[0] = size[v],vvv[1] = 1;
                vv.pb(vvv);
            }
            else {
                vi vvv(2);
                vvv[0] = n-size[i],vvv[1] = 1;
                vv.pb(vvv);
            }
        }
        p[i] = mult(vv,0,(int) vv.size()-1);
    }
    for (i = 0; i < n; i++) {
        map<int,int> M;
        vi poly = p[i];
        if (i > 0) {
            for (j = poly.size()-1; j >= 1; j--) poly[j-1] += MOD-(((LLI) (n-size[i])*poly[j]) % MOD),poly[j-1] %= MOD;
            for (j = 0; j < poly.size()-1; j++) poly[j] = poly[j+1];
            poly.pop_back();
        }
        LLI c = 1;
        for (j = 0; j < poly.size(); j++) {
            down[i] += (poly[poly.size()-j-1]*c) % MOD,down[i] %= MOD;
            c *= k-j,c %= MOD;
        }
        M[n-size[i]] = down[i];
        for (j = 0; j < adjList[i].size(); j++) {
            int v = adjList[i][j];
            if (v != parent[i]) {
                if (M.count(size[v])) up[v] = M[size[v]];
                else {
                    vi poly = p[i];
                    for (l = poly.size()-1; l >= 1; l--) poly[l-1] += MOD-(((LLI) size[v]*poly[l]) % MOD),poly[l-1] %= MOD;
                    for (l = 0; l < poly.size()-1; l++) poly[l] = poly[l+1];
                    poly.pop_back();
                    LLI c = 1;
                    for (l = 0; l < poly.size(); l++) {
                        up[v] += (poly[poly.size()-l-1]*c) % MOD,up[v] %= MOD;
                        c *= k-l,c %= MOD;
                    }
                    M[size[v]] = up[v];
                }
            }
        }
    }
    doDFS2(0,-1);
    printf("%d\n",ans);

    return 0;
}