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

vi adjList[100];
int label[100][100];
string dp[100];
int size[100];
bool comp(string a,string b) {
    if (a.size() == b.size()) {
        int i;
        for (i = (int) a.size()-1; i >= 0; i--) {
            if (a[i] != b[i]) return a[i] < b[i];
        }
        return 0;
    }
    else return a.size() < b.size();
}
bool comp2(pair<string,int> a,pair<string,int> b) {
    if (a.first == b.first) return a.second < b.second;
    else return comp(a.first,b.first);
}
string add1(string s) {
    int i;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            s[i] = '1';
            break;
        }
        else s[i] = '0';
    }
    if (i == s.size()) s += '1';
    return s;
}
int doDFS(int u,int p) {
    int i,j;
    size[u] = 1;
    vector<string> c;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u),size[u] += size[v],c.pb(add1(dp[v]));
    }
    sort(c.begin(),c.end(),comp);
    dp[u] = string(size[u],'0');
    for (i = size[u]-1; i >= 0; i--) {
        vector<string> cc = c;
        for (j = size[u]-1; j >= 0; j--) {
            if (cc.empty()) break;
            if ((j > i) ? dp[u][j]-'0':(j < i)) {
                if (cc.back().size() < j+1) cc.pop_back();
                else if (cc.back().size() > j+1) break;
                else {
                    string s = cc.back();
                    cc.pop_back(),s.pop_back();
                    while (!s.empty() && (s.back() == '0')) s.pop_back();
                    if (!s.empty()) {
                        int p = lower_bound(cc.begin(),cc.end(),s,comp)-cc.begin();
                        cc.insert(cc.begin()+p,s);
                    }
                }
            }
        }
        if (!cc.empty()) dp[u][i] = '1';
    }
    while (!dp[u].empty() && (dp[u].back() == '0')) dp[u].pop_back();
    return 0;
}
int doDFS2(int u,int p,string s) {
    int i;
    if (p != -1) {
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '1') break;
            else s[i] = '1';
        }
        label[u][p] = i+1,s[i] = '0';
        while (!s.empty() && (s.back() == '0')) s.pop_back();
    }
    vector<pair<string,int> > cc;
    vector<string> ss(adjList[u].size());
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) cc.pb(mp(add1(dp[v]),i));
    }
    sort(cc.begin(),cc.end(),comp2);
    for (i = (int) s.size()-1; i >= 0; i--) {
        if (cc.empty()) break;
        if (s[i] == '1') {
            if (cc.back().first.size() < i+1) {
                while (ss[cc.back().second].size() < i+1) ss[cc.back().second] += '0';
                ss[cc.back().second][i] = '1';
                cc.pop_back();
            }
            else {
                while (ss[cc.back().second].size() < i+1) ss[cc.back().second] += '0';
                ss[cc.back().second][i] = '1';
                pair<string,int> s = cc.back();
                cc.pop_back(),s.first.pop_back();
                while (!s.first.empty() && (s.first.back() == '0')) s.first.pop_back();
                if (!s.first.empty()) {
                    int p = lower_bound(cc.begin(),cc.end(),s,comp2)-cc.begin();
                    cc.insert(cc.begin()+p,s);
                }
            }
        }
    }
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS2(v,u,ss[i]);
    }
    return 0;
}
int poss[100];
int doDFS3(int u,int p) {
    int i;
    poss[u] = 0;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS3(v,u);
    }
    return 0;
}
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

    int j;
    doDFS(0,-1);
    doDFS2(0,-1,dp[0]);
    for (i = 0; i < n; i++) poss[i] = 1;
    while (1) {
        pii p = mp(-1,-1);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if ((label[i][j] > 0) && poss[i] && poss[j]) {
                    if (p == mp(-1,-1)) p = mp(i,j);
                    else if (label[i][j] > label[p.first][p.second]) p = mp(i,j);
                }
            }
        }
        if (p == mp(-1,-1)) {
            for (i = 0; i < n; i++) {
                if (poss[i]) break;
            }
            cout << "! " << i+1 << endl;
            break;
        }
        else {
            int r;
            cout << "? " << p.first+1 << " " << p.second+1 << endl;
            cin >> r,r--;
            doDFS3(p.first^p.second^r,r);
        }
    }

    return 0;
}