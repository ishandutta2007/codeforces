#include<iostream>
#include<vector>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> d(n + 1);
    for(int i = 1; i <= n; i++) cin >> d[i];
    int now = d[1];
    vector<int> an{now};
    for(int i = 2; i <= n; i++) {
        an.push_back(now + d[i]);
        if(!d[i]) continue;
        if(now >= d[i]) {
            cout << "-1\n";
            return;
        }
        now += d[i];
        
    }
    for(int i = 0; i + 1 < (int)an.size(); i++) cout << an[i] << ' ';
    cout << an.back() << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}