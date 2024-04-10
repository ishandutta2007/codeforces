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

string S;
int p[300000];
vi SS;
deque<char> s[300000];
int c = 0;
int findAns(int l,int r) {
    if (l > r) return c++;
    else if (l+1 == r) {
        s[c].pb('('),s[c].pb(')');
        return c++;
    }

    if (p[l] == r) {
        int x = findAns(l+1,r-1);
        s[x].push_front('('),s[x].pb(')');
        return x;
    }
    else {
        int i;
        int x = findAns(l,p[l]),y = findAns(p[l]+1,r);
        for (i = 0; i < min(s[x].size(),s[y].size()); i++) {
            if (s[x][i] < s[y][i]) {
                if (s[x].size() <= s[y].size()) {
                    while (!s[x].empty()) s[y].push_front(s[x].back()),s[x].pop_back();
                    return y;
                }
                else {
                    while (!s[y].empty()) s[x].pb(s[y].front()),s[y].pop_front();
                    return x;
                }
            }
            else if (s[x][i] > s[y][i]) return y;
        }
        if (s[x].size() <= s[y].size()) {
            while (!s[x].empty()) s[y].push_front(s[x].back()),s[x].pop_back();
            return y;
        }
        else return y;
    }
}
int main() {
    cin >> S;

    int i,c = 0,m = 0;
    vi v;
    for (i = 0; i < S.size(); i++) {
        if (S[i] == '(') c++,SS.pb(i);
        else {
            if (!SS.empty()) p[SS.back()] = i,p[i] = SS.back(),SS.pop_back();
            c--;
        }
        if (c < m) m = c,v.pb(i);
    }
    string ans = ")";
    for (i = 1; i < v.size(); i++) {
        int x = findAns(v[i-1]+1,v[i]-1);
        while (!s[x].empty()) ans += s[x][0],s[x].pop_front();
        ans += ')';
    }
    for (i = 0; i < c-m; i++) ans += '(';
    cout << ans << endl;

    return 0;
}