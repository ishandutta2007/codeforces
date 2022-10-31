//https://codeforces.com/problemset/problem/1207/D

#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n; cin >> n;
    vector<pair<long long, long long>> v1(n);
    vector<pair<long long, long long>> v2(n);
    for(long long i = 0; i<n; i++){
        long long a, b; cin >> a >> b;
        v1[i] = {a, b};
        v2[i] = {b, a};
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    long long fact[n+1];
    fact[0] = 1;
    for(long long i = 1; i<=n; i++) fact[i] = (i*fact[i-1])%MOD;
    long long ans1 = 1;
    long long prev = -1;
    long long num = 1;
    for(long long i = 0; i<n; i++){
        if(v1[i].first != prev){
            ans1 *= fact[num];
            ans1 %= MOD;
            num = 1;
            prev = v1[i].first;
        }
        else num++;
    }
    ans1 *= fact[num];
    ans1 %= MOD;
    long long ans2 = 1;
    prev = -1;
    num = 1;
    for(long long i = 0; i<n; i++){
        if(v2[i].first != prev){
            ans2 *= fact[num];
            ans2 %= MOD;
            num = 1;
            prev = v2[i].first;
        }
        else num++;
    }
    ans2 *= fact[num];
    ans2 %= MOD;
    long long ans3 = 1;
    pair<long long, long long> pre = {-1, -1};
    num = 1;
    for(long long i = 1; i<n; i++){
        if(v1[i].second < v1[i-1].second) ans3 = 0;
    }
    for(long long i = 0; i<n; i++){
        if(v1[i] != pre){
            ans3 *= fact[num];
            ans3 %= MOD;
            num = 1;
            pre = v1[i];
        }
        else num++;
    }
    ans3 *= fact[num];
    ans3 %= MOD;
    cout << ((fact[n]-ans1-ans2+ans3)%MOD+MOD)%MOD << endl;
}