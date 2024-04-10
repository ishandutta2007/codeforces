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

int t[1000000];
vi adjList[1000000];
list<int> output[1000000][2];
int p[1000000];
int size[1000000];
int doDFS(int u) {
    int i;
    int h = -1;
    vi ret;
    size[u] = adjList[u].empty();
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        ret.pb(doDFS(v));
        size[u] += size[v];
        if ((h == -1) || (size[v] > size[h])) h = v;
    }
    if (h == -1) {
        p[u] = u;
        output[u][!(t[u]-4)].pb(u);
        return t[u]-4;
    }
    else if (adjList[u].size() == 1) {
        p[u] = p[adjList[u][0]];
        swap(output[p[u]][0],output[p[u]][1]);
        //for (i = 0; i < output[p[u]].size(); i++) output[p[u]][i].second ^= 1;
        /*printVar(u);
        for (i = 0; i < output[p[u]].size(); i++){
            cout<<output[p[u]][i].first<<","<<output[p[u]][i].second<<endl;
        }*/
        return !ret[0];
    }
    else {
        p[u] = p[h];
        int other = (h == adjList[u][0]);
        if (t[u] == 0) {
            if (ret[other] == 0) output[p[u]][0].splice(output[p[u]][0].end(),output[p[u]][1]);
        }
        else if (t[u] == 1) {
            if (ret[other] == 1) output[p[u]][1].splice(output[p[u]][1].end(),output[p[u]][0]);
        }
        else if (t[u] == 2) {
            if (ret[other] == 1) swap(output[p[u]][0],output[p[u]][1]);
        }
        int pp = p[adjList[u][other]];
        for (auto it = output[pp][0].begin(); it != output[pp][0].end(); it++) {
            if (t[u] == 0) output[p[u]][0].pb(*it);
            else if (t[u] == 1) output[p[u]][ret[!other]].pb(*it);
            else output[p[u]][ret[!other]].pb(*it);
        }
        for (auto it = output[pp][1].begin(); it != output[pp][1].end(); it++) {
            if (t[u] == 0) output[p[u]][ret[!other]].pb(*it);
            else if (t[u] == 1) output[p[u]][1].pb(*it);
            else output[p[u]][!ret[!other]].pb(*it);
        }
        output[pp][0].clear(),output[pp][1].clear();
        /*printVar(u);
        for (i = 0; i < output[p[u]].size(); i++){
            cout<<output[p[u]][i].first<<","<<output[p[u]][i].second<<endl;
        }*/
        if (t[u] == 0) return ret[0] & ret[1];
        else if (t[u] == 1) return ret[0] | ret[1];
        else return ret[0] ^ ret[1];
    }
}
int main() {
    int i;
    int n;
    char s[4];
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%s",s);
        if (s[0] == 'A') {
            t[i] = 0;
            adjList[i].resize(2);
            scanf("%d %d",&adjList[i][0],&adjList[i][1]);
            adjList[i][0]--,adjList[i][1]--;
        }
        else if (s[0] == 'O') {
            t[i] = 1;
            adjList[i].resize(2);
            scanf("%d %d",&adjList[i][0],&adjList[i][1]);
            adjList[i][0]--,adjList[i][1]--;
        }
        else if (s[0] == 'X') {
            t[i] = 2;
            adjList[i].resize(2);
            scanf("%d %d",&adjList[i][0],&adjList[i][1]);
            adjList[i][0]--,adjList[i][1]--;
        }
        else if (s[0] == 'N') {
            t[i] = 3;
            adjList[i].resize(1);
            scanf("%d",&adjList[i][0]);
            adjList[i][0]--;
        }
        else {
            scanf("%d",&t[i]);
            t[i] += 4;
        }
    }
    doDFS(0);
    vpii ans;
    for (auto it = output[p[0]][0].begin(); it != output[p[0]][0].end(); it++) ans.pb(mp(*it,0));
    for (auto it = output[p[0]][1].begin(); it != output[p[0]][1].end(); it++) ans.pb(mp(*it,1));
    sort(ans.begin(),ans.end());
    for (i = 0; i < ans.size(); i++) printf("%d",ans[i].second);
    printf("\n");

    return 0;
}