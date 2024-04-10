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

struct point { double x,y; int t; };
vector<point> nodes;
double dist[6];
int main() {
    int a,b,c;
    int x1,y1,x2,y2;
    cin >> a >> b >> c;
    cin >> x1 >> y1 >> x2 >> y2;
    if ((a == 0) || (b == 0)) {
        printf("%.10lf\n",(double) abs(x1-x2)+(double) abs(y1-y2));
        return 0;
    }

    int i;
    nodes.pb((point){x1,y1,0}),nodes.pb((point){x2,y2,0});
    nodes.pb((point){x1,(double) (-c-(double) a*x1)/b,1});
    nodes.pb((point){x2,(double) (-c-(double) a*x2)/b,1});
    nodes.pb((point){(double) (-c-(double) b*y1)/a,y1,1});
    nodes.pb((point){(double) (-c-(double) b*y2)/a,y2,1});
    dist[0] = 0;
    for (i = 1; i < 6; i++) dist[i] = 1e99;
    int j,k;
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 6; j++) {
            for (k = 0; k < 6; k++) {
                double d;
                if (nodes[j].t && nodes[k].t) d = sqrt((nodes[j].x-nodes[k].x)*(nodes[j].x-nodes[k].x) \
                     + (nodes[j].y-nodes[k].y)*(nodes[j].y-nodes[k].y));
                else d = abs(nodes[j].x-nodes[k].x)+abs(nodes[j].y-nodes[k].y);
                dist[k] = min(dist[k],dist[j]+d);
            }
        }
    }
    printf("%.10lf\n",dist[1]);

    return 0;
}