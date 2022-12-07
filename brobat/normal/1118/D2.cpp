#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

int n, m;
vector<int> v;

bool check(int k) {
    // Check if we can do the task in k days in O(n) time.
    int temp_ans = 0;
    int x = 0;
    for(auto i : v) {
        temp_ans += max(0ll, i - (x/k));
        x++;
    }
    if(temp_ans >= m) return true;
    return false;
}

int search() {
    int left = 1;
    int right = n;
    int ans = 0;
    while(left<=right) {
        int mid = (left + right)/2;
        if(!check(mid)) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }
    return ans + 1;
}

void solve() {
    cin >> n >> m;
    forn(i, 0, n) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), greater<int>());
    int z = search();
    if(z>n) cout << -1;
    else cout << z;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t; cin >> t; while(t--)
    {solve();}
    return 0;
}