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

inline int index(const vint &v, int x){
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int n, m;
vvint a;

void solve(){
    vint ans;
    ans.reserve(m);

    if(n <= 300){
        vvint b = a;
        vector<vvint> to(n);
        vvint usecnt(n);
        vint refcnt(m);

        for(int i = 0; i < n; ++i){
            b[i].erase(remove(b[i].begin(), b[i].end(), -1), b[i].end());   //append
            sort(b[i].begin(), b[i].end());
            b[i].erase(unique(b[i].begin(), b[i].end()), b[i].end());

            to[i].resize(b[i].size());
            usecnt[i].resize(b[i].size());
            for(int j = 0; j < m; ++j){
                if(a[i][j] != -1){
                    int k = index(b[i], a[i][j]);
                    to[i][k].push_back(j);
                    ++usecnt[i][k];
                }
            }

            for(int j = 0; j < m; ++j){
                if(a[i][j] > b[i][0]){
                    ++refcnt[j];
                }
            }
        }

        queue<int> q;
        for(int i = 0; i < m; ++i){
            if(refcnt[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u + 1);

            for(int i = 0; i < n; ++i){
                if(a[i][u] == -1) continue;

                int k = index(b[i], a[i][u]);
                if(k + 1 >= to[i].size()) continue;

                if(--usecnt[i][k] == 0){
                    for(int j = 0; j < to[i][k+1].size(); ++j){
                        int t = to[i][k+1][j];
                        if(--refcnt[t] == 0){
                            q.push(t);
                        }
                    }
                }
            }
        }
    }
    else{
        set<pii> E;
        vvint G(m);

        for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j){
            bool flag = false;
            for(int k = 0; k < n; ++k){
                if(a[k][i] == -1 || a[k][j] == -1) continue;
                if(a[k][i] < a[k][j]){
                    flag = true;
                    break;
                }
            }
            
            if(flag && E.insert(pii(i, j)).second){
                G[i].push_back(j);
            }
        }

        vint cnt(m);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < G[i].size(); ++j){
                ++cnt[G[i][j]];
            }
        }

        queue<int> q;
        for(int i = 0; i < m; ++i){
            if(cnt[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u + 1);
            
            for(int j = 0; j < G[u].size(); ++j){
                if(--cnt[G[u][j]] == 0){
                    q.push(G[u][j]);
                }
            }
        }
    }

    if(ans.size() < m){
        puts("-1");
    }
    else{
        printf("%d", ans[0]);
        for(int i = 1; i < m; ++i){
            printf(" %d", ans[i]);
        }
        puts("");
    }
}

int main(){
    scanf("%d%d", &n, &m);
    initvv(a, n, m);
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j){
        scanf("%d", &a[i][j]);
    }

    solve();
}