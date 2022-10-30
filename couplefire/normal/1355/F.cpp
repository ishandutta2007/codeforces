#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2021;
const bool DBG = 0;
const int X = 30030;

int lp[N+1];
vector<int> primes;

void genPrimes(){
    for(int i=2; i<=N; ++i){
        if(lp[i] == 0){
            lp[i] = i;
            primes.push_back(i);
        }
        for(int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j)
            lp[i * primes[j]] = primes[j];
    }
}

int eval(array<int, 2> lol){
    int res = 1;
    for(int i = 0; i<lol[1]; ++i)
        res *= lol[0];
    return res;
}

void solve(){
    int top = 0;
    deque<array<int, 2>> dq;
    map<int, int> mp;
    int _ = 22;
    while(_--){
        int cur = 1;
        vector<array<int, 2>> steps;
        while(1){
            if(dq.empty()) dq.push_back({primes[top++], 1});
            if(cur<=(1e18)/eval(dq.front()))
                cur *= eval(dq.front()), steps.push_back(dq.front()), dq.pop_front();
            else break;
        }
        cout << "? " << cur << endl;
        int res; 
        if(!DBG) cin >> res; 
        else res = __gcd(X, cur);
        reverse(steps.begin(), steps.end());
        for(auto [x, y] : steps){
            int cnt = 0;
            while(res%x==0ll) res/=x, cnt++;
            if(cnt==y) mp[x] = y;
            if(cnt==y && eval({x, y+1})<=1e9) dq.push_front({x, y+1});
        }
    }
    int ans = 1;
    for(auto [x, y] : mp)
        ans *= y+1;
    cout << "! " << 2*ans << endl;
}

signed main(){
    genPrimes();
    int t; 
    if(!DBG) cin >> t;
    else t = 1;
    while(t--) solve();
}