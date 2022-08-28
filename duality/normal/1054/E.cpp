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

deque<char> Q[300][300];
string ori[300][300],want[300][300];
struct op { int x1,y1,x2,y2; };
vector<op> sol;
int need[300][2];
int doOp(int x1,int y1,int x2,int y2) {
    sol.pb((op){x1,y1,x2,y2});
    Q[x2][y2].pb(Q[x1][y1].front()),Q[x1][y1].pop_front();
    return 0;
}
int main() {
    int i,j,k;
    int n,m;
    string s;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> s;
            for (k = 0; k < s.size(); k++) Q[i][j].push_front(s[k]);
            ori[i][j] = s;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) cin >> want[i][j];
    }

    int t,pos;
    for (t = 0; t < 2; t++) {
        int s1 = Q[0][0].size(),s2 = Q[0][1].size();
        for (i = 0; i < s1; i++) {
            if (Q[0][0].front() == '0') doOp(0,0,1,0);
            else doOp(0,0,0,1);
        }
        for (i = 0; i < s2; i++) {
            if (Q[0][1].front() == '1') doOp(0,1,1,1);
            else doOp(0,1,0,0);
        }
        for (i = 0; i < n; i++) {
            for (j = 2; j < m; j++) {
                while (!Q[i][j].empty()) {
                    if (Q[i][j].front() == '0') doOp(i,j,i,0);
                    else doOp(i,j,i,1);
                }
            }
        }
        for (i = 1; i < n; i++) {
            for (j = 0; j < 2; j++) {
                while (!Q[i][j].empty()) {
                    if (Q[i][j].front() == '0') {
                        if (j == 0) doOp(i,j,0,0);
                        else doOp(i,j,i,0);
                    }
                    else {
                        if (j == 1) doOp(i,j,0,1);
                        else doOp(i,j,i,1);
                    }
                }
            }
        }
        for (i = 1; i < n; i++) {
            for (j = 0; j < 2; j++) {
                while (!Q[i][j].empty()) {
                    if (Q[i][j].front() == '0') {
                        if (j == 0) doOp(i,j,0,0);
                        else doOp(i,j,i,0);
                    }
                    else {
                        if (j == 1) doOp(i,j,0,1);
                        else doOp(i,j,i,1);
                    }
                }
            }
        }

        if (t == 0) {
            pos = sol.size();
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    s = want[i][j];
                    Q[i][j].clear();
                    for (k = 0; k < s.size(); k++) Q[i][j].pb(s[k]);
                }
            }
        }
    }
    reverse(sol.begin()+pos,sol.end());
    for (i = pos; i < sol.size(); i++) swap(sol[i].x1,sol[i].x2),swap(sol[i].y1,sol[i].y2);
    printf("%d\n",sol.size());
    for (i = 0; i < sol.size(); i++) printf("%d %d %d %d\n",sol[i].x1+1,sol[i].y1+1,sol[i].x2+1,sol[i].y2+1);
/*
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            Q[i][j].clear();
            for (k = 0; k < ori[i][j].size(); k++) Q[i][j].push_front(ori[i][j][k]);
        }
    }
    for (i = 0; i < sol.size(); i++) {
        Q[sol[i].x2][sol[i].y2].pb(Q[sol[i].x1][sol[i].y1].front()),Q[sol[i].x1][sol[i].y1].pop_front();
        assert((sol[i].x1 == sol[i].x2) || (sol[i].y1 == sol[i].y2));
    }
    int l = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            l += ori[i][j].size();
            for (k = 0; k < Q[i][j].size(); k++) cout << Q[i][j][Q[i][j].size()-k-1];
            cout << " ";
        }
        cout << endl;
    }
    cout << 4*l << endl;
    cout << pos << endl;*/

    return 0;
}