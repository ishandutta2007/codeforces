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

int nxt[200000][26],suff[200000],len[200000],num = 0;
int nxt2[200000][26],suff2[200000],len2[200000],num2 = 0;
LLI dp[200000],dp2[200000];
queue<int> Q;
int in[200000];
vi adjList[200000],adjList2[200000];
int pos2[100001];
set<pii> S[200000];
LLI all[200000];
int disc[200000],parent[200000][18],depth[200000],dd = 0;
int doDFS(int u,int p,int d) {
    int i;
    parent[u][0] = p,depth[u] = d,disc[u] = dd++;
    for (i = 0; i < adjList2[u].size(); i++) {
        int v = adjList2[u][i];
        dp2[v] += dp2[u],doDFS(v,u,d+1);
    }
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
LLI ans = 0;
int doDFS2(int u) {
    int i;
    int p = -1;
    for (auto it = S[u].begin(); it != S[u].end(); it++) {
        all[u] += dp2[it->second];
        if (p != -1) all[u] -= dp2[lca(p,it->second)];
        p = it->second;
    }
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        doDFS2(v);
        if (S[v].size() > S[u].size()) swap(all[u],all[v]),swap(S[u],S[v]);
        for (auto it = S[v].begin(); it != S[v].end(); it++) {
            all[u] += dp2[it->second];
            auto it2 = S[u].lower_bound(*it);
            if (it2 != S[u].end()) all[u] -= dp2[lca(it2->second,it->second)];
            if (it2 != S[u].begin()) {
                it2--;
                all[u] -= dp2[lca(it2->second,it->second)];
                it2++;
            }
            if ((it2 != S[u].end()) && (it2 != S[u].begin())) {
                int x = it2->second;
                it2--;
                all[u] += dp2[lca(it2->second,x)];
            }
            S[u].insert(*it);
        }
    }
    ans += all[u]*dp[u];
    return 0;
}
int main() {
    string s;
    cin >> s;

    int i,n = s.size();
    int l = 0;
    memset(nxt,-1,sizeof(nxt)),len[0] = 0,suff[0] = -1;
    for (i = 0; i < n; i++) {
        int c = ++num,p = l;
        len[c] = len[l]+1;
        while ((p != -1) && (nxt[p][s[i]-'a'] == -1)) nxt[p][s[i]-'a'] = c,p = suff[p];
        if (p == -1) suff[p] = -1;
        else {
            int q = nxt[p][s[i]-'a'];
            if (len[q] == len[p]+1) suff[c] = q;
            else {
                int q2 = ++num;
                len[q2] = len[p]+1,suff[q2] = suff[q];
                copy(nxt[q],nxt[q]+26,nxt[q2]);
                while ((p != -1) && (nxt[p][s[i]-'a'] == q)) nxt[p][s[i]-'a'] = q2,p = suff[p];
                suff[q] = suff[c] = q2;
            }
        }
        l = c;
    }
    l = 0;
    memset(nxt2,-1,sizeof(nxt2)),len2[0] = 0,suff2[0] = -1;
    for (i = n-1; i >= 0; i--) {
        int c = ++num2,p = l;
        len2[c] = len2[l]+1;
        while ((p != -1) && (nxt2[p][s[i]-'a'] == -1)) nxt2[p][s[i]-'a'] = c,p = suff2[p];
        if (p == -1) suff2[p] = -1;
        else {
            int q = nxt2[p][s[i]-'a'];
            if (len2[q] == len2[p]+1) suff2[c] = q;
            else {
                int q2 = ++num2;
                len2[q2] = len2[p]+1,suff2[q2] = suff2[q];
                copy(nxt2[q],nxt2[q]+26,nxt2[q2]);
                while ((p != -1) && (nxt2[p][s[i]-'a'] == q)) nxt2[p][s[i]-'a'] = q2,p = suff2[p];
                suff2[q] = suff2[c] = q2;
            }
        }
        l = c;
    }
    int j;
    num++,num2++;
    fill(in,in+num,0);
    for (i = 0; i < num; i++) {
        for (j = 0; j < 26; j++) {
            if (nxt[i][j] != -1) in[nxt[i][j]]++;
        }
    }
    Q.push(0),dp[0] = 1;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (i = 0; i < 26; i++) {
            if (nxt[u][i] != -1) {
                dp[nxt[u][i]] += dp[u],in[nxt[u][i]]--;
                if (in[nxt[u][i]] == 0) Q.push(nxt[u][i]);
            }
        }
    }
    fill(in,in+num2,0);
    for (i = 0; i < num2; i++) {
        for (j = 0; j < 26; j++) {
            if (nxt2[i][j] != -1) in[nxt2[i][j]]++;
        }
    }
    Q.push(0),dp2[0] = 1;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (i = 0; i < 26; i++) {
            if (nxt2[u][i] != -1) {
                dp2[nxt2[u][i]] += dp2[u],in[nxt2[u][i]]--;
                if (in[nxt2[u][i]] == 0) Q.push(nxt2[u][i]);
            }
        }
    }
    for (i = 0; i < num; i++) ans += dp[i];
    for (i = 1; i < num; i++) adjList[suff[i]].pb(i);
    for (i = 1; i < num2; i++) adjList2[suff2[i]].pb(i);
    doDFS(0,-1,0);
    for (i = 1; (1 << i) < num2; i++) {
        for (j = 0; j < num2; j++) {
            if (parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
            else parent[j][i] = -1;
        }
    }
    logn = i;
    int u = 0;
    pos2[n] = u;
    for (i = n-1; i >= 0; i--) u = nxt2[u][s[i]-'a'],pos2[i] = u;
    u = 0,S[u].insert(mp(disc[pos2[1]],pos2[1]));
    for (i = 0; i < n; i++) {
        u = nxt[u][s[i]-'a'];
        if (i+2 <= n) S[u].insert(mp(disc[pos2[i+2]],pos2[i+2]));
    }
    doDFS2(0);
    printf("%I64d\n",ans);

    return 0;
}