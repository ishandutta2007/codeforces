#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000009ll
#define MAXN (int)35e6

long long gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

long long inverse(long long n, long long m){
    long long x, y;
    long long g = gcd(n,m, x, y);
    return (x%m+m)%m;
}

int lp[MAXN+1];
vector<int> pri;

void genPrimes(){
    for(int i=2; i<=MAXN; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pri.push_back (i);
        }
        for (int j=0; j<(int)pri.size() && pri[j]<=lp[i] && i*pri[j]<=MAXN; ++j)
            lp[i * pri[j]] = pri[j];
    }
}

int t;
map<long long, vector<pair<long long, int>>> mp;
vector<string> ans;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    ans.resize(t);
    for(int i = 0; i<t; i++){
        long long n, k; cin >> n >> k;
        mp[k].push_back({n, i});
    }
    genPrimes();
    for(auto w : mp){
        long long k = w.first;
        long long kk = k;
        vector<pair<long long, int>> vv = w.second;
        vector<long long> primes;
        for(int i = 0; i<pri.size(); i++){
            if(k%pri[i]) continue;
            primes.push_back(pri[i]);
            while(k%pri[i] == 0) k/= pri[i];
        }
        if(k != 1) primes.push_back(k);
        primes.erase(unique(primes.begin(), primes.end()), primes.end());
        for(auto p : vv){
            long long n = p.first, ind = p.second;
            if(kk == 1){
                ans[ind] = "NO";
                continue;
            }
            if(__gcd(n, kk) != 1){
                ans[ind] = "YES";
                continue;
            }
            if(primes.size() == 1){
                ans[ind] = "NO";
                continue;
            }
            if(primes.size() == 2){
                long long x = primes[0], y = primes[1];
                long long invy = inverse(y, x);
                long long b = n%x*invy%x;
                assert((n-b*y)%x == 0);
                long long a = (n-b*y)/x;
                if(a >= 0 && b >= 0){
                    ans[ind] = "YES";
                }
                else ans[ind] = "NO";
                continue;
            }
        }
        if(primes.size() <= 2) continue;
        long long p0 = primes[0];
        assert(p0 <= 100000);
        vector<long long> d(p0, INF);
        d[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        q.push({0, 0});
        while(!q.empty()){
            long long v = q.top().second;
            long long dv = q.top().first;
            q.pop();
            if(dv != d[v]) continue;
            for(int i = 1; i<primes.size(); i++){
                long long u = (primes[i]+v)%p0;
                long long len = primes[i];
                if(d[v]+len < d[u]){
                    d[u] = d[v]+len;
                    q.push({d[u], u});
                }
            }
        }
        for(auto p : vv){
            long long n = p.first, ind = p.second;
            if(d[n%p0] <= n) ans[ind] = "YES";
            else ans[ind] = "NO";
        }
    }
    for(int i = 0; i<t; i++) cout << ans[i] << endl;
}