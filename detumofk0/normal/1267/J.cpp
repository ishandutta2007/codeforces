#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("inp", "r")) freopen("inp", "r", stdin);

    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector < int > a(n), cnt(n, 0);
        for(int &x : a) {
            cin >> x; x--;
            cnt[x]++;
        }

        vector < int > comps;
        for(int &t : cnt) if(t > 0) comps.push_back(t);

        int ans = n;

        sort(comps.begin(), comps.end());
        for(int s = 2; s <= comps.front() + 1; ++s) {
            int ret = 0;
            for(int x : comps) {
                if(x % s == 0) {
                    ret += x / s;
                    continue;
                }
                int a = x % (s - 1), b = x / (s - 1), c = (b - a) / s;
                if (a > b) ret = n;
                else b -= c, ret += b;
            }
            ans = min(ans, ret);
        }

        cout << ans << "\n";
    }

    return 0;
}