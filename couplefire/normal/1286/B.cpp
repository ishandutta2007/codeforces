#include <bits/stdc++.h>
using namespace std;
int n;
int root;
vector<int> children[2005];
int ans[2005];
int num[2005];
int cc[2005];

void add(int v, int a){
    ans[v]+=a;
    for(auto i : children[v]) add(i, a);
}

void check(int v, int i){
    if(ans[v] > cc[i]) ans[v]++;
    for(auto k : children[v]) check(k, i);
}

void getAns(int v){
    num[v] = 1;
    int prev = 0;
    for(auto i : children[v]){
        getAns(i);
        add(i, prev);
        prev += num[i];
        num[v] += num[i];
    }
    if(cc[v] >= num[v]){
        cout << "NO" << endl;
        exit(0);
    }
    check(v, v);
    if(children[v].size() == 0){
        ans[v] = 1;
    }
    else{
        ans[v] = cc[v]+1;
    }
}

int main(){
    //freopen("a.in", "r", stdin);
    cin >> n;
    for(int i = 0; i<n; i++){
        int p, c; cin >> p >> c;
        --p;
        if(p == -1){
            root = i;
        }
        else children[p].push_back(i);
        cc[i] = c;
    }
    getAns(root);
    cout << "YES" << endl;
    for(int i = 0; i<n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}