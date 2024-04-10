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

int x[50],y[50],x2[50],y2[50];
int num[50];
struct op { int x1,y1,x2,y2; };
vector<op> sol1,sol2;
int solve(int m,int n) {
    int i,j;
    for (i = 0; i < m; i++) num[y[i]]++;
    while (1) {
        vi v;
        for (i = 0; i < n; i++) {
            if (num[i] >= 2) v.pb(i);
        }
        if (v.empty()) break;
        else {
            int p,b;
            for (j = 0; j < v.size(); j++) {
                p = v[j],b = -1;
                for (i = 0; i < n; i++) {
                    if (num[i] == 0) {
                        if ((b == -1) || (abs(i-p) < abs(b-p))) b = i;
                    }
                }
                int f = 0;
                if (b > p) {
                    for (i = b-1; i > p; i--) {
                        if (num[i] != 1) {
                            f = 1;
                            break;
                        }
                    }
                }
                else {
                    for (i = b+1; i < p; i++) {
                        if (num[i] != 1) {
                            f = 1;
                            break;
                        }
                    }
                }
                if (!f) break;
            }
            if (b > p) {
                for (i = b-1; i >= p; i--) {
                    for (j = 0; j < m; j++) {
                        if (y[j] == i) break;
                    }
                    sol1.pb((op){x[j],y[j],x[j],y[j]+1}),num[y[j]+1]++,num[y[j]]--,y[j]++;
                }
            }
            else {
                for (i = b+1; i <= p; i++) {
                    for (j = 0; j < m; j++) {
                        if (y[j] == i) break;
                    }
                    sol1.pb((op){x[j],y[j],x[j],y[j]-1}),num[y[j]-1]++,num[y[j]]--,y[j]--;
                }
            }
        }
    }
    for (i = 0; i < m; i++) {
        while (x[i] > i) sol1.pb((op){x[i],y[i],x[i]-1,y[i]}),x[i]--;
        while (x[i] < i) sol1.pb((op){x[i],y[i],x[i]+1,y[i]}),x[i]++;
    }
    for (i = 0; i < m; i++) {
        while (y[i] > 0) sol1.pb((op){x[i],y[i],x[i],y[i]-1}),y[i]--;
    }
    return 0;
}
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) scanf("%d %d",&x[i],&y[i]),x[i]--,y[i]--;
    for (i = 0; i < m; i++) scanf("%d %d",&x2[i],&y2[i]),x2[i]--,y2[i]--;
    solve(m,n);
    fill(num,num+n,0);
    for (i = 0; i < m; i++) x[i] = x2[i],y[i] = y2[i];
    sol2 = sol1,sol1.clear();
    solve(m,n);
    swap(sol1,sol2);
    printf("%d\n",sol1.size()+sol2.size());
    for (i = 0; i < sol1.size(); i++) printf("%d %d %d %d\n",sol1[i].x1+1,sol1[i].y1+1,sol1[i].x2+1,sol1[i].y2+1);
    reverse(sol2.begin(),sol2.end());
    for (i = 0; i < sol2.size(); i++) printf("%d %d %d %d\n",sol2[i].x2+1,sol2[i].y2+1,sol2[i].x1+1,sol2[i].y1+1);

    return 0;
}