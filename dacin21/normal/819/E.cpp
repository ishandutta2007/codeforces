#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
    #ifdef LOCAL_RUN
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    #endif // LOCAL_RUN
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    if(n==2){
        cout << -1;
        return 0;
    }
    vector<vector<int> > o;
    while(n>1 && n!=4){
        o.push_back({n, n-1, 1});
        o.push_back({n, n-1, n-2});
        for(int i=1;i<n-2;++i){
            o.push_back({n, i, n-1, i+1});
        }
        n-=2;
    }
    if(n==4){
        o.push_back({1, 2, 3, 4});
        o.push_back({1, 2, 4, 3});
        o.push_back({1, 3, 2, 4});
    }
    cout << o.size() << "\n";
    for(auto const&e:o){
        cout << e.size();
        for(auto const&f:e) cout  << " " << f;
        cout << "\n";
    }


    return 0;
}