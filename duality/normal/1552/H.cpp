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

int query(vpii v) {
    int i,x;
    cout << "? " << v.size() << endl;
    for (i = 0; i < v.size(); i++) cout << v[i].first << " " << v[i].second << " ";
    cout << endl;
    cin >> x;
    return x;
}
vi poss;
int main() {
    int i,j,k;
    vpii v;
    for (i = 1; i <= 200; i++) {
        for (j = 1; j <= 200; j++) v.pb(mp(i,j));
    }
    int A = query(v);
    for (i = 2; i <= 200; i++) {
        if (((A % i) == 0) && (i > 1) && (A/i > 1)) poss.pb(i);
    }
    while (poss.size() > 1) {
        int w = poss.size(),x = -1;
        for (i = 2; i <= 200; i++) {
            int cc = 0;
            vi possj;
            for (k = 0; k < poss.size(); k++) {
                possj.pb((A/poss[k]/i)*poss[k]);
                possj.pb(((A/poss[k]+i-1)/i)*poss[k]);
            }
            for (j = 0; j < possj.size(); j++) {
                int o = j;
                j = possj[j];
                int c = 0;
                for (k = 0; k < poss.size(); k++) {
                    if (((j % poss[k]) == 0) && ((j/poss[k] == A/poss[k]/i) || (j/poss[k] == (A/poss[k]+i-1)/i))) c++;
                }
                cc = max(cc,c);
                j = o;
            }
            if (cc < w) w = cc,x = i;
        }
        for (i = 2; i <= 200; i++) {
            int cc = 0;
            vi possj;
            for (k = 0; k < poss.size(); k++) {
                possj.pb((poss[k]/i)*(A/poss[k]));
                possj.pb(((poss[k]+i-1)/i)*(A/poss[k]));
            }
            for (j = 0; j < possj.size(); j++) {
                int o = j;
                j = possj[j];
                int c = 0;
                for (k = 0; k < poss.size(); k++) {
                    if (((j % (A/poss[k])) == 0) && ((j/(A/poss[k]) == poss[k]/i) || (j/(A/poss[k]) == (poss[k]+i-1)/i))) c++;
                }
                cc = max(cc,c);
                j = o;
            }
            if (cc < w) w = cc,x = -i;
        }
        if (x > 0) {
            vpii v;
            for (i = 1; i <= 200; i++) {
                for (j = 1; j <= 200; j++) {
                    if ((i % x) == 0) v.pb(mp(i,j));
                }
            }
            //cout<<"query x "<<x<<endl;
            i = x,j = query(v);
            vi poss2;
            for (k = 0; k < poss.size(); k++) {
                if (((j % poss[k]) == 0) && ((j/poss[k] == A/poss[k]/i) || (j/poss[k] == (A/poss[k]+i-1)/i))) poss2.pb(poss[k]);
            }
            poss = poss2;
        }
        else {
            vpii v;
            for (i = 1; i <= 200; i++) {
                for (j = 1; j <= 200; j++) {
                    if ((j % (-x)) == 0) v.pb(mp(i,j));
                }
            }
            //cout<<"query y "<<-x<<endl;
            i = -x,j = query(v);
            vi poss2;
            for (k = 0; k < poss.size(); k++) {
                if (((j % (A/poss[k])) == 0) && ((j/(A/poss[k]) == poss[k]/i) || (j/(A/poss[k]) == (poss[k]+i-1)/i))) poss2.pb(poss[k]);
            }
            poss = poss2;
        }
    }
    cout << "! " << 2*(A/poss[0]+poss[0]-2) << endl;
    
    return 0;
}