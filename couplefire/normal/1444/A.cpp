#include <bits/stdc++.h>
using namespace std;

vector<long long> trial_division1(long long n) {
    vector<long long> factorization;
    for (int d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int maxDiv(long long a, long long b){
    int cnt = 0;
    while(a%b == 0) a/=b, cnt++;
    return cnt;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        long long p, q; cin >> p >> q;
        if(p%q != 0){
            cout << p << endl;
            continue;
        }
        vector<long long> factors = trial_division1(q);
        map<long long, int> mp;
        for(auto f : factors) mp[f]++;
        long long least = 1000000000000000009;
        for(auto i : mp){
            int cnt = maxDiv(p, i.first);
            long long getpw = 1;
            for(int j = 0; j<cnt-i.second+1; j++) getpw *= i.first;
            least = min(least, getpw);
        }
        cout << p/least << endl;
    }
}