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


#define MOD 1000000007
#define EPS 1e-8

int n;
int a[310], cnt[310], rcnt[310];
vint G[310], rG[310];
int t;
int depth[310];
int dp[100010];

int solve(){
    int q, b, c;
    scanf("%d%d%d", &n, &q, &t);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < q; ++i){
        scanf("%d%d", &b, &c);
        G[b].push_back(c);
        rG[c].push_back(b);
        ++cnt[c];
        ++rcnt[b];
    }

    queue<int> qu;
    for(int i = 1; i <= n; ++i){
        if(rcnt[i] == 0){ qu.push(i); }
    }
    while(!qu.empty()){
        b = qu.front();
        qu.pop();
        LL u = t - (LL)depth[b] * a[b];
        if(u < 0){ return 0; }
        t = u;
        for(int i = 0; i < rG[b].size(); ++i){
            c = rG[b][i];
            if(!--rcnt[c]){
                depth[c] = depth[b] + 1;
                qu.push(c);
            }
        }
    }
    
    for(int i = 1; i <= n; ++i){
        if(cnt[i] == 0){ qu.push(i); }
    }
    while(!qu.empty()){
        b = qu.front();
        qu.pop();
        for(int i = 0; i < G[b].size(); ++i){
            c = G[b][i];
            a[c] += a[b];
            if(!--cnt[c]){
                qu.push(c);
            }
        }
    }

    if(t < 0){ return 0; }

    for(int i = 1; i <= n; ++i){
        if(cnt[i]){
            return 0;
        }
    }

    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        b = a[i];
        for(int j = b; j <= t; ++j){
            dp[j] += dp[j - b];
            if(dp[j] >= MOD){ dp[j] -= MOD; }
        }
    }
    
    return dp[t];
}

int main(){
    printf("%d\n", solve());
}