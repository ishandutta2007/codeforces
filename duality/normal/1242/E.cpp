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

int a[100000];
vi faces[100000];
int num = 0;
priority_queue<pii> H;
set<pii> edges;
int main() {
    int i;
    int f;
    scanf("%d",&f);
    for (i = 0; i < f; i++) scanf("%d",&a[i]),H.push(mp(a[i],i));

    int j;
    for (i = 0; i < H.top().first; i++) faces[H.top().second].pb(++num);
    int p = H.top().second;
    deque<int> curr;
    for (i = 0; i < faces[p].size(); i++) curr.pb(faces[p][i]);
    H.pop();
    for (i = 1; i < f; i++) {
        int u = H.top().second;
        H.pop();
        int want;
        if (i == f-1) want = 3;
        else want = H.top().first;
        if (curr.size()-a[u]+2 > want+1) {
            for (j = 0; j < a[u]; j++) faces[u].pb(curr.back()),curr.pop_back();
            curr.pb(faces[u].back()),curr.pb(faces[u][0]);
        }
        else {
            if (((curr.size()+a[u]) & 1) == (want & 1)) {
                // want
                int over = (curr.size()+a[u]-want)/2;
                debug "case1",over;
                for (j = 0; j < over+1; j++) faces[u].pb(curr.back()),curr.pop_back();
                curr.pb(faces[u].back());
                for (j = 0; j < a[u]-over-1; j++) faces[u].pb(++num),curr.pb(num);
                curr.pb(faces[u][0]);
            }
            else {
                // want+1
                int over = (curr.size()+a[u]-want-1)/2;
                debug "case2",over;
                for (j = 0; j < over+1; j++) faces[u].pb(curr.back()),curr.pop_back();
                curr.pb(faces[u].back());
                for (j = 0; j < a[u]-over-1; j++) faces[u].pb(++num),curr.pb(num);
                curr.pb(faces[u][0]);
            }
        }
        curr.pb(curr[0]),curr.pop_front();
        printArr(curr,curr.size());
    }
    printf("%d\n",num);
    for (i = 0; i < f; i++) {
        for (j = 0; j < faces[i].size(); j++) printf("%d ",faces[i][j]);
        printf("\n");
    }

    for (i = 0; i < f; i++) {
        for (j = 0; j < faces[i].size(); j++) {
            int a = faces[i][j],b = faces[i][(j+1) % faces[i].size()];
            if (a > b) swap(a,b);
            assert(a <= num);
            assert(b <= num);
            if (edges.count(mp(a,b))) edges.erase(mp(a,b));
            else edges.insert(mp(a,b));
        }
    }
    debug edges.size();

    return 0;
}