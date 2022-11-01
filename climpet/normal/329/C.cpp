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
#define ITR ::iterator


#define MOD 1000000009LL
#define EPS 1e-8


struct UF{
    vint par;
    UF(int n): par(n + 1){
        for(int i = 1; i <= n; ++i){
            par[i] = i;
        }
    }
    int find(int x){
        return x != par[x] ? par[x] = find(par[x]) : x;
    }
};


int n, m;
VV(int) G;
vector<char> vis;
VV(int) one, tri, cyc, chn;

void dfs(int v, vint &tmp){
    vis[v] = 1;
    tmp.push_back(v);
    for(int i = 0; i < G[v].size(); ++i){
        int u = G[v][i];
        if(!vis[u]){
            dfs(u, tmp);
        }
    }
}


int main(){
    int a, b;
    scanf("%d%d", &n, &m);
    G.resize(n + 1);
    for(int i = 0; i < m; ++i){
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vis.resize(n + 1);
    vint tmp;
    int con = 0;
    for(int i = 1; i <= n; ++i){
        if(!vis[i] && G[i].size() < 2){
            tmp.clear();
            dfs(i, tmp);

            if(tmp.size() == 1){
                one.push_back(tmp);
            }
            else{
                chn.push_back(tmp);
            }
            ++con;
        }
    }
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            tmp.clear();
            dfs(i, tmp);
            if(tmp.size() == 3){
                tri.push_back(tmp);
            }
            else{
                cyc.push_back(tmp);
            }
            ++con;
        }
    }

    vint ans;
    bool ng = false;
    if(con == 1){
        if(tri.size()){
            ng = true;
        }
        else if(cyc.size() && cyc[0].size() <= 4){
            ng = true;
        }
        else if(chn.size() && chn[0].size() <= 3){
            ng = true;
        }
        if(ng){
            puts("-1");
            return 0;
        }

        tmp = (cyc.size() ? cyc[0] : chn[0]);
        if(n % 2 != 0 || chn.size()){
            for(int i = 1; i < tmp.size(); i += 2){
                ans.push_back(tmp[i]);
                tmp[i] = -1;
            }
            for(int i = 0; i < tmp.size(); ++i){
                if(tmp[i] != -1){
                    ans.push_back(tmp[i]);
                }
            }
        }
        else{
            int k = n / 2;
            ans.push_back(tmp[0]);
            ans.push_back(tmp[k]);
            for(int i = 1; i < k; ++i){
                ans.push_back(tmp[i]);
                ans.push_back(tmp[n - i]);
            }
        }
    }
    else if(con == 2 && tri.size() && one.size()){
        puts("-1");
        return 0;
    }
    else{
        for(int i = 0; i < tri.size(); ++i){
            ans.push_back(tri[i][0]);
        }
        for(int i = 0; i < cyc.size(); ++i){
            for(int j = 0; j < cyc[i].size(); j += 2){
                ans.push_back(cyc[i][j]);
                cyc[i][j] = -1;
            }
        }
        for(int i = 0; i < chn.size(); ++i){
            for(int j = 1; j < chn[i].size(); j += 2){
                ans.push_back(chn[i][j]);
                chn[i][j] = -1;
            }
        }
        if(cyc.empty() && chn.empty() && !tri.empty() && !one.empty()){
            ans.push_back(one.back()[0]);
            one.pop_back();
        }
        for(int i = 0; i < tri.size(); ++i){
            ans.push_back(tri[i][1]);
        }

        size_t k = -1u;
        for(int i = 0; i < one.size(); ++i){
            ans.push_back(one[i][0]);
            k = min(k, ans.size());
        }
        for(int i = 0; i < cyc.size(); ++i){
            for(int j = 0; j < cyc[i].size(); ++j){
                if(cyc[i][j] != -1){
                    ans.push_back(cyc[i][j]);
                    k = min(k, ans.size());
                }
            }
        }
        for(int i = 0; i < chn.size(); ++i){
            for(int j = 0; j < chn[i].size(); ++j){
                if(chn[i][j] != -1){
                    ans.push_back(chn[i][j]);
                    k = min(k, ans.size());
                }
            }
        }

        if(k != -1u){
            ans.insert(ans.begin() + k, tri.size(), -1);
            for(int i = 0; i < tri.size(); ++i){
                ans[i + k] = tri[i][2];
            }
        }
        else if(!tri.empty()){
            ans.clear();
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < tri.size(); ++j){
                    ans.push_back(tri[j][i]);
                }
            }
        }
    }

    int z = m;
    for(int i = 0; i < ans.size(); ++i){
        if(z > 0){
            --z;
            printf("%d %d\n", ans[i], ans[(i + 1) % ans.size()]);
        }
    }
}