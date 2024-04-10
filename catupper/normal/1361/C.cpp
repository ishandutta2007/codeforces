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

Int v[1100000];
Int n;

vector<Int> ans;
vector<Int> edge[1 << 20];
bool come[1 << 20];
bool used[1 << 20];

void dfs(int x){
    if(come[x])return;
    come[x] = true;
    for(auto e: edge[x]){
        int other = v[2*e-1] + v[2*e] - x;
        dfs(other);
    }
}

void dfs2(Int now){
    while(!edge[now].empty()){
        auto e = edge[now].back();edge[now].pop_back();
        if(used[e])continue;
        used[e] = true;
        int other = v[2*e-1] + v[2*e] - now;
        dfs2(other);
        if(v[2*e-1] == other){
            ans.push_back(2*e-1);
            ans.push_back(2*e);
        }
        else{
            ans.push_back(2*e);
            ans.push_back(2*e-1);
        }
    }
}

bool check(Int v){
    v = min(v+1,1LL<<20);
    for(int i = 0;i < v;i++){
        if(edge[i].size() % 2 == 1)return false;
    }
    int s = 0;
    fill(come, come + v, false);
    while(edge[s].empty())s++;
    dfs(s);
    for(int i = 0;i < v;i++){
        if(edge[i].empty())continue;
        if(!come[i])return false;
    }
    dfs2(s);
    return true;
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> v[2*i-1] >> v[2*i];
    }
    int ansv = 20;
    for(;ansv >= 0;ansv--){
        Int mask = (1 << ansv)-1;
        for(int i = 0;i <= mask && i < (1<<20);i++)edge[i].clear();
        for(int i = 1;i <= n;i++){
            v[2*i-1] &= mask;
            v[2*i] &= mask;
            edge[v[2*i-1]].push_back(i);
            edge[v[2*i]].push_back(i);
        }
        if(check(mask))break;
    }
    cout << ansv<< endl;
    for(auto a:ans)printf("%lld ", a);puts("");
    
    return 0;
}