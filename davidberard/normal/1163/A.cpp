#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int n, m;


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    if(m < 2) {
        cout << 1 << endl;
        return 0;
    }
    --m;
    priority_queue<int> pq;
    pq.push(n-1);
    for(int i=0; i<m; ++i) {
        int u = pq.top(); pq.pop();
        if(u >=5 ) {
            pq.push(3);
            pq.push(u-4);
        } else {
            int a = (u-1)/2;
            int b = u-1-a;
            if(a) pq.push(a);
            if(b) pq.push(b);
        }
    }
    cout << pq.size() << endl;
    return 0;
}