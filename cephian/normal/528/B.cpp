#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;

int n;
const int N = 200005;
vector<pii> v;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x,w;
        cin >> x >> w;
        v.push_back(pii(x+w,x-w));
    }
    sort(v.begin(),v.end());
    int last = -2000000000;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(v[i].second < last) continue;
        last = v[i].first;
        ++ans;
    }
    cout << ans << "\n";
    return 0;
}