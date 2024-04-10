#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N, M;
    cin >> N;
    cin >> M;
    vector<int> c(N), a(M);
    for(auto& ii : c) cin >> ii;
    for(auto& ii : a) cin >> ii;
    int w = 0;
    int amt = 0;
    for(int i=0;i<N;++i) {
        if(w == M || a[w] < c[i]) continue;
        ++amt;
        ++w;
    }
    cout << amt << endl;
    return 0;
}