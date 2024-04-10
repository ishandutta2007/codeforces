//https://codeforces.com/problemset/problem/1210/B

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n; cin >> n;
    vector<pair<long long, long long>> v(n);
    vector<long long> skill(n);
    for(long long i = 0; i<n; i++){
        long long a; cin >> a;
        v[i] = {a, i};
    }
    for(long long i = 0; i<n; i++) cin >> skill[i];
    vector<pair<long long, long long>> vv;
    sort(v.rbegin(), v.rend());
    if(v[0].first == v[1].first) vv.push_back(v[0]);
    if(v[n-1].first == v[n-2].first) vv.push_back(v[n-1]);
    for(long long i = 1; i<n-1; i++){
        if(v[i].first == v[i-1].first || v[i].first == v[i+1].first) vv.push_back(v[i]);
    }
    long long ans = 0;
    for(long long i = 0; i<n; i++){
        for(auto k : vv){
            if((v[i].first | k.first) == k.first){
                ans += skill[v[i].second];
                break;
            }
        }
    }
    cout << ans << endl;
}