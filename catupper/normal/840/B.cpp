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

Int n, m;
Int d[330000];
Int u[330000];
Int v[330000];
vector<Int> edge[330000];

int cnt[330000];
bool come[330000];

vector<int> ans;

void dfs(int x){
    if(come[x])return;
    come[x] = true;
    for(auto edge_ind:edge[x]){
        int to = u[edge_ind] + v[edge_ind] - x;
        if(come[to])continue;
        dfs(to);
        if(cnt[to] % 2 == 1)ans.push_back(edge_ind);
        cnt[x] += cnt[to];
    }
}
    

int main(){
    cin >> n >> m;
    vector<int> ones;
    vector<int> frees;
    for(int i = 1;i <= n;i++){
        cin >> d[i];
        if(d[i] == 1)ones.push_back(i);
        if(d[i] == -1)frees.push_back(i);
    }
    for(int i = 1;i <= m;i++){
        cin >> u[i] >> v[i];
        edge[u[i]].push_back(i);
        edge[v[i]].push_back(i);
    }
    if(ones.size() % 2 == 1){
        if(frees.empty()){
        cout << -1 << endl;
        return 0;
        }
        ones.push_back(frees.back());
    }

    for(auto elem:ones){
        cnt[elem] = 1;
    }

    dfs(1);

    printf("%d\n", int(ans.size()));
    for(auto elem:ans)printf("%d\n", elem);
    
    return 0;
}