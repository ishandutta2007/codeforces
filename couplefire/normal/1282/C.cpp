#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    long long q; cin >> q;
    while(q--){
        long long n, t, a, b; cin >> n >> t >> a >> b;
        set<long long> check;
        long long arr[n];
        long long ta = 0, tb = 0;
        long long ca = 0, cb = 0;
        map<long long, pair<long long, long long>> mp;
        for(long long i = 0; i<n; i++){
            cin >> arr[i];
            if(arr[i]) tb++;
            else ta++;
        }
        for(long long i = 0; i<n; i++){
            long long tt; cin >> tt;
            if(arr[i]) mp[tt].second++;
            else mp[tt].first++;
            check.insert(tt);
            check.insert(tt-1);
        }
        check.insert(t);
        long long ans = 0;
        while(!check.empty()){
            long long top = *check.begin();
            check.erase(check.begin());
            long long tans = 0;
            if(mp.count(top)) ca += mp[top].first, cb += mp[top].second;
            //cout << ca << " " << cb << endl;
            top -= ca*a;
            top -= cb*b;
            if(top < 0) continue;
            tans += ca + cb;
            tans += min(top/a, ta-ca);
            top -= a*min(top/a, ta-ca);
            tans += min(top/b, tb-cb);
            top -= b*min(top/b, tb-cb);
            ans = max(ans, tans);
        }
        cout << ans << endl;
    }
}