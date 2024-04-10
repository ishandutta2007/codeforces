#include <bits/stdc++.h>
using namespace std;

void solve(){
    int tot, len; cin >> tot >> len;
    set<array<int, 2>, greater<>> st;
    for(int i = 1; i<=len; i++){
        int val; cin >> val;
        if(val == 0) continue;
        st.insert({val, i});
    }
    int n = 0;
    for(;;n++){
        int v = n*n, v_lo = (n/2)*(n/2), v_hi = ((n+1)/2)*((n+1)/2);
        if(v-v_lo < tot) continue;
        if(v_hi + (v-v_lo-v_hi)/2 < (*st.begin())[0]) continue;
        break;
    }
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i = 0; i<n; i+=2){
        for(int j = 0; j<n; j+=2){
            if(st.empty()) break;
            auto x = (*st.begin()); st.erase(st.begin());
            grid[i][j] = x[1]; x[0]--;
            if(x[0]) st.insert(x);
        }
    }
    queue<int> todo;
    for(auto x : st){
        while(x[0]--) todo.push(x[1]);
    }
    for(int i = (n+1)%2; i<n; i+=2){
        for(int j = n%2; j<n; j+=2){
            if(todo.empty()) break;
            grid[i][j] = todo.front(); todo.pop();
        }
    }
    for(int i = n%2; i<n; i+=2){
        for(int j = (n+1)%2; j<n; j+=2){
            if(todo.empty()) break;
            grid[i][j] = todo.front(); todo.pop();
        }
    }
    cout << n << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) cout << grid[i][j] << " ";
        cout << endl;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}