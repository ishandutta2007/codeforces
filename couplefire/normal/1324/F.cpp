#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n;
vector<int> adj[MAXN];
int color[MAXN];
int ans[MAXN] = {0};
int aans[MAXN];

void dp1(int v, int p){
    ans[v] = color[v];
    for(auto i : adj[v]){
        if(i == p) continue;
        dp1(i, v);
        ans[v] += max(0, ans[i]);
    }
}

void dp2(int v, int p){
    aans[v] = ans[v];
    for(auto i : adj[v]){
        if(i == p) continue;
        ans[v] -= max(0, ans[i]);
        ans[i] += max(0, ans[v]);
        dp2(i, v);
        ans[i] -= max(0, ans[v]);
        ans[v] += max(0, ans[i]);
    }
}

int main(){
    //freopen("a.in", "r", stdin);
    cin >> n;
    for(int i = 0; i<n; i++){
        int a; cin >> a;
        color[i] = (a == 1) ? 1 : -1;
    }
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dp1(0, -1);
    dp2(0, -1);
    for(int i = 0; i<n; i++) cout << aans[i] << " ";
    cout << endl;

}