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

int n;
int a[200020];
int to[200020];
LL c[200020];
int cnt[200020];
vector<pii> G[200020];
LL ans[200020];

int main(){
    scanf("%d", &n);
    for(int i = 2; i <= n; ++i){
        scanf("%d", &a[i]);
    }

    queue<int> q;
    for(int i = 2; i <= n; ++i){
        ans[i] = LLONG_MIN;
    
        int u = i - a[i];
        LL k = a[i];
        if(u == 1){ u = i; }
        else if(u > 1){
            k += a[u];
            u += a[u];
        }

        if(u <= 0 || u > n){ u = -1; }
        to[i] = u;
        c[i] = k;
        
        if(u > 0){
            G[u].push_back(pii(i, k));
            ++cnt[i];
        }
        else{
            q.push(i);
            ans[i] = k;
        }
    }

    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i = 0; i < G[t].size(); ++i){
            int u = G[t][i].first;
            ans[u] = ans[t] + G[t][i].second;
            if(!--cnt[u]){ q.push(u); }
        }
    }

    for(int i = 1; i < n; ++i){
        LL a = max(ans[1 + i] + i, -1LL);
        printf("%I64d\n", a);
    }
}