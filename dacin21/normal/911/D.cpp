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

    int n, m;
    cin >> n;
    vector<int> a(n);
    for(auto &e:a) cin >> e;

    ll invs = 0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            invs+=(a[i]>a[j]);
        }
    }
    invs%=2;
    cin >> m;
    for(int i=0;i<m;++i){
        int l, r;
        cin >> l >> r;
        int d = r-l+1;
        invs+=(d>>1);
        if(invs%2){
            cout << "odd\n";
        } else {
            cout << "even\n";
        }
        invs%=2;
    }



    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}