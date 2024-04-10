#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<complex>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

bool ng[110][110];
bool exist[110];

vector<int> degs;
vector<P> edge[220000];
vector<int> come[220000];

int n, m, k, a, b, w;

int dfs(int x){
    if(x == k){
        for(auto d:degs){
            for(auto e:degs){
                if(ng[d][e])return 0;
            }
        }
        return 1;
    }
    int ans = 0;
    x++;
    for(int i = 0;i < x;i++){
        degs.push_back(x * 10 + i);
        ans += dfs(x);
        degs.pop_back();
    }
    return ans;
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0;i < m;i++){
        scanf("%d%d%d", &a, &b, &w);a--,b--;
        edge[a].push_back(P(w, b));
    }
    for(int i = 0;i < n;i++){
        sort(edge[i].begin(), edge[i].end());
        for(int j = 0;j < edge[i].size();j++){
            int to = edge[i][j].second;
            come[to].push_back(edge[i].size()*10+j);
        }
    }
    for(int i = 0;i < n;i++){
        sort(come[i].begin(), come[i].end());
        for(int j = 1;j < come[i].size();j++){
            if(come[i][j-1] == come[i][j])ng[come[i][j]][come[i][j]] = true;
        }
        come[i].erase(unique(come[i].begin(), come[i].end()), come[i].end());
        for(int j = 0;j < come[i].size();j++){
            for(int k = j+1;k < come[i].size();k++){
                ng[come[i][j]][come[i][k]] = ng[come[i][k]][come[i][j]] = true;
            }
        }
    }

    cout << dfs(0) << endl;
    
    return 0;
}