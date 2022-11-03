#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double
#define sz(a) (int)a.size()

int n, l, r;
int a[10001];
int b[10001];

bool cmp(int w1, int w2){
	if (b[w1] == b[w2]){	
		return a[w1] > a[w2];
	} else return b[w1] < b[w2];
}

int dp[10001];

int main(){
//	freopen("input.txt", "r", stdin);
	//freopen("output1.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> l >> r;
	int s = 0;
	for (int i = 0; i < n; i++) cin >> a[i], s += a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	vector<int> t;
	for (int i = 0; i < n; i++) t.pb(i);
	sort(all(t), cmp);
	for (int i = 0; i < 10001; i++) dp[i] = -1;
	dp[s] = 0;
	int ans = 0;
	for (int i = 0; i < t.size(); i++){
		//cout << t[i] << endl;
		for (int j = 0; j <= 10000; j++){
			if (j + a[t[i]] <= 10000 && dp[j + a[t[i]]] != -1){
				int ww = 0;
				if (b[t[i]]){
					if (j >= l && j <= r) ww = 1;
				}
				dp[j] = max(dp[j], dp[j + a[t[i]]] + ww);
			}
		}
		for (int j = 0; j < 10000; j++) ans = max(ans, dp[j]);
	}
	cout << ans;
}