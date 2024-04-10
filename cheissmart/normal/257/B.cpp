#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

pi sol(int n, int m) {
	string s = "";
	s += 'a';
	int k = n + m;
	n--;
	for(int i=1;i<k;i++) {
		if(i%2 == 0) {
			if(n == 0) {
				s += 'b';
			}
			else if(m == 0) {
				s += 'a';
			}
			else if(s.back() == 'a') {
				s += 'a';
				n--;
			} else {
				s += 'b';
				m--;
			}
		} else {
			if(n == 0) {
				s += 'b';
			}
			else if(m == 0) {
				s += 'a';
			}
			else if(s.back() == 'a') {
				s += 'b';
				m--;
			} else {
				s += 'a';
				n--;
			}
		}
	}
	//cout << s << endl;
	int p1 = 0, p2 = 0;
	for(int i=0;i<k-1;i++) {
		if(s[i] == s[i+1])
			p1++;
		else
			p2++;
	}
	return {p1, p2};
}

int main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	pi p1 = sol(n, m), p2 = sol(m, n);
	if(p1.F > p2.F) {
		cout << p1.F << " " << p1.S << endl;
	} else if(p1.F < p2.F) {
		cout << p2.F << " " << p2.S << endl;
	} else {
		if(p1.S > p2.S)
			cout << p2.F << " " << p2.S << endl;
		else
			cout << p1.F << " " << p1.S << endl;
	}
}