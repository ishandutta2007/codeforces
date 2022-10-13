#include <bits/stdc++.h>

using namespace std;

#define int long long

const int kMaxN = 100005;

long long Xor[kMaxN];
vector<pair<int, long long>> G[kMaxN];
int D[kMaxN], Viz[kMaxN];

vector<long long> Values;
vector<long long> Xors;

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
};
using namespace ModOps;

void DFS(int node) {
	Viz[node] = 1;
	Xors.push_back(Xor[node]);

	for(auto e : G[node]) {
		int vec = e.first;
		long long val = e.second;

		if(!Viz[vec]) {
			Xor[vec] = Xor[node] ^ val;
			D[vec] = D[node] + 1;
			DFS(vec);
		} else if(D[vec] < D[node] - 1) {
			Values.push_back(Xor[node] ^ Xor[vec] ^ val);
		}
	}
}

long long reunion;
vector<long long> Gauss() {
	int now = 0;
	for(int bit = 0; bit < 62; ++bit) {
		for(int i = now; i < Values.size(); ++i) {
			if(Values[i] & (1LL << bit)) {
				swap(Values[i], Values[now]);
				break;
			}
		}

		if(now == Values.size()) 
			continue;

		if(Values[now] & (1LL << bit)) {
			for(int i = now + 1; i < Values.size(); ++i) {
				if(Values[i] & (1LL << bit))
					Values[i] ^= Values[now];
			}
			++now;
		}
	}
	return vector<long long>(Values.begin(), Values.begin() + now);
}

int SolveFor(int i) {
	Values.clear();
	Xors.clear();
	DFS(i);
	auto Base = Gauss();

	int dim = Base.size();
	assert(dim <= 62);
	int reunion = 0;
	for(auto x : Base) reunion |= x;

	// cerr << "dim" << dim << '\n';

	int ret = 0, pw = 1;
	for(int bit = 0; bit < 62; ++bit) {
		long long count_no, count_yes;

		if(reunion & (1LL << bit)) {
			count_no = count_yes = (1LL << (dim - 1));
		} else {
			count_no = (1LL << dim);
			count_yes = 0;
		}

		int a = 0, b = 0;
		for(auto v : Xors) {
			if(v & (1LL << bit))
				a += 1;
			else b += 1;
		}

		int coef_1 = count_no % kMod;
		coef_1 = mul(coef_1, a);
		coef_1 = mul(coef_1, b);

		int coef_2 = count_yes % kMod;
		coef_2 = mul(coef_2, 
					add(a * (a - 1) / 2 % kMod,
					b * (b - 1) / 2 % kMod));

		int total = add(coef_1, coef_2);


		ret = add(ret, mul(total, pw));
		pw = add(pw, pw);
	}
	return ret;
}

int32_t main() {
	int n, m;
	cin >> n >> m;
	while(m--) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		G[a].emplace_back(b, c);
		G[b].emplace_back(a, c);
	}

	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(!Viz[i]) {
			// cerr << i << " ";
			ans = add(ans, SolveFor(i));
		}
	}
	cout << ans << endl;

	return 0;
}