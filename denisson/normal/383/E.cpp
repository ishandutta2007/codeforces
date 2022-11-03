#include <bits/stdc++.h>
        
using namespace std;
        
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
int dp[1 << 24];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
    	string s;
    	cin >> s;
    	set<int> se;
    	se.insert(s[0] - 'a');
    	se.insert(s[1] - 'a');
    	se.insert(s[2] - 'a');
    	vector<int> t;
    	for (int x : se) t.pb(x);
    	for (int mask = 1; mask < (1 << t.size()); mask++){
    		int pos = 0;
    		int cnt = 0;
    		for (int i = 0; i < t.size(); i++) if ((mask >> i) & 1){
    			cnt++;
    			pos ^= 1 << t[i];
    		}
    		if (cnt % 2 == 1) dp[pos]++;
    		else dp[pos]--;
    	}
    }

    int ans = 0;

    for (int i = 0; i < 24; i++){
    	for (int mask = 0; mask < (1 << 24); mask++) if (!((mask >> i) & 1)) dp[mask ^ (1 << i)] += dp[mask];
    }

    for (int mask = 0; mask < (1 << 24); mask++) ans ^= dp[mask] * dp[mask];
    cout << ans;
}