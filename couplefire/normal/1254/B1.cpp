//https://codeforces.com/problemset/problem/1254/B1

#include <bits/stdc++.h>
using namespace std;
#define INF 10000000000000

int main(){
    long long n; cin >> n;
    vector<long long> arr(n);
    long long ss = 0;
    for(long long i = 0; i<n; i++){
        cin >> arr[i];
        ss += arr[i];
    }
    vector<long long> fact;
    for(long long i = 2; i<=ss; i++) if((ss/i)*i == ss) fact.push_back(i);
    if(fact.empty()){
        cout << -1 << endl;
        return 0;
    }
    long long cur = INF;
    for(auto k : fact){
        long long s = 0;
        vector<long long> tt;
        long long a = 0;
        for(long long i = 0; i<n; i++){
            if(arr[i] == 1){
                s++;
                tt.push_back(i);
            }
            if(s == k){
                long long m = tt.size()/2;
                for(long long j = 0; j<tt.size(); j++) a += abs(tt[j]-tt[m]);
                s = 0;
                tt.clear();
            }
        }
        cur = min(cur, a);
    }
    cout << cur << endl;
}