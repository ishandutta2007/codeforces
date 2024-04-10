#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
ifstream input_from_file("input.txt");
#define cin input_from_file
#endif

typedef long long LL;
typedef pair<int, int> II;

struct Fen{
    int n;
    vector<LL> c, s;
    Fen(int n):n(n), c(n+1), s(n+1){}
    void update(int pos, LL x){
        for(int z=pos; z <= n; z += z & -z){
            c[z] ++;
            s[z] += x;
        }
    }
    LL query(int pos){
        int l = 0; int r = n;
        while(l < r){
            int k = (l + r) / 2;
            int C = 0;
            for(int z = k; z > 0; z -= z & -z) C += c[z];
            
            if(C < pos) l = k + 1; else r = k;
        }
        LL ans = 0;
        for(int k = l; k > 0; k -= k & -k) ans += s[k];
        //~ cerr << "query " << pos << " -> " << ans << endl;
        return ans;
    }
};

void solve(){
    LL n, m; LL t;
    cin >> n >> m >> t;
    vector<LL> a(n+1); for(int i=1; i<=n; i++) cin >> a[i];
    vector<pair<LL,int>> b(n);
    for(int i=1; i<=n; i++) b[i-1] = {a[i], i};
    sort(b.begin(), b.end());
    
    LL tot = 0;
    LL cnt = 0;
    LL lastd = 0;
    pair<LL, LL> ans(0,1);
    Fen f(n);
    for(int i=0; i<n; i++){
        auto p = b[i];
        f.update(p.second, p.first);
        cnt++;
        tot += p.first;
        lastd = p.first;
        if(i == n-1 or p.first < b[i+1].first){
            LL x = (cnt - 1) / m;
            LL T = tot + f.query(x * m);
            if(T <= t) ans = max(ans, pair<LL,LL>(cnt, lastd)); else break;
        }
    }
    
    cnt = 0;
    LL T = 0;
    LL lb = 0;
    for(int i=1; i<=n; i++){
        if(a[i] <= lastd){
            if(cnt % m == 0) {T += lb; lb = 0;}
            T += a[i];
            lb += a[i];
            cnt++;
        }
        if(T > t) break;
        ans = max(ans, {cnt, lastd});
    }
    if(ans.second > t) ans.second = t;
    cout << ans.first << ' ' << ans.second << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int ttc; cin >> ttc;
    for(int i=0; i<ttc; i++) solve();
    
    
}