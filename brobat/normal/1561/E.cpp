#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007



void solve() {
    int n;
    cin >> n;
    vector <pair<int, int>> arr(n);
    vector <int> v(n); 
    vector <int> pos(n);
    vector <int> ans;
    forn(i, 0, n) {
        cin >> arr[i].first;
        v[i] = arr[i].first;
        arr[i].second = i + 1;
    }
    // Check for even-odd positions first.
    sort(arr.begin(), arr.end());
    forn(i, 0, n) {
        if(i%2 == arr[i].second%2) {
            cout << -1 << endl;
            return;
        }
    }
    forn(i, 0, n) pos[i] = arr[i].first;
    // arr --> The array we are sorting
    // pos --> Just useful to know the value of the two elements we need to sort in current iterations.
    // number of iterations = (n-1)/2
    for(int i = n-1; i > 0; i-=2) {
        // Sort the ith and (i-1)th elements.
        int x = find(v.begin(), v.end(), pos[i]) - v.begin();
        ans.push_back(x+1);
        reverse(v.begin(), v.begin() + x + 1);
        int y = find(v.begin(), v.end(), pos[i-1]) - v.begin();
        ans.push_back(y);
        reverse(v.begin(), v.begin() + y);
        // Now biggest element is at position y - 1.
        ans.push_back(y+2);
        reverse(v.begin(), v.begin() + y + 2);
        // Now biggest at index 2, second biggest at index 1
        ans.push_back(3);
        reverse(v.begin(), v.begin() + 3);
        // Now biggest at 0, second biggest at 1.
        ans.push_back(i+1);
        reverse(v.begin(), v.begin() + i + 1);
    }
    cout << ans.size() << endl;
    for(auto i : ans) cout << i << " ";
    cout << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}