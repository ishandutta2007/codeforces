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

vi pos[26];
pii sparse[100000][17];
int logg[100001],logn;
pii com(pii a,pii b) {
    return mp(min(a.first,b.first),max(a.second,b.second));
}
pii query(int s,int e) {
    int l = logg[e-s+1];
    return com(sparse[s][l],sparse[e-(1 << l)+1][l]);
}
int pp[26];
int parentl[26][100000][17],parentr[26][100000][17];
vector<pair<pii,int> > vl[26],vr[26];
int parentl2[100000][17],parentr2[100000][17];
vector<pair<pii,int> > vl2,vr2;
LLI suml[100000][17],sumr[100000][17];
int main() {
    string s;
    cin >> s;

    int i,j,k;
    int n = s.size();
    for (i = 0; i < n; i++) pos[s[i]-'a'].pb(i);
    for (i = 0; i < 26; i++) {
        for (j = 0; j < pos[i].size(); j++) sparse[pos[i][j]][0] = mp((j == 0) ? 0:pos[i][j-1],(j == pos[i].size()-1) ? n-1:pos[i][j+1]);
    }
    for (i = 1; (1 << i) <= n; i++) {
        for (j = 0; j <= n-(1 << i); j++) sparse[j][i] = com(sparse[j][i-1],sparse[j+(1 << (i-1))][i-1]);
    }
    for (i = 2; i <= n; i++) logg[i] = logg[i/2]+1;
    memset(parentl,-1,sizeof(parentl));
    memset(parentr,-1,sizeof(parentr));
    for (i = 0; i < 26; i++) {
        for (j = 0; j <= pos[i].size(); j++) {
            int l = (j == 0) ? 0:pos[i][j-1]+1,r = (j == pos[i].size()) ? n-1:pos[i][j]-1;
            int m = 1e9;
            for (k = r; k >= l; k--) {
                m = min(m,sparse[k][0].first);
                if (m >= l) parentl[i][k][0] = m;
            }
            m = 0;
            for (k = l; k <= r; k++) {
                m = max(m,sparse[k][0].second);
                if (m <= r) parentr[i][k][0] = m;
            }
        }
        for (j = 1; (1 << j) < n; j++) {
            for (k = 0; k < n; k++) {
                if (parentl[i][k][j-1] != -1) parentl[i][k][j] = parentl[i][parentl[i][k][j-1]][j-1];
                if (parentr[i][k][j-1] != -1) parentr[i][k][j] = parentr[i][parentr[i][k][j-1]][j-1];
            }
        }
    }
    int m = 1e9;
    for (i = n-1; i >= 0; i--) {
        m = min(m,sparse[i][0].first);
        parentl2[i][0] = m;
    }
    m = 0;
    for (i = 0; i < n; i++) {
        m = max(m,sparse[i][0].second);
        parentr2[i][0] = m;
    }
    for (i = 1; (1 << i) < n; i++) {
        for (j = 0; j < n; j++) {
            parentl2[j][i] = parentl2[parentl2[j][i-1]][i-1];
            parentr2[j][i] = parentr2[parentr2[j][i-1]][i-1];
        }
    }
    logn = i;
    LLI ans = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 26; j++) pp[j] = lower_bound(pos[j].begin(),pos[j].end(),i)-pos[j].begin();
        int l = i,r = i,d = 0;
        while ((l > 0) || (r < n-1)) {
            pii p = query(l,r);
            d++,ans += (LLI) d*(p.second-p.first+1-(r-l+1));
            l = p.first,r = p.second;
            int x = -1,y = n;
            for (j = 0; j < 26; j++) {
                if ((pp[j] < pos[j].size()) && (pos[j][pp[j]] <= r)) continue;
                if ((pp[j] > 0) && (pos[j][pp[j]-1] >= l)) continue;
                if ((pp[j] < pos[j].size()) && (pos[j][pp[j]] <= y)) y = pos[j][pp[j]];
                if ((pp[j] > 0) && (pos[j][pp[j]-1] >= x)) x = pos[j][pp[j]-1];
            }
            int ll = l,rr = r;
            for (j = logn-1; j >= 0; j--) {
                if ((x == -1) && (y == n)) {
                    if ((parentl2[ll][j] != 0) || (parentr2[rr][j] != n-1)) {
                        vl2.pb(mp(mp(ll,j),d)),vr2.pb(mp(mp(rr,j),d));
                        ll = parentl2[ll][j],rr = parentr2[rr][j];
                        d += (1 << j);
                    }
                }
                else if (x == -1) {
                    if (parentr2[rr][j] < y) {
                        vl[s[y]-'a'].pb(mp(mp(ll,j),d)),vr2.pb(mp(mp(rr,j),d));
                        ll = parentl[s[y]-'a'][ll][j],rr = parentr2[rr][j];
                        d += (1 << j);
                    }
                }
                else if (y == n) {
                    if (parentl2[ll][j] > x) {
                        vl2.pb(mp(mp(ll,j),d)),vr[s[x]-'a'].pb(mp(mp(rr,j),d));
                        ll = parentl2[ll][j],rr = parentr[s[x]-'a'][rr][j];
                        d += (1 << j);
                    }
                }
                else {
                    if ((parentl[s[y]-'a'][ll][j] != -1) && (parentl[s[y]-'a'][ll][j] > x) \
                        && (parentr[s[x]-'a'][rr][j] != -1) && (parentr[s[x]-'a'][rr][j] < y)) {
                        vl[s[y]-'a'].pb(mp(mp(ll,j),d)),vr[s[x]-'a'].pb(mp(mp(rr,j),d));
                        ll = parentl[s[y]-'a'][ll][j],rr = parentr[s[x]-'a'][rr][j];
                        d += (1 << j);
                    }
                }
            }
            l = ll,r = rr;
        }
    }
    for (i = 0; i < 26; i++) {
        if (vl[i].empty() && vr[i].empty()) continue;
        for (j = 0; j < n; j++) suml[j][0] = sumr[j][0] = j;
        for (j = 1; j < logn; j++) {
            for (k = 0; k < n; k++) {
                if (parentl[i][k][j] != -1) suml[k][j] = suml[k][j-1]+suml[parentl[i][k][j-1]][j-1];
                if (parentr[i][k][j] != -1) sumr[k][j] = sumr[k][j-1]+sumr[parentr[i][k][j-1]][j-1];
            }
        }
        for (j = 0; j < vl[i].size(); j++) {
            int u = vl[i][j].first.first,d = vl[i][j].second;
            k = vl[i][j].first.second;
            ans += suml[u][k]+(LLI) d*u-(LLI) (d+(1 << k))*parentl[i][u][k];
        }
        for (j = 0; j < vr[i].size(); j++) {
            int u = vr[i][j].first.first,d = vr[i][j].second;
            k = vr[i][j].first.second;
            ans -= sumr[u][k]+(LLI) d*u-(LLI) (d+(1 << k))*parentr[i][u][k];
        }
    }
    for (j = 0; j < n; j++) suml[j][0] = sumr[j][0] = j;
    for (j = 1; j < logn; j++) {
        for (k = 0; k < n; k++) {
            suml[k][j] = suml[k][j-1]+suml[parentl2[k][j-1]][j-1];
            sumr[k][j] = sumr[k][j-1]+sumr[parentr2[k][j-1]][j-1];
        }
    }
    for (j = 0; j < vl2.size(); j++) {
        int u = vl2[j].first.first,d = vl2[j].second;
        k = vl2[j].first.second;
        ans += suml[u][k]+(LLI) d*u-(LLI) (d+(1 << k))*parentl2[u][k];
    }
    for (j = 0; j < vr2.size(); j++) {
        int u = vr2[j].first.first,d = vr2[j].second;
        k = vr2[j].first.second;
        ans -= sumr[u][k]+(LLI) d*u-(LLI) (d+(1 << k))*parentr2[u][k];
    }
    cout << ans << endl;

    return 0;
}