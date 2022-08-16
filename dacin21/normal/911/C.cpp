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
    freopen("inC.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT; while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    array<int, 3> a;
    for(auto &e:a) cin >> e;
    sort(a.begin(), a.end());
    bool f = true;
    if(a[0] == 1) f=false;
    if(a[0] == 2 && a[1] == 2) f=false;
    if(a[0] == 3 && a[1] == 3 && a[2] == 3) f = false;
    if(a[0] == 2 && a[1] == 4 && a[2] == 4) f=false;
    if(f){
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }



    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}