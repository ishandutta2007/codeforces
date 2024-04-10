#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second

int p, q, ans = 0, numprimes = 0, numpals;

vi primes;

int to_int(string myString) {
	return atoi(myString.c_str());
}

void genprimes() {
	primes.pb(2);
	for (int i = 3; i < 2000000; ++i) {
		int flag = 0;
		for (int j = 0; j < primes.size(); ++j) {
			if (i % primes[j] == 0) {
				flag = 1;
				break;
			}
			if (primes[j] > sqrt(i)) break;
		}
		if (flag == 0) primes.pb(i);
	}
}

int find_palindromes(int y) {
	int num = 0;
	string z = to_string(y);
	FOR(i,1,z.length()) {
		if (i % 2 == 0) num += 9*pow(10,i/2-1);
		else num += 9*pow(10,(i-1)/2);
	}
	
	if (z.length() % 2 == 0) {
		string x = z.substr(0,z.length()/2);
		reverse(x.begin(),x.end());
		if (x > z.substr(z.length()/2,z.length()/2)) {
			reverse(x.begin(),x.end());
			x[0] -= 1;
			num += (to_int(x));
		} else {
			reverse(x.begin(),x.end());
			x[0] -= 1;
			num += to_int(x)+1;
		}
	} else {
		string x = z.substr(0,(z.length()-1)/2);
		reverse(x.begin(),x.end());
		string asdf = z.substr(0,(z.length()+1)/2);
		asdf[0] -= 1;
		if (x > z.substr((z.length()+1)/2,(z.length()-1)/2)) {
			num += (to_int(asdf));
		} else num += to_int(asdf)+1;
	}
	return num;
}

int comp() {
	if (numprimes*q <= numpals*p) return true;
	return false;
}

int main() {
	cin >> p >> q;
	genprimes();
	
	F0R(i, primes.size()) {
		int x = primes[i]-1;
		numprimes = i;
		numpals = find_palindromes(x);
		if (comp()) {
			ans = x;
		}
	}
	cout << ans;
	return 0;
}