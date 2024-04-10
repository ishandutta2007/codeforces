// David Berard
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int PMAX = 10100;

/*
ll is_square(ll num) {
	if(num == 0 || n == 1) return true;
	if(num < 0) return false;
	ll b = 1, h = 110000000;
	while(b+1<h) {
		ll mid = (b+h)/2;
		if(mid*mid < num) {
			b = mid;
		} else {
			h = mid;
		}
	}
	if(b*b == num) return true;
	if((b+1)*(b+1) == num) return true;
	//if((b+2)*(b+2) == num) return true;
	return false;
}
*/

vector<bool> is_prime(PMAX, true);
vector<int> primes;

void init() {
	is_prime[0] = false;
	is_prime[1] = false;
	for(int i=2;i<PMAX;++i) {
		if(is_prime[i]) {
			primes.push_back(i);
			for(int j = i*i;j<PMAX;j+=i) {
				is_prime[j] = false;
			}
		}
	}
}

struct num {
	int val;
	int rem;
	int gnum;
	num() {}
	num(int x) { assign(x); }
	void assign(int x) {
		int sgn = 1;
		if(x < 0) {
			sgn = -1;
			x = -x;
		}
		val = x;
		rem = x;
		if(val == 0) {
			return;
		}
		vector<int> used_primes;
		used_primes.push_back(1);
		for(int i=0;i<primes.size();++i) {
			while(true)
			{
				int div = rem/primes[i];
				if(div*primes[i] != rem) {
					break;
				}
				rem = div;
				if(used_primes.back() == primes[i]) {
					used_primes.pop_back();
				} else {
					used_primes.push_back(primes[i]);
				}
			}
		}
		if(rem != 1) {
			used_primes.push_back(rem);
		}
		rem = 1;
		for(int vv : used_primes) {
			rem *= vv;
		}
		val *= sgn;
		rem *= sgn;
	}
	bool operator==(const num& o) const {
		return rem == o.rem;
	}
};

namespace std {
	template <>
	struct hash<num> {
		std::size_t operator() (const num& o) const {
			return std::hash<int>{}(o.rem);
		}
	};
};

vector<num> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	init();
	
	int N;
	cin >> N;
	for(int i=0;i<N;++i) {
		int val;
		cin >> val;
		v.push_back(num(val));
	}

	unordered_map<int, int> remmap;
	for(int i=0;i<v.size();++i) {
		remmap[v[i].rem] = -1;
	}
	int tcnt = 0;
	for(auto &it : remmap) {
		it.second = tcnt++;
	}
	for(auto &vv : v) {
		vv.gnum = remmap[vv.rem];
	}

	vector<int> amt(N+1, 0);
	for(int i=0;i<N;++i) {
		vector<bool> used(remmap.size(), false);
		int neg1 = 0, pos1 = 0, zero = 0, nused = 0;
		for(int j=i;j<N;++j) {
			if(v[j].rem == -1) {
				++neg1;
			} else if(v[j].rem == 0) {
				++zero;
			} else if(v[j].rem == 1) {
				++pos1;
			} else {
				if(used[v[j].gnum] == 0) {
					used[v[j].gnum] = 1;
					++ nused;
				}
			}

			int tot = 0;
			/////////////////////////////////////////////////////////
			if(nused == 0 && neg1 == 0 && pos1 == 0 && zero != 0) {
				++tot;
			}
			if(neg1 != 0) {
				++tot;
			}
			if(pos1 != 0) {
				++tot;
			}
			tot += nused;
			++amt[tot];
		}
	}
	for(int i=1;i<=N;++i) {
		cout << amt[i] << " ";
	}
	cout << endl;

	return 0;
}