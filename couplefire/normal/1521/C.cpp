#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000009;

int ask(int type, int i, int j, int x){
    cout << "? " << type << " " << i << " " << j << " " << x << endl;
    int res; cin >> res;
    return res;
}

void solve(){
    int n; cin >> n;
    vector<int> vals(n+1, INF);
    int p1;
    for(int i = 1; i<=n-1; i+=2){
        vals[i] = ask(2, i, i+1, 1);
    }
    int bruh1 = min_element(vals.begin(), vals.end())-vals.begin();
    vals.erase(vals.begin()+bruh1);
    int bruh2 = min_element(vals.begin(), vals.end())-vals.begin()+1;
    if(ask(1, bruh1, bruh1+1, 1) == 1) p1 = bruh1+1;
    else if(ask(1, bruh1+1, bruh1, 1) == 1) p1 = bruh1;
    else if(ask(1, bruh2, bruh2+1, 1) == 1) p1 = bruh2+1;
    else if(ask(1, bruh2+1, bruh2, 1) == 1) p1 = bruh2;
    else p1 = n;
    vector<int> ans(n+1); ans[p1] = 1;
    for(int i = 1; i<=n; i++){
        if(i == p1) continue;
        ans[i] = ask(1, p1, i, n-1);
    }
    cout << "! ";
    for(int i = 1; i<=n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}