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

    ///CODE
    int n; cin >>n;
    vector<ll> a(n), b(n), x(n);
    vector<pair<ll, int> > y(n);
    for(auto &e:a) cin >> e;
    for(auto &e:b) cin >> e;
    for(int i=0;i<n;++i){
        y[i] = make_pair(b[i], i);
    }
    sort(y.rbegin(), y.rend());
    sort(a.begin(), a.end());
    for(int i=0;i<n;++i){
        x[y[i].second] = a[i];
    }
    copy(x.begin(), x.end(), ostream_iterator<ll>(cout, " "));
    cout << "\n";


    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}