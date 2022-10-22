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

vector<string> ans;

bool come[220000];
int n, m, x, y;
vector<int> edge[220000];
int dep[220000];

void add(int x, int y, int z){
    ans.push_back(to_string(x) + " "  + to_string(y) + " " + to_string(z));
}

bool dfs(int x, int p = -1){
    come[x] = true;
    vector<int> back;
    for(auto to:edge[x]){
        if(to == p)continue;
        if(come[to]){
            if(dep[to] < dep[x])
                back.push_back(to);
        }
        else{
            dep[to] = dep[x] + 1;
            if(dfs(to, x))back.push_back(to);
        }
    }
    while(back.size() >= 2){
        int a = back.back();back.pop_back();
        int b = back.back();back.pop_back();
        add(a, x, b);
    }
    if(back.empty())return true;
    if(p != -1)add(back.back(), x, p);
    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for(int i = 1;i <= n;i++){
        if(!come[i])dfs(i);
    }
    cout << ans.size() << endl;
    for(auto x:ans)cout << x << endl;
    return 0;
}