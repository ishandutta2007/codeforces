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
	cin >> n;
	vector<pair<int, int>> v;
	vector<string> ss(n);
	string ans(2000006, 'a');
	for(int i=0;i<n;i++) {
		int k;
		cin >> ss[i] >> k;
		for(int j=0;j<k;j++) {
			int t;
			cin >> t;
			v.EB(--t, i);
		}
	}
	sort(v.begin(), v.end());
	int end = 0;
	for(auto &p:v) {
		string &s = ss[p.S];
		int &pos = p.F;
		if(pos+s.size()-1 < end)
			continue;
		for(int i=max(end, pos);i<pos+s.size();i++)
			ans[i] = s[i-pos];
		end = pos + s.size();
	} 
	for(int i=0;i<end;i++)
		cout << ans[i]; 
	
}