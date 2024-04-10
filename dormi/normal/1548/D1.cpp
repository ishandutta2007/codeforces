#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=6001;
pll arr[MN];
ll cnt[2][2];
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
        arr[i].first /= 2, arr[i].second /= 2;
        cnt[arr[i].first % 2][arr[i].second % 2]++;
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        cnt[arr[i].first%2][arr[i].second%2]--;
        for (int j = 0; j < 2; j++) {
            for (int j2 = 0; j2 < 2; j2++) {
                if(cnt[j][j2]) {
                    ll am=cnt[j][j2];
                    cnt[j][j2]--;
                    for (int k = 0; k < 2; k++) {
                        for (int k2 = 0; k2 < 2; k2++) {
                            if ((__gcd(abs(k - arr[i].first), abs(k2 - arr[i].second)) + __gcd(abs(k - j), abs(k2 - j2)) + __gcd(abs(arr[i].first - j), abs(arr[i].second - j2))) % 2 == 0) {
                                ans += am*cnt[k][k2];
                            }
                        }
                    }
                    cnt[j][j2]++;
                }
            }
        }
        cnt[arr[i].first%2][arr[i].second%2]++;
    }
    printf("%lli\n",ans/6);
    return 0;
}