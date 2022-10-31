#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

const int N = 200005;
const int A = 500005;
int a[N]={0};
int amt[A]={0};
int n,q;
bool here[N]={0};
ll sm = 0;

int fact[A];

void gf() {
	for(int i = 1; i < A; ++i)
		fact[i] = i;
	for(int i = 2; i < A; ++i) {
		if(fact[i] == i) {
			for(ll j = ll(i)*i; j < A; j += i)
				fact[j] = i;
		}
	}
}

void getp(set<int>& s, int b) {
	if(b == 1) return;
	getp(s, b/fact[b]);
	s.insert(fact[b]);
}

vector<int> getp(int b) {
	vector<int> p;
	set<int> s;
	getp(s,b);
	while(!s.empty()) {
		p.push_back(*s.begin());
		s.erase(s.begin());
	}
	return p;
}

int bc(int m) {
	int ans = 0;
	while(m) {
		ans += m&1;
		m /= 2;
	}
	return ans;
}

int gcd1(int m) {
	int ans = 0;
	vector<int> p = getp(a[m]);
	for(int i = (1<<p.size())-1; i >= 0; --i) {
		int d = 1;
		for(int j = 0; j < p.size(); ++j)
			if((i&(1<<j)) != 0)
				d *= p[j];
		if(bc(i)&1) {
			ans -= amt[d];
		} else {
			ans += amt[d];
		}
	}
	return ans;
}

void adjust(int m, int pr) {
	vector<int> p = getp(a[m]);
	for(int i = (1<<p.size())-1; i >= 0; --i) {
		int d = 1;
		for(int j = 0; j < p.size(); ++j)
			if((i&(1<<j)) != 0)
				d *= p[j];
		amt[d] += pr;
	}
}

int main() {
	ios::sync_with_stdio(0);
	gf();
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	while(q--) {
		int x;
		cin >> x;
		if(here[x]) {
			here[x] = false;
			adjust(x,-1);
			sm -= gcd1(x);
		} else {
			here[x] = true;
			sm += gcd1(x);
			adjust(x,1);
		}
		cout << sm << "\n";
	}
	return 0;
}