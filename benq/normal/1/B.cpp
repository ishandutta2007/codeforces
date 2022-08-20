#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

string tolet(int num) {
	num--;
	int clen = 1, cind = 26;
	while (num >= cind) {
		num -= cind;
		cind *= 26;
		clen++;
	}
	string ans;
	F0R(i,clen) {
		ans += char('A'+(num%26));
		num /= 26;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int tonum(string let) {
	int ans = 0;
	FOR(i,1,let.size()) ans += pow(26,i);
	F0R(i,let.size()) {
		ans += pow(26,let.size()-1-i)*int(let[i]-'A');
	}
	ans++;
	return ans;
}

string toBC(string s) {
	string a,b;
	bool f = 0;
	FOR(i,1,s.length()) {
		if (s[i] == 'C') f = 1;
		else {
			if (!f) a += s[i];
			else b += s[i];
		}
	}
	return tolet(stoi(b))+a;
}

string toR(string s) {
	string chars, num;
	for (char i: s) {
		if ('A' <= i && i <= 'Z') chars += i;
		else num += i;
	}
	return 'R'+num+'C'+to_string(tonum(chars));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	F0R(i,n) {
		string s; cin >> s;
		bool f = 0;
		F0R(j,s.length()-1) if ('0' <= s[j] && s[j] <= '9' && s[j+1] == 'C') f = 1;
		if (f) cout << toBC(s) << "\n";
		else cout << toR(s) << "\n";
	}
}