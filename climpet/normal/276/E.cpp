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


struct BIT{
    vector<int> b;
    
    BIT(int n): b(n + 1){}
    
    int sum(int i){
        int s = 0;
        while(i > 0){
            s += b[i];
            i -= i & -i;
        }
        return s;
    }
    
    void add(int i, int x){
        while(i < b.size()){
            b[i] += x;
            i += i & -i;
        }
    }
};



int main(){
    int n, m, q, v, x, d;
    scanf("%d%d", &n, &q);

    vvint G(n + 1);
    for(int i = 1; i < n; ++i){
        scanf("%d%d", &v, &x);
        G[v].push_back(x);
        G[x].push_back(v);
    }

    vector<char> visit(n + 1);
    vint rnum(n + 1, -1);
    vint dist(n + 1, -1);
    vint vcnt(G[1].size(), -1);

    dist[1] = 0;
    visit[1] = 1;
    for(int i = 0; i < G[1].size(); ++i){
        v = G[1][i];
        d = 0;
        do{
            visit[v] = 1;
            dist[v] = ++d;
            rnum[v] = i;
            x = -1;
            for(int j = 0; j < G[v].size(); ++j){
                if(!visit[G[v][j]]){
                    x = G[v][j];
                }
            }
            v = x;
        } while(x != -1);
        
        vcnt[i] = d;
    }

    vector<BIT> rbits;
    rbits.reserve(vcnt.size());
    for(int i = 0; i < vcnt.size(); ++i){
        rbits.push_back(BIT(vcnt[i] + 3));
    }

    BIT root(n + 3);

    for(; q--; ){
        scanf("%d%d", &m, &v);
        int r = rnum[v];

        if(m == 0){
            scanf("%d%d", &x, &d);
            if(v == 1){
                root.add(1, x);
                root.add(d + 2, -x);
            }
            else if(d >= dist[v]){
                int k = d - dist[v];
                root.add(1, x);
                root.add(k + 2, -x);

                rbits[r].add(min(k + 1, vcnt[r] + 2), x);
                rbits[r].add(min(dist[v] + d + 1, vcnt[r] + 2), -x);
            }
            else{
                rbits[r].add(dist[v] - d, x);
                rbits[r].add(min(dist[v] + d + 1, vcnt[r] + 2), -x);
            }
        }
        else{
            int ans = 0;
            if(v == 1){
                ans = root.sum(1);
            }
            else{
                int r = rnum[v];
                d = dist[v];
                ans = rbits[r].sum(d) + root.sum(d + 1);
            }
            printf("%d\n", ans);
        }
    }
}