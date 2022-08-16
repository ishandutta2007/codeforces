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

    int n;
    cin >> n;
    vector<int> v(n), mi;
    for(auto &e:v){
        cin >> e;
    }
    mi = v;
    mi.push_back(0);
    for(int i=n-2;i>=0;--i){
        xmax(mi[i], mi[i+1]-1);
    }
    ll ans = 0;
    int cur_marks = 0;
    for(int i=0;i<n;++i){
        //cerr << v[i] << " " << cur_marks << " " << mi[i] << "\n";
        ans+=cur_marks-v[i];
        if(cur_marks< mi[i+1]){
            ++cur_marks;
        }
    }
    cout << ans << "\n";



    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}