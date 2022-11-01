#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back
#define ITR ::iterator


#define MOD 1000000009LL
#define EPS 1e-8



struct segtree{
    int n;
    vint dat, idx;

    segtree(int n_){
        n = 1;
        while(n < n_) n *= 2;
        dat.resize(n, INT_MIN);
        idx.resize(n * 2 - 1);
        for(int i = 0; i < n; ++i){
            idx[i + n - 1] = i;
        }
    }

    void update(int k, int a){
        dat[k] = a;
        k += n - 1;
        while(k > 0){
            k = (k - 1) / 2;
            if(dat[idx[k*2+1]] > dat[idx[k*2+2]]){
                idx[k] = idx[k * 2 + 1];
            }
            else{
                idx[k] = idx[k * 2 + 2];
            }
        }
    }
    
    int query(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return idx[k];
        
        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

        if(dat[vl] > dat[vr]) return vl;
        return vr;
    }
};


int n, m;
vint a, b, c, ans, cs;
vector<char> used, visit;
vvint G;

int main(){
    scanf("%d%d", &n, &m);

    a.resize(m);
    b = c = a;
    ans.resize(m, -1);
    used.resize(m);
    for(int i = 0; i < m; ++i){
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }

    G.resize(n + 1);
    cs.resize(n + 1);
    visit.resize(n + 1);
    for(int i = 0; i < m; ++i){
        G[a[i]].push_back(i);
        G[b[i]].push_back(i);
    }

/*
    for(int i = 0; i < G[1].size(); ++i){
        cs[1] += c[G[1][i]];
    }
    for(int i = 0; i < G[n].size(); ++i){
        cs[n] -= c[G[n][i]];
    }
*/
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < G[i].size(); ++j){
            cs[i] -= c[G[i][j]];
        }
    }
    
    cs[1] = 0;
    cs[n] *= 2;

    segtree st(n + 4);
    st.update(1, cs[1]);

    while(1){
        int vn = st.query(0, st.n, 0, 0, st.n);
        if(st.dat[vn] == INT_MIN) break;
        st.update(vn, INT_MIN);

        for(int j = 0; j < G[vn].size(); ++j){
            int en = G[vn][j];
            if(used[en]) continue;

            used[en] = 1;
            int t = a[en] ^ b[en] ^ vn;
//          cs[vn] -= c[en];
            cs[t] += 2 * c[en];
            ans[en] = (vn == b[en]);
            st.update(t, cs[t]);
        }
    }

for(int i=1;i<=n;++i)if(cs[i])throw i;

    for(int i = 0; i < m; ++i){
        puts(ans[i] != 0 ? "1" : "0");
    }
}