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

vi adjList[500000];
int ans[500001],ans2[500001],ans3[500001];
int parent[500000],height[500000],height2[500000];
int doDFS(int u,int p) {
    int i;
    parent[u] = p,height[u] = 0;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u),height[u] = max(height[u],height[v]+1);
    }
    return 0;
}
int doDFS2(int u,int p,int h) {
    int i;
    int m1 = 0,m2 = 0,mi = -1;
    height2[u] = h;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            if (height[v]+2 >= m1) m2 = m1,m1 = height[v]+2,mi = v;
            else if (height[v]+2 >= m2) m2 = height[v]+2;
        }
    }
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            if (v == mi) doDFS2(v,u,max(h+1,m2));
            else doDFS2(v,u,max(h+1,m1));
        }
    }
    return 0;
}
vi dd[500000];
vector<pair<int,pii> > pp[500000];
int main() {
    int i;
    int n,u,v;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    doDFS(0,-1);
    doDFS2(0,-1,0);

    int j;
    for (i = 0; i < n; i++) {
        vi d;
        for (j = 0; j < adjList[i].size(); j++) {
            int v = adjList[i][j];
            if (v != parent[i]) d.pb(height[v]+1);
            else d.pb(height2[i]);
        }
        sort(d.begin(),d.end());
        printVar(i);
        printArr(d,d.size());
        int p = d.size();
        for (j = d.size()-1; j >= 0; j--) {
            ans[d[j]] = max(ans[d[j]],(int) d.size()-j);
            while ((p > 0) && (d[p-1] > d[j])) p--;
            if ((j < (int) d.size()-1) && (d[j+1] > d[j])) {
                if (p < (int) d.size()-1) ans3[d[j]] = max(ans3[d[j]],(int) d.size()-j);
            }
        }
        dd[i] = d;
    }
    for (i = 1; i < n; i++) {
        vi d;
        for (j = 0; j < adjList[i].size(); j++) {
            int v = adjList[i][j];
            if (v != parent[i]) d.pb(height[v]+1);
        }/*
        for (j = 0; j < adjList[parent[i]].size(); j++) {
            int v = adjList[parent[i]][j];
            if ((v != i) && (v != parent[parent[i]])) d.pb(height[v]+1);
            else if (v == parent[parent[i]]) d.pb(height2[parent[i]]);
        }*/
        sort(d.begin(),d.end());
        for (j = d.size()-1; j >= 0; j--) {
            int p = lower_bound(dd[parent[i]].begin(),dd[parent[i]].end(),d[j])-dd[parent[i]].begin();
            int c = dd[parent[i]].size()-p+d.size()-j;
            if ((p < dd[parent[i]].size()) && (height[i]+1 >= dd[parent[i]][p])) c--;
            ans2[d[j]] = max(ans2[d[j]],c);
            pp[parent[i]].pb(mp(d[j],mp(d.size()-j,height[i]+1)));
        }
        printArr(d,d.size());
        //for (j = d.size()-1; j >= 0; j--) ans2[d[j]] = max(ans2[d[j]],(int) d.size()-j);
        printArr(ans,n+1);
        printArr(ans2,n+1);
        printArr(ans3,n+1);
    }
    for (i = 0; i < n; i++) {
        sort(pp[i].begin(),pp[i].end());
        int k = (int) pp[i].size()-1;
        pii m = mp(0,0);
        for (j = dd[i].size()-1; j >= 0; j--) {
            while ((k >= 0) && (pp[i][k].first >= dd[i][j])) m = max(m,pp[i][k].second),k--;
            ans2[dd[i][j]] = max(ans2[dd[i][j]],(int) dd[i].size()-j+m.first-(dd[i][j] <= m.second));
        }
    }
    for (i = n-1; i >= 0; i--) {
        ans[i] = max(ans[i],ans[i+1]);
        ans2[i] = max(ans2[i],ans2[i+1]);
        ans3[i] = max(ans3[i],ans3[i+1]);
    }
    printArr(ans,n+1);
    printArr(ans2,n+1);
    printArr(ans3,n+1);
    int maxd = 0;
    for (i = 0; i < n; i++) maxd = max(maxd,(int) adjList[i].size());
    int diam = 0;
    for (i = 0; i < n; i++) diam = max(diam,max(height2[i],height[i]));
    for (i = 1; i <= n; i++) {
        if (i == 1) printf("%d ",maxd+1);
        else {
            int aa = 1;
            if (!(i & 1)) aa = max(aa,ans[i/2]),aa = max(aa,ans2[i/2]);
            else aa = max(aa,ans[(i+1)/2]),aa = max(aa,ans3[(i-1)/2]);
            if (i <= diam) aa = max(aa,2);
            printf("%d ",aa);
        }
    }
    printf("\n");

    return 0;
}