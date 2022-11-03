#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> llll;

int N;
ll TL, WL;
llll K[300300];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin >> N >> TL >> WL;
    for(int n = 0; n < N - 1; ++n) {
        ll t, w;
        cin >> t >> w;
        K[n] = llll(t, w + 1 - t);
    }
    K[N - 1] = llll(0LL, 1LL << 60);
    sort(K, K + N, greater<llll>());
    for(int n = 0; n < N; ++n)
        swap(K[n].first, K[n].second);
    priority_queue<llll, vector<llll>, greater<llll>> P;
    priority_queue<llll> Q;
    int ans = 1 << 30;
    ll B = TL - K[0].second;
    for(int n = 0; n < N;) {
        while(B >= 0) {
            if(P.empty()) {
                cout << "1" << '\n';
                return 0;
            }
            Q.push(P.top());
            B -= P.top().first;
            P.pop();
        }
        if(Q.size()) {
            P.push(Q.top());
            B += Q.top().first;
            Q.pop();
        }
        if(B >= 0)
            ans = min(ans, 1 + int(P.size()));
        do {
            Q.push(K[n]);
            B -= K[n].first;
            B += Q.top().first;
            P.push(Q.top());
            Q.pop();
            ++n;
        } while(n < N && K[n - 1].second == K[n].second);
        if(n < N)
            B += K[n - 1].second - K[n].second;
    }
    cout << ans << '\n';
}