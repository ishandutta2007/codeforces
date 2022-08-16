#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll inf = 1e18;
int main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTTT; cin >> TTTT;
    while(TTTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > o;
    vector<int> c(k);
    int d=2;
    iota(c.begin(), c.end(), 0);
    int l = k;
    while(l<n-1){
        int i = l%k;
        o.emplace_back(c[i], l);
        c[i] = l;
        if(i==0 || i==1) ++d;
        ++l;
    }
    for(int e:c){
        o.emplace_back(e, n-1);
    }

    cout << d << "\n";
    for(auto const&e:o){
        cout << e.first+1 << " " << e.second+1 << "\n";
    }




    #ifdef LOCAL_RUN
    cout << endl;
    }
    #endif // LOCAL_RUN
    return 0;
}