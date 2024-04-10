#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

string s[100005];
int a[100005], b[100005];
int ln, x = 0;
bool nosol = 0;

int f(int l, int r) {
	if(nosol) return 0;
	int c = 0;
	for(int i=l;i<r;i++) {
		if(s[i] == "add") {
			c++;
		} else if(s[i] == "for") {
			c += f(i+1, b[i]) * a[i];
			i = b[i];
		}
	}
	if(c > (1uLL<<32)-1)
		nosol = 1;
	return c;
}

int32_t main()
{
	IO_OP;
	cin >> ln;
	vi v;
	for(int i=0;i<ln;i++) {
		cin >> s[i];
		if(s[i] == "for") {
			cin >> a[i];
			v.PB(i);
		}
		else if(s[i] == "end") {
			b[v.back()] = i;
			v.pop_back();
		}
	}
	x = f(0, ln);
	if(nosol) {
		cout << "OVERFLOW!!!" << endl;
	} else {
		cout << x << endl;
	}
}