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

int main()
{
	IO_OP;
	
	int n;
	string s;
	cin >> n >> s;
	if(n%2 || s[0] == ')' || s[n-1] == '(') {
		cout << ":(" << endl;
		return 0;
	}
	s[0] = '(', s[n-1] = ')';
	int ct = 0, l = 0, r;
	for(int i=1;i<n-1;i++) {
		if(s[i] == '?')
			ct++;
		else if(s[i] == '(')
			l++;
	}
	l = (n-2)/2 - l;
	r = ct - l;
	if(l < 0 || r < 0) {
		cout << ":(" << endl;
		return 0;
	}
	for(int i=1;i<n-1;i++) {
		if(s[i] == '?') {
			if(l) {
				s[i] = '(';
				l--;
			}
			else
				s[i] = ')';
		}
	}
	int cnt = 0;
	for(int i=1;i<n-1;i++) {
		char c = s[i];
		if(c == '?'){
			cout << ":(" << endl;
			return 0;
		}
		if(c == '(')
			cnt++;
		else
			cnt--;
		if(cnt < 0) {
			cout << ":(" << endl;
			return 0;
		}
	}
	if(cnt){
		cout << ":(" << endl;
		return 0;
	} 
	cout << s << endl;
}