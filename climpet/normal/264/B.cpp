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

bool isnp[100001];
int index[100001];
int dp[100001];

int main(){
    for(int i = 2; i < 350; ++i)
        if(!isnp[i])
            for(int j = i * i; j <= 100000; j += i)
                isnp[j] = true;

    memset(index, -1, sizeof index);

    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        index[a[i]] = i;
    }

    vvint fc(n);
    for(int i = 2; i < 99998; ++i){
        if(isnp[i]) continue;
        for(int j = i; j <= 100000; j += i){
            if(index[j] >= 0){
                fc[index[j]].push_back(i);
            }
        }
    }

    int ans = 1;
    for(int i = 0; i < n; ++i){
        int t = 1;
        for(int j = 0; j < fc[i].size(); ++j){
            t = max(t, dp[fc[i][j]] + 1);
        }
        ans = max(ans, t);
        for(int j = 0; j < fc[i].size(); ++j){
            dp[fc[i][j]] = t;
        }
    }
    
    printf("%d\n", ans);
}