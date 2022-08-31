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

int n,q = 0;
int query(vi v) {
    int i,r;
    q++;
    if (q > 18*n) while (1);
    cout << "? " << v.size();
    for (i = 0; i < v.size(); i++) cout << " " << v[i]+1;
    cout << endl;
    cin >> r;
    return r;
}
map<vi,int> M;
int p[800],pos[801],o[800];
int main() {
    srand(time(NULL));
    cin >> n;

    int i,j,k,l;
    if (n <= 8) {
        for (i = 0; i < min(18*n,(1 << n)-2); i++) {
            int x = 1+(rand() % ((1 << n)-2));
            vi v;
            for (j = 0; j < n; j++) {
                if (x & (1 << j)) v.pb(j);
            }
            while (M.count(v)) {
                x = 1+(rand() % ((1 << n)-2)),v.clear();
                for (j = 0; j < n; j++) {
                    if (x & (1 << j)) v.pb(j);
                }
            }
            M[v] = query(v);
        }
        for (i = 0; i < n; i++) p[i] = i+1;
        do {
            int f = 0;
            for (auto it = M.begin(); it != M.end(); it++) {
                int s = 0;
                for (j = 0; j < it->first.size(); j++) s += p[it->first[j]];
                if (((s % it->first.size()) == 0) != it->second) {
                    f = 1;
                    break;
                }
            }
            if (!f) break;
        } while (next_permutation(p,p+n) && (p[0] <= n/2));
    }
    else {
        int ii;
        fill(pos,pos+n+1,-1),fill(p,p+n,-1);
        for (i = 0; i < n; i++) o[i] = i;
        random_shuffle(o,o+n);
        for (ii = 0; ii < n; ii++) {
            i = o[ii];
            vi v;
            for (j = 0; j < n; j++) {
                if (i != j) v.pb(j);
            }
            if (query(v)) {
                if (pos[1] == -1) pos[1] = i,p[i] = 1;
                else if (pos[n] == -1) pos[n] = i,p[i] = n;
                else break;
            }
        }
        random_shuffle(o,o+n);
        for (ii = 0; ii < n; ii++) {
            i = o[ii];
            if (p[i] == -1) {
                vi v;
                for (j = 0; j < n; j++) {
                    if ((j != pos[1]) && (j != pos[n]) && (i != j)) v.pb(j);
                }
                v.pb(pos[1]);
                if ((pos[n/2] == -1) && query(v)) pos[n/2] = i,p[i] = n/2;
                v.back() = pos[n];
                if ((pos[n/2+1] == -1) && query(v)) pos[n/2+1] = i,p[i] = n/2+1;
            }
        }
        random_shuffle(o,o+n);
        for (ii = 0; ii < n; ii++) {
            i = o[ii];
            if (p[i] == -1) {
                vi v;
                for (j = 0; j < n; j++) {
                    if ((j != pos[1]) && (j != pos[n/2]) && (i != j)) v.pb(j);
                }
                if (query(v)) {
                    pos[n/2+2] = i,p[i] = n/2+2;
                    break;
                }
            }
        }
        random_shuffle(o,o+n);
        for (ii = 0; ii < n; ii++) {
            i = o[ii];
            if (p[i] == -1) {
                vi v;
                for (j = 0; j < n; j++) {
                    if ((j != pos[n]) && (j != pos[n/2+1]) && (i != j)) v.pb(j);
                }
                if (query(v)) {
                    pos[n/2-1] = i,p[i] = n/2-1;
                    break;
                }
            }
        }
        random_shuffle(o,o+n);
        for (ii = 0; ii < n; ii++) {
            i = o[ii];
            if (p[i] == -1) {
                vi v;
                for (j = 0; j < n; j++) {
                    if ((j != pos[n]) && (j != pos[n/2+2]) && (i != j)) v.pb(j);
                }
                if (query(v)) {
                    pos[n/2-2] = i,p[i] = n/2-2;
                    break;
                }
            }
        }
        if (n <= 60) {
            vpii vv;
            int f[3] = {3,4,5};
            for (i = n/2-2; i <= n/2+2; i++) vv.pb(mp(pos[i],i));
            for (i = 0; i < n; i++) {
                if (p[i] == -1) {
                    int rem[3];
                    for (j = 0; j < 3; j++) {
                        for (k = 0; k < f[j]; k++) {
                            vi v;
                            int s = 0;
                            for (l = 0; l < f[j]; l++) {
                                if (k != l) v.pb(vv[l].first),s += vv[l].second;
                            }
                            v.pb(i);
                            if ((k == f[j]-1) || query(v)) {
                                rem[j] = f[j]-(s % f[j]);
                                if (rem[j] == f[j]) rem[j] = 0;
                                break;
                            }
                        }
                    }
                    for (j = 1; j <= n; j++) {
                        for (k = 0; k < 3; k++) {
                            if ((j % f[k]) != rem[k]) break;
                        }
                        if (k == 3) break;
                    }
                    p[i] = j;
                }
            }
        }
        else {
            random_shuffle(o,o+n);
            for (ii = 0; ii < n; ii++) {
                i = o[ii];
                if (p[i] == -1) {
                    vi v;
                    for (j = 0; j < n; j++) {
                        if ((j != pos[1]) && (j != pos[n/2-1]) && (i != j)) v.pb(j);
                    }
                    if (query(v)) {
                        pos[n/2+3] = i,p[i] = n/2+3;
                        break;
                    }
                }
            }
            random_shuffle(o,o+n);
            for (ii = 0; ii < n; ii++) {
                i = o[ii];
                if (p[i] == -1) {
                    vi v;
                    for (j = 0; j < n; j++) {
                        if ((j != pos[1]) && (j != pos[n/2-2]) && (i != j)) v.pb(j);
                    }
                    if (query(v)) {
                        pos[n/2+4] = i,p[i] = n/2+4;
                        break;
                    }
                }
            }
            random_shuffle(o,o+n);
            for (ii = 0; ii < n; ii++) {
                i = o[ii];
                if (p[i] == -1) {
                    vi v;
                    for (j = 0; j < n; j++) {
                        if ((j != pos[n]) && (j != pos[n/2+3]) && (i != j)) v.pb(j);
                    }
                    if (query(v)) {
                        pos[n/2-3] = i,p[i] = n/2-3;
                        break;
                    }
                }
            }
            vpii vv;
            int f[4] = {3,5,7,8};
            for (i = n/2-3; i <= n/2+4; i++) vv.pb(mp(pos[i],i));
            for (i = 0; i < n; i++) {
                if (p[i] == -1) {
                    int rem[4];
                    for (j = 0; j < 4; j++) {
                        for (k = 0; k < f[j]; k++) {
                            vi v;
                            int s = 0;
                            for (l = 0; l < f[j]; l++) {
                                if (k != l) v.pb(vv[l].first),s += vv[l].second;
                            }
                            v.pb(i);
                            if ((k == f[j]-1) || query(v)) {
                                rem[j] = f[j]-(s % f[j]);
                                if (rem[j] == f[j]) rem[j] = 0;
                                break;
                            }
                        }
                    }
                    for (j = 1; j <= n; j++) {
                        for (k = 0; k < 4; k++) {
                            if ((j % f[k]) != rem[k]) break;
                        }
                        if (k == 4) break;
                    }
                    p[i] = j;
                }
            }
        }
    }
    if (p[0] > n/2) {
        for (i = 0; i < n; i++) p[i] = n+1-p[i];
    }
    cout << "!";
    for (i = 0; i < n; i++) cout << " " << p[i];
    cout << endl;

    return 0;
}