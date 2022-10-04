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

ll mod;

class modulo_field_element {

private:

	ll value;

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

const int mx = 1e5 + 228;
int n, p, best;
modulo_field_element a[mx], sum, pref_sum;

int main() {
	cin >> n >> p;
	mod = p;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	modulo_field_element cur = 0;
	for (int i = 0; i < n - 1; ++i) {
		cur += a[i];
		modulo_field_element other = sum - cur;
		best = max(best, (int)cur + (int)other);
	}
	cout << best << endl;
}