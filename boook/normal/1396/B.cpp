// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 1010
#define inf 0x3f3f3f3f

int t, n, x[maxn];

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; ++ i) cin >> x[i];
        priority_queue<PII> pq;
        for (int i = 1; i <= n; ++ i) pq.push(make_pair(x[i], i));
        
        int now = 0, pre = -1;
        while (1) {
            if (pq.size() == 0) break;
            else {
                PII fir = pq.top(); pq.pop();
                if (fir.S == pre) {
                    if (pq.size() == 0) break;
                    else {
                        PII sec = pq.top(); pq.pop();
                        pre = sec.S, sec.F --;
                        if (sec.F > 0) pq.push(sec);
                        if (fir.F > 0) pq.push(fir);
                    }
                } else {
                    pre = fir.S, fir.F --;
                    if (fir.F > 0) pq.push(fir);
                }
            }

            now ^= 1;
        }
        if (now == 0) cout << "HL\n";
        else cout << "T\n";
    }
    return 0;
}