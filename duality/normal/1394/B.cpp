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
template<typename T1,typename T2>
ostream& operator<<(ostream& output,const pair<T1,T2> &p) {
    output << "(" << p.first << "," << p.second << ")";
    return output;
}


vpii adjList[200000];
vpii adjList2[200000];
int bad[10][10];
int bad2[10][10][10][10];
int c[10],ans = 0;
int findAns(int x,int k) {
    printVar(x);
    printArr(c,k+1);
    if (x > k) {
        ans++;
        return 0;
    }

    int i,j;
    for (i = 1; i <= x; i++) {
        if (bad[x][i]) continue;
        c[x] = i;
        for (j = 1; j < x; j++) {
            if (bad2[j][c[j]][x][c[x]]) break;
        }
        if (j == x) findAns(x+1,k);
    }
    return 0;
}
int main() {
    int i;
    int n,m,k;
    int u,v,w;
    scanf("%d %d %d",&n,&m,&k);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d",&u,&v,&w);
        u--,v--;
        adjList[u].pb(mp(w,v));
    }

    int j,l;
    for (i = 0; i < n; i++) {
        sort(adjList[i].begin(),adjList[i].end());
        for (j = 0; j < adjList[i].size(); j++) adjList2[adjList[i][j].second].pb(mp(adjList[i].size(),j+1));
    }
    for (i = 0; i < n; i++) {
        sort(adjList2[i].begin(),adjList2[i].end());
        vpii v;
        printArr(adjList2[i],adjList2[i].size());
        for (j = 0; j < adjList2[i].size(); j++) {
            if ((j > 0) && (adjList2[i][j] == adjList2[i][j-1]))
                bad[adjList2[i][j].first][adjList2[i][j].second] = 1;
            else if ((j < adjList2[i].size()-1) && (adjList2[i][j] == adjList2[i][j+1]))
                bad[adjList2[i][j].first][adjList2[i][j].second] = 1;
            else v.pb(adjList2[i][j]);
        }
        printArr(v,v.size());
        for (j = 0; j < v.size(); j++) {
            for (l = j+1; l < v.size(); l++) {
                bad2[v[j].first][v[j].second][v[l].first][v[l].second] = 1;
                bad2[v[l].first][v[l].second][v[j].first][v[j].second] = 1;
            }
        }
    }/*
    for (i = 1; i <= k;i++){
        for (j = 1; j <= i; j++){
            int l,m;
            for (l = 1; l <= k; l++) {
                for (m = 1; m <= l; m++) {
                    if (bad2[i][j][l][m]) cout<<i<<","<<j<<","<<l<<","<<m<<endl;
                }
            }
        }
    }*/
    findAns(1,k);
    printf("%d\n",ans);

    return 0;
}