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

string ans;
int query(string s) {
    int i,j,k,a;
    cout << "? " << s << endl;
    cin >> k;
    for (i = 0; i < k; i++) {
        cin >> a,a--;
        for (j = 0; j < s.size(); j++) ans[a+j] = s[j];
    }
    return k;
}
int main() {
    int i,j;
    int t,n;
    cin >> t;
    while (t--) {
        cin >> n;

        vector<string> poss;
        ans = "";
        for (i = 0; i < n; i++) ans += '?';
        if (n == 4) {
            if (query("HC")+query("CO")+query("HO") == 0) query("CCC"),query("HHH"),query("OOO");
            for (i = 0; i < 81; i++) {
                int t = i;
                string s;
                for (j = 0; j < 4; j++) {
                    if ((t % 3) == 0) s += 'C';
                    else if ((t % 3) == 1) s += 'H';
                    else s += 'O';
                    t /= 3;
                }
                for (j = 0; j < 4; j++) {
                    if ((ans[j] != '?') && (ans[j] != s[j])) break;
                }
                if (j == 4) {
                    for (j = 0; j < 4; j++) {
                        string t = s.substr(j,2);
                        if ((ans.substr(j,2) == "??") && ((t == "HC") || (t == "CO") || (t == "HO"))) break;
                        t = s.substr(j,3);
                        if ((ans.substr(j,3) == "???") && ((t == "CCC") || (t == "HHH") || (t == "OOO"))) break;
                    }
                    if (j == 4) poss.pb(s);
                }
            }
        }
        else {
            query("CC"),query("CH"),query("CO"),query("HO"),query("OH");
            for (i = 0; i < n-2; i++) {
                if ((ans[i] != '?') && (ans[i] != 'C') && (ans[i+1] == '?')) ans[i+1] = ans[i];
            }
            for (i = n-3; i >= 0; i--) {
                if ((ans[i+1] != '?') && (ans[i+1] != 'C') && (ans[i] == '?')) ans[i] = ans[i+1];
            }
            string s = ans;
            for (i = 0; i < n-1; i++) {
                if (s[i] == '?') s[i] = 'H';
                else break;
            }
            if (s[n-1] == '?') s[n-1] = s[n-2];
            poss.pb(s),s = ans;
            for (i = 0; i < n-1; i++) {
                if (s[i] == '?') s[i] = 'H';
                else break;
            }
            if (s[n-1] == '?') s[n-1] = 'C';
            poss.pb(s),s = ans;
            for (i = 0; i < n-1; i++) {
                if (s[i] == '?') s[i] = 'O';
                else break;
            }
            if (s[n-1] == '?') s[n-1] = s[n-2];
            poss.pb(s),s = ans;
            for (i = 0; i < n-1; i++) {
                if (s[i] == '?') s[i] = 'O';
                else break;
            }
            if (s[n-1] == '?') s[n-1] = 'C';
            poss.pb(s);
        }
        for (i = 0; i < poss.size()-1; i++) {
            if (query(poss[i]) > 0) break;
        }
        cout << "! " << poss[i] << endl;
        cin >> i;
    }

    return 0;
}