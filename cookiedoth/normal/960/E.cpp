/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

class modulo_field_element {

private:

	ll value;

	const static ll mod = 1e9 + 7;

	ll power(ll x, ll deg) {
		if (deg == 0)
			return 1;
		if ((deg & 1) == 0) {
			ll half = power(x, deg >> 1);
			return (half * half) % mod;
		}
		else {
			ll peace = power(x, deg - 1);
			return (peace * x) % mod;
		}
	}

	ll power(ll x) {
		return power(x, mod - 2);
	}

public:

	modulo_field_element(ll _value): value((_value % mod + mod) % mod) {}
	modulo_field_element(int _value): value(((ll)_value % mod + mod) % mod) {}
	modulo_field_element(): value(0) {}

	modulo_field_element inv () {
		return modulo_field_element(power(value));
	}

	modulo_field_element operator + (const modulo_field_element &a) {
		return (this->value + a.value) % mod;
	}

	modulo_field_element operator * (const modulo_field_element &a) {
		return (this->value * a.value) % mod;
	}

	modulo_field_element operator - (const modulo_field_element &a) {
		return (this->value - a.value + mod) % mod;
	}

	modulo_field_element operator / (const modulo_field_element &a) {
		return (*this) * ((modulo_field_element)power(a.value));
	}

	modulo_field_element operator += (const modulo_field_element &a) {
		return *this = *this + a;
		//this->value = (this->value + a.value) % mod;
	}

	modulo_field_element operator -= (const modulo_field_element &a) {
		return *this = *this - a;
		//this->value = (this->value - a.value + mod) % mod;
	}

	modulo_field_element operator *= (const modulo_field_element &a) {
		return *this = *this * a;
		//this->value = (this->value * a.value) % mod;
	}

	modulo_field_element operator /= (const modulo_field_element &a) {
		return *this = *this / a;
		//value = (value * power(a->value)) % mod;
	}

	modulo_field_element operator ++ (int) {
		return (this->value + 1) % mod;
	}

	modulo_field_element operator ++ () {
		return (this->value + 1) % mod;
	}

	modulo_field_element operator -- (int) {
		return (this->value - 1 + mod) % mod;
	}

	modulo_field_element operator -- () {
		return (this->value - 1 + mod) % mod;
	}

	modulo_field_element operator + () {
		return (*this);
	}

	modulo_field_element operator - () {
		return ((mod - this->value) % mod);
	}

	operator int() const {
		return (int)value;
	}

	operator ll() const {
		return (ll)value;
	}

};

ostream& operator << (ostream &s, const modulo_field_element& a) {
	return s << (ll)a;
}

istream& operator >> (istream &s, modulo_field_element &a) {
	ll val;
	s >> val;
	a = modulo_field_element(val);
	return s;
}

const int mx = 2e5 + 228;
int n;
vector<int> g[mx], children[mx];
modulo_field_element ans, a[mx], even[mx], odd[mx], f_even[mx], f_odd[mx], t_even[mx], t_odd[mx];

void hang(int v, int pv) {
	if (v != 0)
		children[pv].push_back(v);
	for (auto v1 : g[v]) {
		if (v1 != pv)
			hang(v1, v);
	}
}

void dfs(int v) {
	for (auto v1 : children[v]) {
		dfs(v1);
	}
	even[v] += 1;
	f_even[v] += a[v];
	t_even[v] += a[v];
	modulo_field_element sum_even = 0, sum_odd = 0, sum_f_even = 0, sum_f_odd = 0, sum_t_even = 0, sum_t_odd = 0;
	for (auto v1 : children[v]) {
		even[v] += odd[v1];
		f_even[v] += (f_odd[v1] + odd[v1] * a[v]);
		t_even[v] += (-t_odd[v1] + odd[v1] * a[v]);
		odd[v] += even[v1];
		f_odd[v] += (f_even[v1] - even[v1] * a[v]);
		t_odd[v] += (-t_even[v1] + even[v1] * a[v]);
		sum_even += even[v1];
		sum_odd += odd[v1];
		sum_f_even += f_even[v1];
		sum_f_odd += f_odd[v1];
		sum_t_even += t_even[v1];
		sum_t_odd += t_odd[v1];
	}
	for (auto v1 : children[v]) {
		modulo_field_element rem_odd = sum_odd - odd[v1];
		modulo_field_element rem_even = sum_even - even[v1];
		modulo_field_element rem_f_odd = sum_f_odd - f_odd[v1];
		modulo_field_element rem_f_even = sum_f_even - f_even[v1];
		modulo_field_element rem_t_odd = sum_t_odd - t_odd[v1];
		modulo_field_element rem_t_even = sum_t_even - t_even[v1];
		modulo_field_element c1 = f_even[v1] * rem_even + rem_t_even * even[v1] - rem_even * even[v1] * a[v];
		modulo_field_element c2 = f_even[v1] * rem_odd + rem_t_odd * even[v1] - rem_odd * even[v1] * a[v];
		modulo_field_element c3 = f_odd[v1] * rem_even - rem_t_even * odd[v1] + rem_even * odd[v1] * a[v];
		modulo_field_element c4 = f_odd[v1] * rem_odd - rem_t_odd * odd[v1] + rem_odd * odd[v1] * a[v];
		ans += (c1 + c2 + c3 + c4);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	hang(0, 0);
	dfs(0);
	for (int i = 0; i < n; ++i) {
		ans += (f_odd[i] + f_even[i] + t_odd[i] + t_even[i]);
		ans -= a[i];
	}
	/*cout << "f" << endl;
	for (int i = 0; i < n; ++i) {
		cout << f_even[i] << " " << f_odd[i] << endl;
	}
	cout << "t" << endl;
	for (int i = 0; i < n; ++i) {
		cout << t_even[i] << " " << t_odd[i] << endl;
	}*/
	cout << ans << endl;
}