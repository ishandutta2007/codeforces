#include <bits/stdc++.h>
					
using namespace std;
			
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double
 
const int mod = (int)1e9 + 7;

int n;
int a[300007];

void add(int &a, int b){
	a += b;
	if (a >= mod) a -= mod;
}

int mult(int a, int b){
	return a * (ll)b % mod;
}

int main(){
//	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int ans = 0;
	int sum = 0;
	int step = 1;
	for (int i = 1; i < n; i++){
		int val = a[i] - a[i - 1];
		int gg = step - 1;
		if (gg < 0) gg += mod;
		add(sum, mult(val, gg));
		sum = mult(sum, 2);
		add(sum, val);
		add(ans, sum);
	//	cout << ans << ' ' << sum << endl;
		step = mult(step, 2);
	}	
	cout << ans;
}