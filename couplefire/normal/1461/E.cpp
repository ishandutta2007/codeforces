#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long k, l, r, t, x, y; cin >> k >> l >> r >> t >> x >> y;
    long long period = 0;
    set<long long> st;
    long long cur = k;
    long long yy = y-x;
    while(period < t && !st.count(cur%x)){
        if(cur > r || cur < l){
            cout << "No" << endl;
            exit(0);
        }
        st.insert(cur%x);
        long long reach = max(r-y-x+1, l);
        long long dec = max((cur-reach)/x, 0ll);
        period += dec;
        cur -= dec*x;
        reach = r-y;
        // cout << cur << endl;
        if(cur > reach && period < t){
            cout << "No" << endl;
            exit(0);
        }
        if(yy < 0){
            yy = -yy;
            long long time = (cur-l)/yy;
            if(time < t-period) cout << "No" << endl;
            else cout << "Yes" << endl;
            exit(0);
        }
        if(yy == 0){
            cout << "Yes" << endl;
            exit(0);
        }
        long long inc = max((reach-cur+yy-1)/yy, 1ll);
        cur += inc*yy;
        period += inc;
    }
    // cout << st.size() << endl;
    cout << "Yes" << endl;
}