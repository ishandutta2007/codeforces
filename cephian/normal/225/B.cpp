#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

queue<ll> pv;
vector<ll> v;
vector<ll> ans;
int s, k;

int main() {
    cin >> s >> k;
    v.push_back(1);
    pv.push(1);
    pv.push(1);
    
    ll sm = 2;
    while(sm <= s) {
        pv.push(sm);
        v.push_back(sm);
        sm *= 2;
        if(pv.size() > k) {
            sm -= pv.front();
            pv.pop();
        }
    }
    for(int i = v.size()-1; i >=0; --i) {
        if(v[i] < s) {
            ans.push_back(v[i]);
            s -= v[i];
        } else if(v[i] == s) {
            ans.push_back(v[i]);
            break;
        }
    }
    while(ans.size() < 2)
        ans.push_back(0);
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if(i == ans.size()-1) cout << "\n";
        else cout << " ";
    }
    return 0;
}