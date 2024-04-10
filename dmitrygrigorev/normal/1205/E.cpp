#include <bits/stdc++.h>
#define div suka
#define ll long long
using namespace std;
const int mod = 1000000007;
int Sum(int x, int y){
	if (x+y<0) return x+y+mod;
	if (x+y>=mod) return x+y-mod;
	return x+y;
}
int mult(int x, int y){
	return ((ll) x * (ll) y) % (ll) mod;
}
const int K = 200007;
vector<int> div[K];
int pw(int x, int y){
	if (y == 0) return 1;
	if (y==1) return x%mod;
	if (y % 2 == 0){
		int R = pw(x, y/2);
		return mult(R, R);
	}
	return mult(x, pw(x, y-1));
}
int give(int l, int r, int x){
	int a = (l+x-1)/x;
	int b = r/x;
	if (a > b) return 0;
	return b-a+1;
}
int get(int n, int l, int r){
	int res = r-l+1;
	vector<int> p = div[n];
	int L = p.size();
	for (int mask=1; mask < (1<<L); mask++){
		int x = 1;
		for (int j=0; j < L; j++){
			int ba = (1<<j)&mask;
			if (ba!=0) x *= p[j];
		}
		int number = give(l, r, x);
		int b = __builtin_popcount(mask);
		if (b%2==0) res += number;
		else res -= number;
	}
	return res;
}
signed main() {
	#ifdef LOCAL
		freopen("H_input.txt", "r", stdin);
		//freopen("C_output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
   	int n, k;
   	cin >> n >> k;
   	for (int i=2; i < K; i++){
   		if (div[i].size() >= 1) continue;
   		for (int j=i; j < K; j += i) div[j].push_back(i);
   	}
   	int ans=0;
   	for (int g=1; g < n; g++){
   		int len = (n+g-1)/g;
   		for (int sum=2; sum <= 2*(len-1); sum++){
   			int L, R;
   			if (sum <= len) L = 1;
   			else L = sum-len+1;
   			if (sum >= len) R = len-1;
   			else R = sum-1;
   			int var = get(sum, L, R);
   			int count1 = g - (n%g), g1 = len-1;
   			int count2 = (n%g), g2 = len;
   			if (n%g == 0) swap(count1, count2);
   			int kf = 1;
   			int cmp1, cmp2;
   			if (sum <= g1+1) cmp1=1;
   			else cmp1 = sum-g1;
   			if (sum <= g2+1) cmp2=1;
   			else cmp2 = sum-g2;
   			kf = mult(kf, pw(pw(k, cmp1), count1));
   			kf = mult(kf, pw(pw(k, cmp2), count2));
   			//cout << g << " " << sum << " " << kf << " " << var << endl;
   			ans = Sum(ans, mult(kf, var));
   		}
   	}
   	int R = pw(k, mod-2);
   	ans = mult(ans, pw(R, n));
   	cout << ans;
}