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

int L[3000000];
int Manacher(string s) {
    int N = 2*s.size() + 1;

    int i,j = 1;
    L[0] = 0,L[1] = 1;
    for (i = 2; i < N; i++) {
        L[i] = max(min(L[2*j-i],j+L[j]-i),0);
        while (((i+L[i]) < N) && (L[i] < i) && ((((i+L[i]) % 2) == 1) || (s[(i+L[i]+1)/2] == s[(i-L[i]-1)/2]))) L[i]++;
        if ((i+L[i]) > (j+L[j])) j = i;
    }
    return 0;
}

int main() {
    cin.sync_with_stdio(0);
    int i;
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;

        i = 0;
        while ((i < s.size()/2) && (s[i] == s[s.size()-i-1])) i++;
        if (i >= s.size()/2) cout << s << endl;
        else {
            int p = i;
            string t = s.substr(p,s.size()-2*p);
            Manacher(t);
            int pre = 0,suff = 0;
            for (i = 0; i < 2*t.size()+1; i++) {
                if (L[i] == i) pre = i;
            }
            for (i = 2*t.size(); i >= 0; i--) {
                if (L[i] == 2*t.size()-i) suff = 2*t.size()-i;
            }
            if (pre > suff) cout << s.substr(0,p) << s.substr(p,pre) << s.substr(s.size()-p,p) << endl;
            else cout << s.substr(0,p) << s.substr(s.size()-p-suff,suff) << s.substr(s.size()-p,p) << endl;
        }
    }

    return 0;
}