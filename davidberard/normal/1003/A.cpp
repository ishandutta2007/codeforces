#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int amt[1000];

int main () {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    int ans = 0;
    for(int i=1;i<=N;++i) {
        int a;
        cin >> a;
        ans = max(ans, ++amt[a]);
    }
    cout << ans << endl;
    return 0;
}