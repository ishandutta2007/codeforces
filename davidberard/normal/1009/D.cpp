#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N, M;
    cin >> N;
    cin >> M;
    if(M < N-1) {
        cout << "Impossible" << endl;
        return 0;
    }
    vector<pii> edges;
    int cnt = 0;
    for(int i=1;i<N;++i) {
        edges.push_back(pii(i, i+1));
        ++cnt;
    }
    for(int i=1;i<N && cnt < M;++i) {
        for(int j=i+2;j<=N && cnt < M;++j) {
            if(__gcd(i, j) == 1) {
                edges.emplace_back(i, j);
                ++cnt;
            }
        }
    }
    if(cnt == M) {
        cout << "Possible" << endl;
        for(auto& x : edges) {
            cout << x.first << " " << x.second << "\n";

        }
    } else {
        cout << "Impossible" << endl;
    }
    
    return 0;
}