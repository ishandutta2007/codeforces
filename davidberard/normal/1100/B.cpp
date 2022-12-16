#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for(int i=0;i<m;++i) {
        int a;
        cin >> a;
        if(mp.count(a) == 0) {
            mp[a] = 0;
        }
        mp[a]++;
        if(mp.size() == n) {
            cout << "1";
            for(int j=1;j<=n;++j) {
                if(--mp[j] == 0) {
                    mp.erase(j);
                }
            }
        } else {
            cout << "0";
        }
    }
    cout << endl;
    return 0;
}