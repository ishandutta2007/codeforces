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
string w[3000],w2[3000];
int lps[3001];
int check(string s,string t) {
    int k;
    for (k = 0; k < n; k++) {
        int i,j = -1;
        string S = w[k],T = s;
        lps[0] = -1;
        for (i = 0; i < T.size(); i++) {
            while ((j >= 0) && (T[i] != T[j])) j = lps[j];
            lps[i+1] = ++j;
        }
        j = 0;
        int f = -1;
        for (i = 0; i < S.size(); i++) {
            while ((j >= 0) && (S[i] != T[j])) j = lps[j];
            j++;
            if (j == T.size()) {
                f = i-j+1;
                break;
            }
        }
        if (f != -1) {
            for (j = 0; j < s.size(); j++) w[k][j+f] = t[j];
        }
        if (w[k] != w2[k]) return 0;
    }
    return 1;
}
int main() {
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin.tie(0);

    int i;
    cin >> n;
    for (i = 0; i < n; i++) cin >> w[i];
    for (i = 0; i < n; i++) cin >> w2[i];

    int j;
    string sc,tc,sl,sr,tl,tr;
    for (i = 0; i < n; i++) {
        vi pos;
        for (j = 0; j < w[i].size(); j++) {
            if (w[i][j] != w2[i][j]) pos.pb(j);
        }
        if (!pos.empty()) {
            string sc2 = w[i].substr(pos[0],pos.back()-pos[0]+1);
            string tc2 = w2[i].substr(pos[0],pos.back()-pos[0]+1);
            string sl2,sr2,tl2,tr2;
            for (j = pos[0]-1; j >= 0; j--) sl2.pb(w[i][j]),tl2.pb(w2[i][j]);
            for (j = pos.back()+1; j < w[i].size(); j++) sr2.pb(w[i][j]),tr2.pb(w2[i][j]);
            if (sc == "") sc = sc2,tc = tc2,sl = sl2,sr = sr2,tl = tl2,tr = tr2;
            else {
                if ((sc2 != sc) || (tc2 != tc)) {
                    cout << "NO" << endl;
                    return 0;
                }

                for (j = 0; j < min(sl.size(),sl2.size()); j++) {
                    if (sl[j] != sl2[j]) break;
                }
                sl.resize(j);
                for (j = 0; j < min(sr.size(),sr2.size()); j++) {
                    if (sr[j] != sr2[j]) break;
                }
                sr.resize(j);
                for (j = 0; j < min(tl.size(),tl2.size()); j++) {
                    if (tl[j] != tl2[j]) break;
                }
                tl.resize(j);
                for (j = 0; j < min(tr.size(),tr2.size()); j++) {
                    if (tr[j] != tr2[j]) break;
                }
                tr.resize(j);
            }
        }
    }
    string cands,candt;
    for (i = (int) sl.size()-1; i >= 0; i--) cands += sl[i];
    cands += sc + sr;
    for (i = (int) tl.size()-1; i >= 0; i--) candt += tl[i];
    candt += tc + tr;
    if (check(cands,candt)) {
        cout << "YES" << endl;
        cout << cands << endl << candt << endl;
    }
    else cout << "NO" << endl;

    return 0;
}