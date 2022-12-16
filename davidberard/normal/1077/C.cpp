#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N;
    ll sm = 0;
    cin >> N;
    vector<int> v(N);
    map<int, int> mp;
    for(auto& x : v) {
        cin >> x;
        sm += x;
        mp[x]++;
    }
    vector<int> ans;
    for(int i=0;i<N;++i)
    {
        if(sm-v[i] <= 2e6 && (sm-v[i])%2 == 0)
        {
            int amt = (sm-v[i])/2;
            if(mp[amt] - (v[i] == amt) > 0)
            {
                ans.push_back(i+1);
            }
        }
    }
    cout << ans.size() << endl;
    for(auto& x : ans) cout << x << " ";
    cout << endl;
    return 0;
}