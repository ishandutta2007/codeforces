#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
using LL = long long;
 
int main(){
 
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
 
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
 
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        vector<multiset<LL> > s; 
        vector<int> factor, f, a(n);
        vector<vector<LL> > sum;
        for(int i = 1; i * i <= n; i++){
            if (n % i == 0){
                if (i != n) f.push_back(i);
                if (i * i != n && n / i != n) f.push_back(n / i);
            }
        }
        sort(f.begin(), f.end(), greater<int>());
        for(int i = 0; i < f.size(); i++){
            bool success = 1;
            for(auto x : factor)
                if (x % f[i] == 0){
                    success = 0;
                    break;
                }
            if (success) factor.push_back(f[i]);
        }
        sum.resize(factor.size());
        s.resize(factor.size());
        for(int i = 0; i < factor.size(); i++)
            sum[i].assign(factor[i], 0LL);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            for(int j = 0; j < factor.size(); j++)
                sum[j][i % factor[j]] += a[i];
        }
        LL ans = 0;
        for(int i = 0; i < factor.size(); i++){
            for(auto x : sum[i]) s[i].insert(x);
            ans = max(ans, factor[i] * (*s[i].rbegin()));
        }
        cout << ans << '\n';
        while(m--){
            int p, x;
            cin >> p >> x;
            p--;
            for(int i = 0; i < factor.size(); i++){
                s[i].erase(s[i].lower_bound(sum[i][p % factor[i]]));
                sum[i][p % factor[i]] -= a[p];
            }
            a[p] = x;
            ans = 0;
            for(int i = 0; i < factor.size(); i++){
                sum[i][p % factor[i]] += a[p];
                s[i].insert(sum[i][p % factor[i]]);
                ans = max(ans, factor[i] * (*s[i].rbegin()));
            }
            cout << ans << '\n';
        }
    }
 
}