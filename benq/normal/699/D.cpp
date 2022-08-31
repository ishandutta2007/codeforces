#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define INF 9999;

const int MOD = 1000000007;
double PI = 4*atan(1);

int n, a[200001], comp[200001];
vi change[2];

int main() {
    // calculate # of cycles
	ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    FOR(i,1,n+1) cin >> a[i];
    int cur = 0;
    FOR(i,1,n+1) {
        if (!comp[i]) {
            int j = i;
            cur ++;
            while (!comp[j]) {
                comp[j] = cur;
                j = a[j];
            }
            if (comp[j] == cur) {
                if (j == a[j]) change[0].pb(j);
                else change[1].pb(j);
            }
        }
    }
    int ans = 0;
    if (change[0].size()) {
        for (int i: change[0]) if (i != change[0][0]) {
            a[i] = change[0][0];
            ans++;
        }
        for (int i: change[1]) {
            a[i] = change[0][0];
            ans++;
        }
    } else {
        a[change[1][0]] = change[1][0], ans++;
        for (int i: change[1]) if (i != change[1][0]) {
            a[i] = change[1][0];
            ans++;
        }
    }
    cout << ans << endl;
    FOR(i,1,n+1) cout << a[i] << " ";
}