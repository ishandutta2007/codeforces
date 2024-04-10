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
int a[200007];

int fac[200007];
int invfac[200007];

int mult(int a, int b){
	return a * (ll)b % mod;
}

int sum(int a, int b){
	return (a + (ll)b) % mod;
}

int dec(int a, int b){
	return (a - (ll)b + mod) % mod;
}

int bp(int a, int k){
	if (k == 1) return a;
	if (k % 2 == 1){
		return mult(a, bp(a, k - 1));
	} else {
		int q = bp(a, k / 2);
		return mult(q, q);
	}
}

int cnk(int n, int k){
	if (k > n) return 0;
	return mult(fac[n], mult(invfac[k], invfac[n - k]));
}

int solve(){
	vector<int> t;
	for (int i = 0; i < n; i++) t.pub(a[i]);
	int ss = 1;
	while(1){
		//for (int x : t) cout << x << ' ';
		//cout << endl;
		if (t.size() == 1) return t[0];
		vector<int> d;
		for (int i = 1; i < t.size(); i++){
			if (ss == 1){
				d.pub(sum(t[i], t[i - 1]));
			} else {
				d.pub(dec(t[i - 1], t[i]));
			}
			ss ^= 1;
		}
		t = d;
	}
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    fac[0] = 1;
    for (int i = 1; i < 200007; i++) fac[i] = mult(fac[i - 1], i);
    for (int i = 0; i < 200007; i++) invfac[i] = bp(fac[i], mod - 2);
    cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	//cout << solve() << endl;
	if (n % 2 == 0){
		vector<int> w[2];
		int s[2] = {0, 0};
		for (int i = 0; i < n; i++) w[i % 2].pub(a[i]);
		int ans = 0;
		for (int it = 0; it < 2; it++){
			for (int i = 0; i < w[it].size(); i++) s[it] = sum(s[it], mult(w[it][i], cnk((int)w[it].size() - 1, i)));
		}
		if ((n / 2) % 2 == 1) ans = sum(s[0], s[1]); else ans = dec(s[0], s[1]);
		cout << ans;
	} else {
		if (n % 4 == 1){
			int ans = 0;
			int cc = 0;
			for (int i = 0; i < n; i++){
				if (i % 2 == 0){
					ans = sum(ans, mult(a[i], cnk(n / 2, cc)));
					cc++;
				}
			}
			cout << ans;
		} else {	
			int ans1 = 0, ans2 = 0, ans3 = 0;
			int cc = 0;
			for (int i = 0; i < n - 2; i++){
				if (i % 2 == 0){
					ans1 = sum(ans1, mult(a[i], cnk((n - 2) / 2, cc)));
					cc++;
				}
			}
			cc = 0;
			for (int i = 1; i < n - 1; i++){
				if (i % 2 == 1){
					ans2 = sum(ans2, mult(a[i], cnk((n - 2) / 2, cc)));
					cc++;
				}
			}
			cc = 0;
			for (int i = 2; i < n; i++){
				if (i % 2 == 0){
					ans3 = sum(ans3, mult(a[i], cnk((n - 2) / 2, cc)));
					cc++;
				}
			}
			//cout << ans1 << ' ' << ans2 << ' ' << ans3 << endl;
			cout << sum(ans1, sum(ans2, dec(ans2, ans3)));
		}
	}
}