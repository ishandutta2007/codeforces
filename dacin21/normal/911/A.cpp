#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

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

    int n; cin >> n;
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    int ma = *min_element(a.begin(), a.end());
    int la = -1e9, ans = 1e9;
    for(int i=0;i<n;++i){
        if(a[i] == ma){
            xmin(ans, i-la);
            la = i;
        }
    }
    cout << ans << "\n";


    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}