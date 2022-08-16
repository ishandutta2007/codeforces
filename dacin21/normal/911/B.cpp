#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

constexpr int inf = 1e9;

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

    int n, a, b;
    cin >> n >> a >> b;
    int ans = -inf;
    for(int i=1;i<n;++i){
        xmax(ans, min(a/i, b/(n-i)));
    }
    cout << ans << "\n";



    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}