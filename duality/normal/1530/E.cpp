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

char s[100001];
int occ[26];
int main() {
    int i;
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%s",s);

        memset(occ,0,sizeof(occ));
        for (i = 0; s[i] != '\0'; i++) occ[s[i]-'a']++;
        for (i = 0; i < 26; i++) {
            if (occ[i] == 1) break;
        }
        string t;
        if (i < 26) {
            t += i+'a',occ[i]--;
            for (i = 0; i < 26; i++) {
                while (occ[i] > 0) t += i+'a',occ[i]--;
            }
            cout << t << endl;
            continue;
        }
        while (1) {
            vi v;
            for (i = 0; i < 26; i++) {
                if (occ[i] > 0) v.pb(i);
            }
            if (v.empty()) break;
            else if (v.size() == 1) t += v[0]+'a',occ[v[0]]--;
            else {
                if ((t.size() > 1) && (t.back() == t[0]) && (v[0] == t[0]-'a')) t += v[1]+'a',occ[v[1]]--;
                else t += v[0]+'a',occ[v[0]]--;
            }
        }
        for (i = 1; i < t.size()-1; i++) {
            if ((t[i] == t[0]) && (t[i+1] == t[1])) break;
        }
        if (i == t.size()-1) cout << t << endl;
        else {
            memset(occ,0,sizeof(occ));
            for (i = 0; s[i] != '\0'; i++) occ[s[i]-'a']++;
            vi v;
            for (i = 0; i < 26; i++) {
                if (occ[i] > 0) v.pb(i);
            }
            if (v.size() >= 3) {
                string t;
                t += v[0]+'a',occ[v[0]]--;
                t += v[1]+'a',occ[v[1]]--;
                if (occ[v[0]] > 0) {
                    while (occ[v[0]] > 0) t += v[0]+'a',occ[v[0]]--;
                    t += v[2]+'a',occ[v[2]]--;
                }
                for (i = 0; i < 26; i++) {
                    while (occ[i] > 0) t += i+'a',occ[i]--;
                }
                cout << t << endl;
            }
            else if (v.size() == 1) {
                string t;
                while (occ[v[0]] > 0) t += v[0]+'a',occ[v[0]]--;
                cout << t << endl;
            }
            else {
                string t;
                t += v[0]+'a',occ[v[0]]--;
                while (occ[v[1]] > 0) t += v[1]+'a',occ[v[1]]--;
                while (occ[v[0]] > 0) t += v[0]+'a',occ[v[0]]--;
                cout << t << endl;
            }
        }
    }

    return 0;
}