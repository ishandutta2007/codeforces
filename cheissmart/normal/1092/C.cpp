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

string a[300];
int p[300], pl[300];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<2*n-2;i++){
		cin >> a[i];
	}
	string s, t;
	int si;
	for(int i=0;i<2*n-2;i++)
		if(a[i].size() == n-1)
			s = a[i], si = i;
	for(int i=0;i<2*n-2;i++)
		if(a[i].size() == n-1 && i != si)
			t = a[i];
	if(s.substr(1) == t.substr(0, t.size()-1)) {
		string m = s + t[n-2];
		bool ok = true;
		for(int i=0;i<2*n-2;i++) {
			if(!p[a[i].size()] && a[i] == m.substr(0, a[i].size())) {
				pl[i] = 1;
				p[a[i].size()] = 1;
			} else {
				if(a[i] != m.substr(m.size()-a[i].size())) {
					ok = false;
					break;
				}
			}
		}
		if(ok) {
			for(int i=0;i<2*n-2;i++)
				if(pl[i]) cout << 'P';
				else cout << 'S';
			return 0;
		}
	}
	for(int i=0;i<300;i++)
		pl[i] = p[i] = 0;
		
	string m = t + s[n-2];
	
	bool ok = true;
	for(int i=0;i<2*n-2;i++) {
		if(!p[a[i].size()] && a[i] == m.substr(0, a[i].size())) {
			pl[i] = 1;
			p[a[i].size()] = 1;
		}
	}
	for(int i=0;i<2*n-2;i++)
		if(pl[i]) cout << 'P';
		else cout << 'S';
}