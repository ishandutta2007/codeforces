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

string s[1000000];
int trie[1000001][26],node[1000000],fail[1000001],num = 0;
int m1[1000001],m2[1000001];
bool comp(int a,int b) {
    return ((a == -1) ? 0:s[a].size()) < ((b == -1) ? 0:s[b].size());
}
queue<int> Q;
vi adjList[1000001];
int disc[1000001],fin[1000001],num2 = 0;
int doDFS(int u) {
    int i;
    disc[u] = num2++;
    for (i = 0; i < adjList[u].size(); i++) doDFS(adjList[u][i]);
    fin[u] = num2;
    return 0;
}
int order[1000000];
int bad[1000000];
int main() {
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin.tie(0);

    int i,j;
    int n;
    cin >> n;
    memset(trie,-1,sizeof(trie));
    memset(m1,-1,sizeof(m1));
    memset(m2,-1,sizeof(m2));
    for (i = 0; i < n; i++) {
        cin >> s[i];
        int u = 0;
        for (j = 0; j < s[i].size(); j++) {
            if (trie[u][s[i][j]-'a'] == -1) trie[u][s[i][j]-'a'] = ++num;
            u = trie[u][s[i][j]-'a'];
        }
        node[i] = u,m1[u] = i;
    }

    for (i = 0; i < 26; i++) {
        if (trie[0][i] != -1) Q.push(trie[0][i]);
        else trie[0][i] = 0;
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (i = 0; i < 26; i++) {
            if (trie[u][i] != -1) {
                int v = fail[u];
                while (trie[v][i] == -1) v = fail[v];
                v = trie[v][i];
                fail[trie[u][i]] = v;
                if (!comp(m1[v],m1[trie[u][i]])) m2[trie[u][i]] = m1[trie[u][i]],m1[trie[u][i]] = m1[v];
                else if (!comp(m1[v],m2[trie[u][i]])) m2[trie[u][i]] = m1[v];
                if (!comp(m2[v],m1[trie[u][i]])) m2[trie[u][i]] = m1[trie[u][i]],m1[trie[u][i]] = m2[v];
                else if (!comp(m2[v],m2[trie[u][i]])) m2[trie[u][i]] = m2[v];
                Q.push(trie[u][i]);
            }
        }
    }

    LLI ans = 0;
    for (i = 1; i <= num; i++) adjList[fail[i]].pb(i);
    doDFS(0);
    for (i = 0; i < n; i++) order[i] = i;
    sort(order,order+n,comp);
    for (i = 0; i < n; i++) {
        int x = order[i],u = 0;
        vector<pair<pii,int> > vv;
        for (j = 0; j < s[x].size(); j++) {
            u = trie[u][s[x][j]-'a'];
            if ((m1[u] != -1) && (m1[u] != x)) vv.pb(mp(mp(j-s[m1[u]].size()+1,-j),m1[u]));
            else if ((m2[u] != -1) && (m2[u] != x)) vv.pb(mp(mp(j-s[m2[u]].size()+1,-j),m2[u]));
        }
        int r = -1;
        sort(vv.begin(),vv.end());
        for (j = 0; j < vv.size(); j++) {
            if (-vv[j].first.second <= r) bad[vv[j].second] = 1;
            else r = -vv[j].first.second;
        }
        vi vv2;
        for (j = 0; j < vv.size(); j++) vv2.pb(disc[node[vv[j].second]]);
        sort(vv2.begin(),vv2.end());
        for (j = 0; j < vv.size(); j++) {
            int p = upper_bound(vv2.begin(),vv2.end(),disc[node[vv[j].second]])-vv2.begin();
            if ((p < vv2.size()) && (vv2[p] < fin[node[vv[j].second]])) bad[vv[j].second] = 1;
        }
        for (j = 0; j < vv.size(); j++) {
            if (!bad[vv[j].second]) ans++,bad[vv[j].second] = 1;
        }
        for (j = 0; j < vv.size(); j++) bad[vv[j].second] = 0;
    }
    printf("%I64d\n",ans);

    return 0;
}