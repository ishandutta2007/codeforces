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

int ct[3];

int main()
{
	IO_OP;
	
	int n;
	string s;
	cin >> n >> s;
	for(char c:s)
		ct[c-'0']++;
	for(int i=0;i<3;i++)
		ct[i] = n/3 - ct[i];
	if(ct[0] > 0) {
		for(int i=0;ct[0];i++) {
			if(ct[s[i]-'0'] >= 0) continue;
			ct[0]--;
			ct[s[i]-'0']++;
			s[i] = '0';
		}
	} 
	if(ct[0] < 0) {
		vi v;
		for(int i=n-1;ct[0];i--) {
			if(s[i] != '0') continue;
			ct[0]++;
			v.PB(i);
		}
		for(int i=v.size()-1;i>=0;i--) {
			int j = v[i];
			if(ct[1] > 0) {
				s[j] = '1';
				ct[1]--;
			} else {
				s[j] = '2';
				ct[2]--;
			}
		}
	}
	
	if(ct[1] > 0) {
		for(int i=0;ct[1];i++) {
			if(ct[s[i]-'0'] >= 0) continue;
			ct[1]--;
			ct[s[i]-'0']++;
			s[i] = '1';
		}
	} 
	if(ct[1] < 0) {
		vi v;
		for(int i=n-1;ct[1];i--) {
			if(s[i] != '1') continue;
			ct[1]++;
			s[i] = '2';
		}
	}

	cout << s << endl; 
}