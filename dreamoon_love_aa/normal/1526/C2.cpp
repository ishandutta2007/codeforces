#include<iostream>
#include<queue>
using namespace std;
void solve() {
    int n, an = 0;
    cin >> n;
    long long now = 0;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        now += x;
        pq.push(-x);
        if(now < 0) {
            now += pq.top();
            pq.pop();
        }
    }
    cout << pq.size() << '\n';
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}