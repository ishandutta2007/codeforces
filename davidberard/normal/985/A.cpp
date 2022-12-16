#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
vector<int> v;

int cnt(int pairity) {
    stack<int> needToPlace;
    int it = 0;
    int ans = 0;
    for(int i=1;i<=N;++i) {
        if(i%2 == pairity) {
            /*if(!needToPlace.empty()) {
                int pos = needToPlace.front(); needToPlace.pop();
                ans += i-pos;
            } else { */
                int pos = v[it++];
                if(pos == i) {
                    continue;
                }
                else if(pos < i) {
                    ans += i-pos;
                } else {
                    ans += pos-i;
                }
            //}
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    v = vector<int>(N/2);
    for(int& ii : v) cin >> ii;
    sort(v.begin(), v.end());
    int ans = min(cnt(0), cnt(1));
    cout << ans << endl;
    return 0;
}