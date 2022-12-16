#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<int> t(N);
    for(auto& x : t) cin >> x;
    sort(t.begin(), t.end());
    for(int i=0;i<t.size();++i) {
        for(int j=i+1;j<t.size();++j) {
            for(int k=j+1;k<t.size();++k) {
        if(t[i] != t[j] && t[j] != t[k] && t[k]-t[i] == 2) {
            cout << "YES" << endl;
            return 0;
        } }}
    }
    cout << "NO" << endl;
    return 0;
}