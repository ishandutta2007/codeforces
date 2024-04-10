#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[6][10001];

int ask(vector<ll> a){
    cout << a.size() << ' ';
    for(auto x : a) cout << x << ' ';
    cout << endl;
    int res; cin >> res;
    if(res<0) exit(0);
    return res;
}

void solve(int n, ll l){
    if(!n) exit(0);
    vector<ll> idx; ll cur = l;
    for(int i = 0; i<=min(l, 10000ll); ++i){
        cur += dp[n-1][min(cur, 10000ll)]+1;
        idx.push_back(cur-1);
    } idx.pop_back();
    int id = ask(idx);
    if(id==0) return solve(n-1, l);
    return solve(n-1, idx[id-1]+1);
}

int main(){
    for(int i = 1; i<=5; ++i)
        for(int j = 1; j<=10000; ++j){
            ll cur = j;
            for(int k = 0; k<=j; ++k){
                dp[i][j] += dp[i-1][cur]+1;
                cur = min(10000ll, cur+dp[i-1][cur]+1);
            } --dp[i][j];
        }
    solve(5, 1);
}