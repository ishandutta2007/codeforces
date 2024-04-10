#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

int sum(int x, int y){
	if (x+y < 0) return x+y+mod;
	if (x+y >= mod) return x+y-mod;
	return x+y;
}

int mult(int x, int y){
	return ((ll) x * y) % (ll) mod;
}

int pw(int x, int y){
	if (y==0) return 1;
	if (y==1) return x%mod;
	if (y%2) return mult(x, pw(x, y-1));
	int t = pw(x, y/2);
	return mult(t,t);
}

vector<int> fact = {1}, rev;

int C(int n, int k){
	if (k < 0 || k > n) return 0;
	return mult(fact[n], mult(rev[k], rev[n-k]));
}



class NTT{
public:
	#define db long double 
	#define ll long long
	const static int mod = 998244353;
	const static int root = 646; // 646^(2^20) == 1 (998244353)
	const static int rev_root = 208611436;
	const static int MAX_SIZE = 1 << 21;

	void add(int &a, int b){
		a += b;
		if (a < 0) a += mod;
		if (a >= mod) a -= mod;
	}

	int sum(int a, int b){
		add(a, b);
		return a;
	}

	int mult(int a, int b){
		return a * (ll)b % mod;
	}

	int bp(int a, int k){
		if (k == 0) return 1;
		if (k & 1){
			return mult(a, bp(a, k - 1));
		} else {
			int q = bp(a, k >> 1);
			return mult(q, q);
		}
	}

	int rev(int a){
		return bp(a, mod - 2);
	}

	int n;
	int a[MAX_SIZE * 2 + 7], b[MAX_SIZE * 2 + 7];

	int getReverse(int a, int k){
		int ans = 0;
		for (int i = 0; i < k; i++) if ((a >> i) & 1) ans ^= (1 << (k - i - 1));
		return ans;
	}

	void ntt(int *a, int type){
		int k = -1;
		for (int i = 0; i < 25; i++) if ((n >> i) & 1){ 
			k = i;
			break;
		}
		for (int i = 0; i < n; i++){
			int j = getReverse(i, k);
			if (i < j) swap(a[i], a[j]);
		}
		for (int len = 2; len <= n; len *= 2){
			int w = bp(root, (1 << 20) / len);
			if (type == -1) w = bp(rev_root, (1 << 20) / len);
			for (int i = 0; i < n; i += len){
				int g = 1;
				for (int j = 0; j < len / 2; j++){
					int x = a[i + j];
					int y = mult(a[i + j + len / 2], g);
					a[i + j] = sum(x, y);
					a[i + j + len / 2] = sum(x, mod - y);
					g = mult(g, w);
				}
			}
		}
		if (type == -1){ 
			int rev_n = rev(n);
			for (int i = 0; i < n; i++) a[i] = mult(a[i], rev_n);
		}
	}

	vector<int> mult(vector<int> &w1, vector<int> &w2){
		n = 1;
		while(n < w1.size() + w2.size()) n *= 2;
		for (int i = 0; i < w1.size(); i++){
			a[i] = w1[i];
			a[i] %= mod;
			if (a[i] < 0) a[i] += mod;
		}
		for (int i = 0; i < w2.size(); i++){
			b[i] = w2[i];
			b[i] %= mod;
			if (b[i] < 0) b[i] += mod;
		}
		for (int i = w1.size(); i < n; i++) a[i] = 0;
		for (int i = w2.size(); i < n; i++) b[i] = 0;
		ntt(a, 1);
		ntt(b, 1);
		for (int i = 0; i < n; i++) a[i] = mult(a[i], b[i]);
		ntt(a, -1);
		vector<int> ans(n);
		for (int i = 0; i < n; i++) ans[i] = a[i];
		while(ans.size() && ans.back() == 0) ans.pop_back();
		return ans;
	}
};

NTT kek;

const int CHECK = 2407;
const int N = CHECK*2;

int ways[N][CHECK];

int tays[N][CHECK];


int main(){
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("N_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i=1; i <= 10000; ++i) fact.push_back(mult(fact.back(), i));
	for (int i=0; i < fact.size(); ++i) rev.push_back(pw(fact[i], mod-2));


	int h, w;
	cin >> h >> w;
	vector<bool> a(h, true), b(w, true);
	int n;
	cin >> n;
	for (int i=0;i<n;++i){
		int e, f, c, d;
		cin >> e >> f >> c >> d;
		e--, f--, c--, d--;
		for (int j=e; j <= c; ++j) a[j] = false;
		for (int j=f; j <= d; ++j) b[j] = false;
	}

	ways[0][0] = 1;
	for (int i=0; i < h; ++i){
		for (int j=0; j < CHECK-1; ++j){
			ways[i+1][j] = sum(ways[i+1][j], ways[i][j]);
			if (i > 0 && a[i] && a[i-1] && j > 0) ways[i+1][j] = sum(ways[i+1][j], ways[i-1][j-1]);
		}
	}

	tays[0][0] = 1;

	for (int i=0; i < w; ++i){
		for (int j=0; j < CHECK-1; ++j){
			tays[i+1][j] = sum(tays[i+1][j], tays[i][j]);
			if (i > 0 && b[i] && b[i-1]) tays[i+1][j] = sum(tays[i+1][j], tays[i-1][j-1]);
		}
	}

	int ans = 0;

	int tota=0, totb=0;
	for (int i=0; i < h; ++i) tota += a[i];
	for (int i=0; i < w; ++i) totb += b[i];

	//cout << ways[h][1] << endl;

	for (int str=0; str <= tota; str++) for (int T=0; 2*T + str <= tota;++T){
		if (T+2*str > totb) continue;
		int kek = mult(ways[h][T], C(tota-2*T, str));
		kek = mult(kek, tays[w][str]);
		kek = mult(kek, C(totb-2*str, T));
		kek = mult(kek, fact[str]);
		kek = mult(kek, fact[T]);
		ans = sum(ans, kek);
	}
	cout << ans;






}