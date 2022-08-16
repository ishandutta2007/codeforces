#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

constexpr ll inf = 2e18;

signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT; while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    int n;
    cin >> n;
    vector<int> a(2*n);
    for(auto &e:a) cin >> e;
    sort(a.begin(), a.end());
    ll ans = 2e18;
    for(int i=0;i<n;++i){
        ll x = a[n-1+i] - a[i];
        ll y;
        if(i == 0){
            y = a[2*n-1] - a[n];
        } else {
            y = a[2*n-1] - a[0];
        }
        xmin(ans, x*y);
    }
    cout << ans << "\n";


    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}