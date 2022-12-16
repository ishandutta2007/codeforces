#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N, k;
    cin >> N;
    cin >> k;
    deque<int> dq;
    for(int i=0;i<N;++i) {
        int v;
        cin >> v;
        dq.push_back(v);
    }
    int cnt = 0;
    while(!dq.empty() && dq.back() <= k) {
        ++cnt;
        dq.pop_back();
    }
    while(!dq.empty() && dq.front() <= k) {
        ++cnt;
        dq.pop_front();
    }
    cout << cnt << endl;
    return 0;
}