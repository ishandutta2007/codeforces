#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int NMAX = 500010;
int N, K, D;
vector<int> pencils;

struct segtree{
    vector<int> d;
    int n, h;
    segtree(int sz) {
        h = sizeof(int)*8 - __builtin_clz(sz);
        n = 1 << h;
        d = vector<int>(n<<1, 0);
    }
    void add(int l, int r) {
        for(l+=n, r+=n;l<r;l/=2, r/=2) {
            if(l%2) d[l++]++;
            if(r%2) d[--r]++;
        }
    }
    int query(int x) const {
        int ans = 0;
        for(x += n;x > 0;x/=2) {
            ans += d[x];
        }
        return ans;
    }
    int operator[] (const int& ind) const {
        return query(ind);
    }
};

/*
struct segtree2 {
    vector<int> t;
    int n, h;
    segtree(int sz) {
        h = sizeof(int)*8 - __builtin_clz(sz);
        n = 1 << h;
        t = vector<int>(n<<1, 0);
    }
    void 
}*/

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    cin >> K;
    cin >> D;

    segtree dp(N), dp2(N+1);

    for(int i=0;i<N;++i) {
        int ii;
        cin >> ii;
        pencils.push_back((ll) ii);
    }

    dp.add(0, 1);

    sort(pencils.begin(), pencils.end());
    for(int i=0;i<N+1;++i) {
        //cerr << i << ":" << dp[i] << endl;
        if(dp[i]) {
            auto top_it = upper_bound(pencils.begin(), pencils.end(), pencils[i]+D);
            int top = top_it-pencils.begin();
            //cerr << "Top is " << top << endl;
            if(top-i >= K) {
                //cerr << " set from " << i+K-1 << " to " << top << endl;
                dp.add(i+K, top+1);
            }
        }
    }
    cout << (dp[N] ? "YES" : "NO") << endl;

    return 0;
}