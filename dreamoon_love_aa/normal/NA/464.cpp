#include<iostream>
#include<algorithm>
#include<vector>
#define SZ(X) ((int)(X).size())
using namespace std;
const int SIZE = 1<<20;
int a[SIZE];
int n;
void solve() {
    vector<pair<int, int>> AA;
    for(int i = 0; i < n; i++) {
        AA.push_back(make_pair(a[i], i + 1));
    }
    sort(AA.begin(), AA.end());
    int an = 0;
    for(int i = 0; i < SZ(AA); i++) {
        for(int j = i + 1; j < SZ(AA); j++) {
            if((long long)AA[i].first * AA[j].first > 2 * n) {
                break;
            }
            if(AA[i].first * AA[j].first == AA[i].second + AA[j].second) {
                an++;
            }
        }
    }
    cout << an << '\n';
}
void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        input();
        solve();
    }
    return 0;
}