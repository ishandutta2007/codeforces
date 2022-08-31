#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &e:a) cin >> e;
    sort(a.begin(), a.end());
    ll l=-1, r=2e9;
    while(l+1<r){
        ll m = l+(r-l)/2;
        vector<char> can(n+1, 0);
        can[0] = 1;
        int lastcan = -1e9;
        for(int i=k-1;i<n;++i){
            if(i>=k-1){
                if(can[i-k+1]){
                    lastcan = i-k+1;
                }
            }
            if(lastcan>=0 && a[i]-a[lastcan]<=m){
                can[i+1] = 1;
            }
        }
        if(can.back()){
            r=m;
        } else {
            l=m;
        }
    }
    cout << r << "\n";


    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}