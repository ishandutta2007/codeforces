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
#include <list>
#include <iomanip>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back


#define MOD 1000000009LL
#define EPS 1e-8


int xf = 100000, yf = 100000;
int n, m;
int a[3010][3010];
int xsum[3010][3010], ysum[3010][3010];

struct UF{
    vector<int> par;
    UF(int n): par(n + 1){
        for(int i = 0; i <= n; ++i){
            par[i] = i;
        }
    }
    
    int find(int x){
        return x != par[x] ? par[x] = find(par[x]) : x;
    }
    
    bool unite(int x, int y){
        if(rand() & 128){ swap(x, y); }
        x = find(x);
        y = find(y);
        if(x == y){ return false; }
        par[x] = y;
        return true;
    }
};


bool check(int k){
    int xsz = 1500 / k + 3, ysz = 1500 / k + 3;
    int x1 = xf % k, y1 = yf % k;
    if(!x1){ x1 = k; }
    if(!y1){ y1 = k; }
    
    UF uf(xsz * ysz);

    for(int i = 1; i <= n; ++i){
        if((i - y1) % k == 0){ continue; }
        for(int j = x1; j <= m; j += k){
            if(xsum[i][j + k - 1] - xsum[i][j] != 0){
                return false;
            }
        }
    }


    vector<char> use(xsz * ysz);
    vector<int> dim(xsz * ysz);
    for(int i = y1; i <= n; i += k)
    for(int j = x1; j <= m; j += k){
        int t;
        int vnum = i / k * xsz + j / k;
        
        if(a[i][j]){
            use[vnum] = 1;
        }

        t = xsum[i][j + k - 1] - xsum[i][j];
        if(t != 0){
            if(t != k - 1 || !a[i][j] || !a[i][j + k]){ return false; }
            ++dim[vnum];
            ++dim[vnum + 1];
            uf.unite(vnum, vnum + 1);
        }
        
        t = ysum[i + k - 1][j] - ysum[i][j];
        if(t != 0){
            if(t != k - 1 || !a[i][j] || !a[i + k][j]){ return false; }
            ++dim[vnum];
            ++dim[vnum + xsz];
            uf.unite(vnum, vnum + xsz);
        }
    }

    int odds = 0;
    for(int i = 0; i < dim.size(); ++i){
        odds += dim[i] % 2;
    }
    if(odds > 2){ return false; }

    int par = -1;
    for(int i = 0; i < use.size(); ++i){
        if(!use[i]){ continue; }
        int p = uf.find(i);
        if(par != -1 && p != par){ return false; }
        par = p;
    }
    return true;
}


vector<int> solve(){
    int s = 0;
    vector<int> ans;

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j){
        scanf("%d", &a[i][j]);
        if(a[i][j] == 1){
            yf = min(yf, i);
            xf = min(xf, j);
            ++s;
        }
    }
    
    if(s <= 1){ return ans; }
    
    for(int i = 1; i <= 3000; ++i)
    for(int j = 1; j <= 3000; ++j){
        xsum[i][j] = xsum[i][j - 1] + a[i][j];
        ysum[i][j] = ysum[i - 1][j] + a[i][j];
    }

    for(int k = 2; k < n || k < m; ++k){
        if(check(k)){ ans.push_back(k); }
    }
    return ans;
}

int main(){
    srand(time(0));
    vector<int> ans = solve();
    if(ans.empty()){
        ans.push_back(-1);
    }
    for(int i = 0; i < ans.size(); ++i){
        printf("%d%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
    }
}