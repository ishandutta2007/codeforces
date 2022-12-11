#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    VI v(n);
    int ans = 0;
    for (int i = 0; i < n; ++i){
        cin >> v[i];
        if (i >= 1 and v[i] == v[i-1]) cnt = 0;
        ++cnt;
        ans = max(ans, cnt);
    }
    cout << ans <<endl;
}