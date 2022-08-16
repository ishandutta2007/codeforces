#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

ll cost(ll x){
    return x*(x-1)/2;
}
vector<ll> can;

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
    if(n == 0){
        cout << "a\n";
    } else {
        vector<ll> d;
        for(ll i = n+2;i>1;--i){
            while(n && n >= cost(i)){
                d.push_back(i);
                n-=cost(i);
            }
        }
        assert(n == 0);
        assert(d.size() < 25);
        for(int i=0;i<(int)d.size();++i){
            cout << string(d[i], 'a'+i);
        }

        cout << "\n";
    }


    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}