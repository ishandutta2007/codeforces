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
#define MOD 1000000007
#define S1 23
#define S2 31

vi occ[26];
struct query { int x,y,i; };
vector<query> queries[200001];
int diff[200000];
int nn[26][200000];
pii updates[200000];
int pow1[200001],pow2[200001];
pii tree[1 << 19];
int update(int s,int e,int ai,int i,int num) {
    if ((s > ai) || (e < ai)) return 0;
    else if (s == e) {
        tree[i] = mp(num,num);
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,ai,2*i+1,num);
    update(mid+1,e,ai,2*i+2,num);
    tree[i].first = ((LLI) pow1[mid-s+1]*tree[2*i+2].first+tree[2*i+1].first) % MOD;
    tree[i].second = ((LLI) pow2[mid-s+1]*tree[2*i+2].second+tree[2*i+1].second) % MOD;
    return 0;
}
pii ret;
int pp;
int queryh(int s,int e,int qs,int qe,int i) {
    if ((s > qe) || (e < qs)) return 0;
    else if ((s >= qs) && (e <= qe)) {
        ret.first = ((LLI) pow1[pp]*tree[i].first+ret.first) % MOD;
        ret.second = ((LLI) pow2[pp]*tree[i].second+ret.second) % MOD;
        pp += e-s+1;
        return 0;
    }

    int mid = (s+e) / 2;
    queryh(s,mid,qs,qe,2*i+1);
    queryh(mid+1,e,qs,qe,2*i+2);
    return 0;
}
int num[200000];
int ans[200000];
template<typename T1,typename T2>
ostream& operator<<(ostream& output,const pair<T1,T2> &p) {
	output << "(" << p.first << "," << p.second << ")";
	return output;
}
int main() {
    int i;
    int n,m;
    char c;
    int x,y,l;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        scanf(" %c",&c);
        occ[c-'a'].pb(i);
    }
    for (i = 0; i < m; i++) {
        scanf("%d %d %d",&x,&y,&l);
        queries[l].pb((query){x-1,y-1,i});
    }

    int j,k;
    for (i = 0; i < 26; i++) {
        fill(nn[i],nn[i]+n,n);
        for (j = 0; j < occ[i].size(); j++) {
            if (j == 0) diff[occ[i][j]] = 0;
            else diff[occ[i][j]] = occ[i][j]-occ[i][j-1];
            for (k = (j == 0) ? 0:occ[i][j-1]+1; k <= occ[i][j]; k++) nn[i][k] = occ[i][j];
        }
    }
    printArr(diff,n);
    for (i = 0; i < n; i++) updates[i] = mp(diff[i],i);
    sort(updates,updates+n);
    pow1[0] = pow2[0] = 1;
    for (i = 1; i <= n; i++) {
        pow1[i] = ((LLI) pow1[i-1]*S1) % MOD;
        pow2[i] = ((LLI) pow2[i-1]*S2) % MOD;
    }

    j = 0;
    for (i = 0; i <= n; i++) {
        while ((j < n) && (updates[j].first < i)) {
            update(0,n-1,updates[j].second,0,updates[j].first+1);
            num[updates[j].second] = updates[j].first+1;
            //cout<<updates[j].second<<" to "<<updates[j].first<<endl;
            j++;
        }
        for (k = 0; k < queries[i].size(); k++) {
            x = queries[i][k].x;
            y = queries[i][k].y;
            //cout<<"Query "<<x<<","<<y<<endl;
            vpii a,b;
            for (l = 0; l < 26; l++) {
                if (nn[l][x] <= x+i-1) a.pb(mp(nn[l][x]-x,num[nn[l][x]]));
                if (nn[l][y] <= y+i-1) b.pb(mp(nn[l][y]-y,num[nn[l][y]]));
            }
            printArr(a,a.size());
            printArr(b,b.size());
            if (a.size() != b.size()) ans[queries[i][k].i] = 0;
            else {
                    //debug "here";
                sort(a.begin(),a.end());
                sort(b.begin(),b.end());
                for (l = 0; l < a.size(); l++) {
                    if (a[l].first != b[l].first) break;
                }
                if (l == a.size()) {
                    for (l = 0; l < a.size(); l++) update(0,n-1,a[l].first+x,0,n+2);
                    ret = mp(0,0),pp = 0;
                    queryh(0,n-1,x,x+i-1,0);
                    pii hash1 = ret;
                    for (l = 0; l < a.size(); l++) update(0,n-1,a[l].first+x,0,a[l].second);
                    for (l = 0; l < b.size(); l++) update(0,n-1,b[l].first+y,0,n+2);
                    ret = mp(0,0),pp = 0;
                    queryh(0,n-1,y,y+i-1,0);
                    pii hash2 = ret;
                    for (l = 0; l < b.size(); l++) update(0,n-1,b[l].first+y,0,b[l].second);
                    //cout<<hash1.first<<","<<hash2.first<<endl;
                    if (hash1 != hash2) ans[queries[i][k].i] = 0;
                    else ans[queries[i][k].i] = 1;
                }
                else ans[queries[i][k].i] = 0;
            }
        }
    }
    for (i = 0; i < m; i++) printf(ans[i] ? "YES\n":"NO\n");

    return 0;
}