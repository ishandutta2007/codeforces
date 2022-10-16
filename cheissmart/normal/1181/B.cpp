#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;
int a[100005], b[100005], c[100005];

string smin(string a, string b) {
	if(a.size() < b.size()) return a;
	if(a.size() > b.size()) return b;
	for(int i=0;i<a.size();i++)
		if(a[i] < b[i])
			return a;
		else if(a[i] > b[i])
			return b;
	return a;
}

string add(string s, string t) {
	string r;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	memset(c, 0, sizeof c);
	for(int i=0;i<s.size();i++)
		a[i] = s[i]-'0';
	for(int i=0;i<t.size();i++)
		b[i] = t[i]-'0';
	int n = max(s.size(), t.size());
	for(int i=0;i<n;i++) {
		c[i] += a[i] + b[i];
		c[i+1] += c[i]/10;
		c[i] %= 10;
	}
	for(int i=0;i<n+1;i++)
		r.PB('0'+c[i]);
	while(r.back() == '0') r.pop_back();
	reverse(r.begin(), r.end());
	return r;
}

int main()
{
	IO_OP;
	
	int n;
	string s, t;
	vi v;
	cin >> n >> s;
	int i = n / 2;
	while(i>=0 && s[i] == '0') i--;
	if(i >= 0)
		v.PB(i);
	if(i >= 1)
		v.PB(i-1);
	i = n / 2;
	while(i<n && s[i] == '0') i++;
	if(i>=0 && i < n)
		v.PB(i-1);
	string ans(100005, '9' ); 
	for(int i:v) {
		string a = s.substr(0, i+1);
		string b = s.substr(i+1);
		if(a[0] == '0' || b[0] == '0') continue;
		string c = add(a, b);
		ans = smin(c, ans);
	}
	cout << ans << endl;
	 
}