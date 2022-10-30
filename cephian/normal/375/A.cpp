#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
struct __test {} test;
using namespace std;
template <typename T>const __test &operator<<(const __test& d,
const T& v) {return cerr << "\033[31m" << v << "\033[0m",d;}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int f[1000]={};
string s;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int a[4] = {1,6,8,9};
	int m[7] = {};
	do {
		int b = a[0]*1 + a[1]*10 + a[2]*100 + a[3]*1000;
		m[b%7] = b;
	} while(next_permutation(a,a+4));
	cin >> s;
	for(int i = 0; i < s.size(); ++i) {
		++f[s[i]];
	}
	--f['1'];
	--f['6'];
	--f['8'];
	--f['9'];
	int r = 0;
	for(int i = '9'; i > '0'; --i) {
		while(f[i]--) {
			r = (r*10 + i-'0')%7;
			cout << char(i);
		}
	}
	r = (r * 10000)%7;
	int q = 1;
	for(int i = 0; i < f['0']; ++i) {
		r = (r*10)%7;
		q = (q*10)%7;
	}
	for(int k = 0; k < 7; ++k) {
		if((q*k+r)%7 == 0) {
			cout << m[k];
			break;
		}
	}
	while(f['0']--) {
		cout << '0';
	}
	cout << "\n";
}