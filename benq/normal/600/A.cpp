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
 
const int MOD = 1000000007;
const int MAX = 10000005;

string a,b;

int test(string x) {
	if (x.length() == 0) return false;
	if (x[0] == '0' && x.length()>1) return false;
	F0R(i,x.length()) if (!('0' <= x[i] && x[i] <= '9')) return false;
	return true;
}

int main() {
	string s;
	cin >> s;
	s += ',';
	int count1 = -1, k = int(s.length());
	
	while (count1 < k-1) {
		count1 ++;
		string x = "";
		while (s[count1] != ',' && s[count1] != ';' && count1 < k) {
			x += s[count1];
			count1 ++;
		}
		if (test(x)) {a += x; a += ',';}
		else {b += x; b += ',';}
	}
	
	if (a.length() == 0) cout << "-" << endl;
	else cout << "\"" << a.substr(0,int(a.length())-1) << "\"" << endl;
	if (b.length() == 0) cout << "-" << endl;
	else cout << "\"" << b.substr(0,int(b.length())-1) << "\"";
}