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


int par[101];
int cnt[101];
int find(int x){
    return x != par[x] ? par[x] = find(par[x]) : x;
}


int main(){
    int n, m, k, a, b;
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= m; ++i){
        par[i] = i;
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d", &k);
        if(k == 0){ ++ans; }
        else{
            scanf("%d", &a);
            ++cnt[a];
            for(int j = 1; j < k; ++j){
                scanf("%d", &b);
                ++cnt[b];
                par[find(a)] = find(b);
            }
        }
    }

    int t = -1;
    for(int i = 1; i <= m; ++i){
        if(cnt[i] && par[i] == i){
            ++t;
        }
    }
    if(t > 0){ ans += t; }
    printf("%d\n", ans);
}