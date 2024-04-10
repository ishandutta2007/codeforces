#include <bits/stdc++.h>
#define F first
#define S second
#define ALL(v) (v).begin(), (v).end()
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef long long ll;

const int INF = 1e9 + 7;

int p[200005];

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	string s, t;
	cin >> n >> s;
	p[0] = s[0] == '(' ? 1 : -1;
	for(int i=1;i<s.size();i++)
		p[i] = p[i-1] + (s[i] == '(' ? 1 : -1);
	if(p[n-1] != 0) {
		cout << "NO" << endl;
		return 0;
	}
	int j = -1;
	for(int i=0;i<n;i++) {
		if(p[i] < 0) {
			j = i;
			break;
		}
	}
	if(j == -1) {
		cout << "YES" << endl;
		return 0;
	}
	t = s.substr(0, j) + s.substr(j+1) + s[j];
	int pp = t[0] == '(' ? 1 : -1;
	if(pp < 0) {
		cout << "NO" << endl;
		return 0;
	}
	for(int i=1;i<s.size();i++){
		pp += (t[i] == '(' ? 1 : -1);
		if(pp < 0) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}