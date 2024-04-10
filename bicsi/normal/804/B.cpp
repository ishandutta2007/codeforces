#include <bits/stdc++.h>

using namespace std;

const int kMod = 1e9 + 7;

namespace ModOps {
	int add(int a, int b) {
		a += b;
		if(a >= kMod) a -= kMod;
		return a;
	}
	int sub(int a, int b) {
		a -= b;
		if(a < 0) a += kMod;
		return a;
	}
	int mul(int a, int b) {
		return 1LL * a * b % kMod;
	}
	int lgpow(int b, int e) {
		int r = 1;
		while(e) {
			if(e % 2) 
				r = mul(r, b);
			b = mul(b, b);
			e /= 2;
		}
		return r;
	}
	int inv(int x) {
		return lgpow(x, kMod - 2);
	}

	vector<int> Fact, IFact;
	bool __processed;

	void ProcessFactorials(int maxx) {
		++maxx;
		Fact.resize(maxx);
		IFact.resize(maxx);

		Fact[0] = IFact[0] = 1;
		for (int i = 1; i <= maxx; ++i)
			Fact[i] = mul(Fact[i - 1], i);

		IFact[maxx] = inv(Fact[maxx]);
		for(int i = maxx - 1; i >= 1; --i)
			IFact[i] = mul(i + 1, IFact[i + 1]);

		__processed = true;
	}

	int GetComb(int n, int k) {
		assert(__processed);
		return mul(mul(Fact[n], IFact[n - k]), IFact[k]);
	}
};
using namespace ModOps;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;

	int n = str.size();

	int cnt = 0, ans = 0;
	for(int i = n - 1; i >= 0; --i) {
		if(str[i] == 'b')
			cnt = add(cnt, 1);
		else {
			ans = add(ans, cnt);
			cnt = add(cnt, cnt);
		}
	}

	cout << ans << endl;
	
	return 0;
}