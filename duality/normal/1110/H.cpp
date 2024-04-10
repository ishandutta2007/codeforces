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

string l,r;
int trie[20000][10],leaf[20000][805],fail[20000],nxt[20000][10],num = 0;
queue<int> Q;
int insert(string s,int l) {
    int i,u = 0,f = 0;
    for (i = 0; i < s.size(); i++) {
        if ((s[i] == '0') && !f) continue;
        else f = 1;
        if (trie[u][s[i]-'0'] == -1) trie[u][s[i]-'0'] = ++num;
        u = trie[u][s[i]-'0'];
    }
    leaf[u][l]++;
    return 0;
}
int insertAll(string c,int x,int y) {
    if (x && y) {
        insert(c,l.size()-c.size());
        return 0;
    }
    if (c.size() == l.size()) return 0;

    int i;
    c += '0';
    for (i = 0; i < 10; i++) {
        c.back() = '0'+i;
        if (!x && (i < l[c.size()-1]-'0')) continue;
        if (!y && (i > r[c.size()-1]-'0')) continue;
        insertAll(c,x | (i > l[c.size()-1]-'0'),y | (i < r[c.size()-1]-'0'));
    }
    return 0;
}
int dp[2001][20000];
int main() {
    int n;
    cin >> l >> r >> n;
    r = "0" + r;

    int i,j,k;
    for (i = l.size()-1; i >= 0; i--) {
        if (l[i] == '0') l[i] = '9';
        else {
            l[i]--;
            break;
        }
    }
    for (i = r.size()-1; i >= 0; i--) {
        if (r[i] == '9') r[i] = '0';
        else {
            r[i]++;
            break;
        }
    }
    while (l.size() < r.size()) l = "0" + l;
    memset(trie,-1,sizeof(trie));
    insertAll("",0,0);
    for (i = 0; i < 10; i++) {
        if (trie[0][i] != -1) nxt[0][i] = trie[0][i],fail[trie[0][i]] = 0,Q.push(trie[0][i]);
        else nxt[0][i] = trie[0][i] = 0;
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (i = 0; i < 10; i++) {
            if (trie[u][i] != -1) {
                fail[trie[u][i]] = nxt[fail[u]][i];
                for (j = 0; j < 805; j++) leaf[trie[u][i]][j] += leaf[nxt[fail[u]][i]][j];
                nxt[u][i] = trie[u][i],Q.push(trie[u][i]);
            }
            else nxt[u][i] = nxt[fail[u]][i];
        }
    }
    num++;
    for (i = 0; i < num; i++) {
        for (j = 1; j < 805; j++) leaf[i][j] += leaf[i][j-1];
    }
    for (i = n-1; i >= 0; i--) {
        for (j = 0; j < num; j++) {
            for (k = 0; k < 10; k++) dp[i][j] = max(dp[i][j],dp[i+1][nxt[j][k]]+leaf[nxt[j][k]][min(n-i-1,804)]);
        }
    }
    printf("%d\n",dp[0][0]);
    int u = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 10; j++) {
            if (dp[i][u] == dp[i+1][nxt[u][j]]+leaf[nxt[u][j]][min(n-i-1,804)]) {
                printf("%d",j),u = nxt[u][j];
                break;
            }
        }
    }
    printf("\n");

    return 0;
}