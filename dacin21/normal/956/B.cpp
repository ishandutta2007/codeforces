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
    cout << fixed << setprecision(15);

    int n, u;
    cin >> n >> u;
    vector<int> v(n);
    for(auto &e:v){
        cin >> e;
    }

    long double l=0.0, r = 1.0;
    for(int it=0;it<50;++it){
        long double m = l + (r-l)/2;
        deque<pair<long double, int> > q;

        bool did = false;

        for(int i=1;i<n;++i){
            while(!q.empty() && v[i]-v[q.front().second]>u){
                q.pop_front();
            }
            if(!q.empty()){
                if(v[i] * (1-m) >= q.front().first){
                    did = true;
                    break;
                }
            }
            long double add_val = v[i] - m*v[i-1];
            while(!q.empty() && q.back().first >= add_val){
                q.pop_back();
            }
            q.emplace_back(add_val, i-1);
        }
        if(did){
            l = m;
        } else {
            r = m;
        }
    }
    //cerr << " => " << r << "\n";
    if(l*u <= 0.1){
        cout << "-1\n";
    } else {
        cout << l << "\n";
    }



    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}