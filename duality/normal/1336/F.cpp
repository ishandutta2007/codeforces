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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

vi adjList[150000];
int s[150000],t[150000];
int parent[150000][18],depth[150000],disc[150000],fin[150000],order[150000],num = 0;
int doDFS(int u,int p,int d) {
    int i;
    parent[u][0] = p,depth[u] = d,disc[u] = num++,order[num-1] = u;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u,d+1);
    }
    fin[u] = num;
    return 0;
}
int logn;
int lca(int u,int v) {
    if (depth[u] < depth[v]) swap(u,v);
    int i;
    for (i = logn-1; i >= 0; i--) {
        if ((parent[u][i] != -1) && (depth[parent[u][i]] >= depth[v])) u = parent[u][i];
    }
    if (u == v) return u;
    for (i = logn-1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) u = parent[u][i],v = parent[v][i];
    }
    return parent[u][0];
}
int getAnc(int u,int k) {
    int i;
    for (i = logn-1; i >= 0; i--) {
        if (k & (1 << i)) u = parent[u][i];
    }
    return u;
}
vector<pair<pii,pii> > other;
int paths[150000];
LLI ans;
int doDFS2(int u,int p) {
    int i;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            doDFS2(v,u);
            paths[u] += paths[v];
        }
    }
    ans += (LLI) paths[u]*(paths[u]-1)/2;
    return 0;
}
vpii x,y,ee;
set<int> Sx,Sy;
int posx[150000],posy[150000];
ordered_set *Sx2[150000],*Sy2[150000];
int temp[150001];
LLI getAns(int n,int m,int k) {
    int i,j;
    ans = 0;
    fill(paths,paths+n,0),other.clear();
    for (i = 0; i < m; i++) {
        int u = s[i],v = t[i],l = lca(u,v);
        if (depth[u]-depth[l] >= k) {
            int x = getAnc(u,depth[u]-depth[l]-k+1);
            paths[u]++,paths[x]--;
        }
        if (depth[v]-depth[l] >= k) {
            int x = getAnc(v,depth[v]-depth[l]-k+1);
            paths[v]++,paths[x]--;
        }
        if ((l != u) && (l != v)) {
            int uu = getAnc(u,depth[u]-depth[l]-1);
            int vv = getAnc(v,depth[v]-depth[l]-1);
            if (uu > vv) swap(uu,vv),swap(u,v);
            other.pb(mp(mp(uu,vv),mp(u,v)));
        }
    }
    doDFS2(0,-1);
    sort(other.begin(),other.end());
    i = 0;
    while (i < other.size()) {
        j = i;
        while ((j < other.size()) && (other[j].first == other[i].first)) j++;
        if (j == i+1) {
            i = j;
            continue;
        }
        int e = j,dd = depth[other[e-1].first.first]-1;
        x.clear(),y.clear(),ee.clear(),Sx.clear(),Sy.clear();
        for (; i < e; i++) {
            x.pb(mp(disc[other[i].second.first],i));
            y.pb(mp(disc[other[i].second.second],i));
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        for (i = 1; i < x.size(); i++) {
            int l = lca(order[x[i-1].first],order[x[i].first]);
            ee.pb(mp(min(depth[l]-dd,k-1),i));
            Sx.insert(i);
        }
        Sx.insert(0),Sx.insert(x.size());
        Sy.insert(0),Sy.insert(y.size());
        for (i = 1; i < y.size(); i++) {
            int l = lca(order[y[i-1].first],order[y[i].first]);
            if (k-(depth[l]-dd)-1 > 0) ee.pb(mp(k-(depth[l]-dd)-1,-i));
        }
        for (i = 0; i < x.size(); i++) {
            int q = lower_bound(y.begin(),y.end(),mp(disc[other[x[i].second].second.second],x[i].second))-y.begin();
            Sx2[i]->clear(),Sx2[i]->insert(q),posx[i] = q;
        }
        for (i = 0; i < y.size(); i++) Sy2[i]->clear();
        for (i = 0; i < y.size(); i++) {
            int q = lower_bound(x.begin(),x.end(),mp(disc[other[y[i].second].second.first],y[i].second))-x.begin();
            Sy2[y.size()-1]->insert(q),posy[i] = q;
        }
        int p = k-1;
        LLI c = 0;
        sort(ee.begin(),ee.end());
        for (i = ee.size()-1; i >= 0; i--) {
            if (ee[i].first <= p) ans += (p-ee[i].first)*c;
            if (ee[i].second > 0) {
                int a = ee[i].second;
                Sx.erase(a);
                auto it = Sx.lower_bound(a);
                int r = *it;
                it--;
                int l = *it;
                if (a-l < r-a) {
                    vi v;
                    for (j = l; j < a; j++) {
                        auto it2 = Sy.upper_bound(posx[j]);
                        int rr = *it2;
                        it2--;
                        int ll = *it2;
                        temp[rr]++,temp[ll]--,v.pb(rr),v.pb(ll);
                    }
                    for (j = 0; j < v.size(); j++) {
                        if (temp[v[j]] != 0) c += temp[v[j]]*(LLI) Sx2[r-1]->order_of_key(v[j]),temp[v[j]] = 0;
                    }
                    for (j = l; j < a; j++) Sx2[r-1]->insert(posx[j]);
                }
                else {
                    vi v;
                    for (j = a; j < r; j++) {
                        auto it2 = Sy.upper_bound(posx[j]);
                        int rr = *it2;
                        it2--;
                        int ll = *it2;
                        temp[rr]++,temp[ll]--,v.pb(rr),v.pb(ll);
                    }
                    for (j = 0; j < v.size(); j++) {
                        if (temp[v[j]] != 0) c += temp[v[j]]*(LLI) Sx2[a-1]->order_of_key(v[j]),temp[v[j]] = 0;
                    }
                    for (j = a; j < r; j++) Sx2[a-1]->insert(posx[j]);
                    swap(Sx2[a-1],Sx2[r-1]);
                }
            }
            else {
                int a = -ee[i].second;
                auto it = Sy.lower_bound(a);
                int r = *it;
                it--;
                int l = *it;
                Sy.insert(a);
                if (a-l < r-a) {
                    vi v;
                    for (j = l; j < a; j++) Sy2[r-1]->erase(posy[j]),Sy2[a-1]->insert(posy[j]);
                    for (j = l; j < a; j++) {
                        auto it2 = Sx.upper_bound(posy[j]);
                        int rr = *it2;
                        it2--;
                        int ll = *it2;
                        temp[rr]--,temp[ll]++,v.pb(rr),v.pb(ll);
                    }
                    for (j = 0; j < v.size(); j++) {
                        if (temp[v[j]] != 0) c += temp[v[j]]*(LLI) Sy2[r-1]->order_of_key(v[j]),temp[v[j]] = 0;
                    }
                }
                else {
                    vi v;
                    for (j = a; j < r; j++) Sy2[r-1]->erase(posy[j]),Sy2[a-1]->insert(posy[j]);
                    swap(Sy2[a-1],Sy2[r-1]);
                    for (j = a; j < r; j++) {
                        auto it2 = Sx.upper_bound(posy[j]);
                        int rr = *it2;
                        it2--;
                        int ll = *it2;
                        temp[rr]--,temp[ll]++,v.pb(rr),v.pb(ll);
                    }
                    for (j = 0; j < v.size(); j++) {
                        if (temp[v[j]] != 0) c += temp[v[j]]*(LLI) Sy2[a-1]->order_of_key(v[j]),temp[v[j]] = 0;
                    }
                }
            }
            p = ee[i].first;
        }
        ans += p*c;
        i = e;
    }
    return ans;
}
int main() {
    int i;
    int n,m,k,u,v;
    scanf("%d %d %d",&n,&m,&k);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    for (i = 0; i < m; i++) scanf("%d %d",&s[i],&t[i]),s[i]--,t[i]--;

    int j;
    doDFS(0,-1,0);
    for (i = 1; (1 << i) < n; i++) {
        for (j = 0; j < n; j++) {
            if (parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
            else parent[j][i] = -1;
        }
    }
    logn = i;
    for (i = 0; i < m; i++) Sx2[i] = new ordered_set,Sy2[i] = new ordered_set;
    printf("%lld\n",getAns(n,m,k)-getAns(n,m,k+1));

    return 0;
}