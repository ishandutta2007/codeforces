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
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

vector<int> child[2200];
Int p,  n;
Int a[220000], c[220000];
bool ng;
vector<int> dfs(int x){
    vector<int> de;
    for(auto to:child[x]){
        auto tmp = dfs(to);
        de.insert(de.end(), tmp.begin(), tmp.end());
    }
    if(de.size() < c[x])ng = true;
    else
        de.insert(de.begin() + c[x], x);
    return de;
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> p >> c[i];
        child[p].push_back(i);
        
    }
    int root = child[0][0];
    auto tmp = dfs(root);
    if(ng)cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        for(int i = 0;i < n;i++)a[tmp[i]] = i+1;
        for(int i = 1;i <= n;i++)cout << a[i] << " ";
    }cout << endl;
    return 0;
}