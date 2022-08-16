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

    ll n, m, a, d;
    cin >> n >> m >> a >> d;
    vector<ll> t(m);
    for(auto &e:t) cin >> e;
    sort(t.begin(), t.end());
    ll next_n = 1;
    int i=0;
    ll dcnt = 0;
    ll close = -1e9;
    while(i<m || next_n<=n){
        //cerr << i << " " << next_n << " : " << close << "\n";
        // advance employ
        if(next_n<=n && close >= a*next_n){
            next_n = close/a+1;
            continue;
        }
        //advance client
        if(i<m && close>=t[i]){
            ++i;
            continue;
        }
        ++dcnt;
        // next event
        if(next_n>n){
            close = t[i]+d;
        } else if(i>=m || next_n*a<t[i]){
            // speed up
            ll simult = d / a+1;
            ll docnt = 300/simult + 1;
            ll incn  = simult*docnt;
            ll cbound = (next_n + incn+1)*a;
            if(next_n + incn <= n){
                if(i>=m || t[i]>cbound){
                    dcnt+=docnt;
                    next_n+=incn;
                }
            }

            close = next_n*a + d;
        } else {
            close = t[i]+d;
        }
    }
    //cerr << i << " " << next_n << " : " << close << "\n";
    cout << dcnt << "\n";

    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}