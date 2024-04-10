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
int a[300007];
ll dp[300007];
int to[300007];

vector<int> ans;

void calc(int l, int r){
	int now = a[l + 1];
	for (int i = l + 1; i <= r - 1; i++){
		int nxt = a[i + 1];
		if (now > 0 && nxt > 0){
			ans.pb(i);
			int mi = min(now, nxt);
			now -= mi;
			nxt -= mi;
		}
		if (now > 0) ans.pb(i - 1);
		now = nxt;
	}
}

int main(){
   //	freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = n - 1; i >= 0; i--){
    	ll val = 0;
    	dp[i] = (ll)1e18 + 7;
    	int now = a[i + 1];
    	for (int j = i + 2; j <= n + 1; j++){
    		if (j - i > 3) break;
    		if (dp[j] + val + now < dp[i]){
    			dp[i] = dp[j] + val + now;
    			to[i] = j;
    		}
    		val += now;
    		now = a[j] - min(a[j], now);
    	}
    }

    int pos = 0;
    if (dp[1] < dp[0]) pos = 1;

    while(1){
    	if (pos >= n) break;
    	calc(pos, to[pos]);
    	pos = to[pos];
    }

    cout << ans.size() << "\n";
    for (int x : ans) cout << x << ' ';
}