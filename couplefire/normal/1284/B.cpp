#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n; cin >> n;
    vector<long long> ma;
    vector<long long> mi;
    long long ans = 0;
    for(long long i = 0; i<n; i++){
        long long m; cin >> m;
        long long curmin = 100000000;
        long long curmax = -100000000;
        bool work = false;
        for(long long j = 0; j<m; j++){
            long long a; cin >> a;
            if(a > curmin) work = true;
            curmin = min(curmin, a);
            curmax = max(curmax, a);
        }
        if(!work){
            ma.push_back(curmax);
            mi.push_back(curmin);
        }
    }
    ans = (n-ma.size())*n*2;
    ans -= (n-ma.size())*(n-ma.size());
    sort(mi.begin(), mi.end());
    sort(ma.begin(), ma.end());
    for(long long i = 0; i<mi.size(); i++){
        long long len = ma.size()-(upper_bound(ma.begin(), ma.end(), mi[i])-ma.begin());
        ans += len;
    }
    cout << ans << endl;
}