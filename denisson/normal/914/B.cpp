#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

int n;
int a[100007];
int dp[100007];

int main(){
	//srand(time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output2.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	dp[n - 1] = 1;

	bool was = 0;

	for (int i = n - 2; i >= 0; i--){
		if (!was && a[i] != a[i + 1] && dp[i + 2] == 0) was = 1;
		if (was){
			dp[i] = 1;
			continue;
		}
		if (dp[i + 1] == 0){
			dp[i] = 1;
		}
	}

	if (dp[0])
		cout << "Conan";
	else 
		cout << "Agasa";
}