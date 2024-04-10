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
	
	int t;
	cin >> t;
	while(t--) {
		map<char, int> m;
		string s;
		cin >> s;
		for(char c:s)
			m[c]++;
		if(m.size() == 1) {
			cout << s << endl;
		} else if(m.size() == 2) {
			sort(s.begin(), s.end());
			bool nonoans = 1;
			for(int i=0;i<s.size()-1;i++) {
				if(s[i+1]-s[i] == 1) {
					cout << "No answer" << endl;
					nonoans = 0;
				}
			}
			if(nonoans)
				cout << s << endl;
		} else if(m.size() == 3) {
			string t;
			vector<pair<char, int>> v;
			for(auto p:m)
				v.PB(p);
			if(v[1].F - v[0].F == 1 && v[2].F - v[1].F == 1){
				cout << "No answer" << endl;
			} else {
				if(v[1].F - v[0].F == 1) {
					swap(v[1], v[2]);
				} else {
					swap(v[0], v[1]);
				}
				for(int i=0;i<3;i++)
					for(int j=0;j<v[i].S;j++)
						t += v[i].F;
				cout << t << endl;
			}
		} else {
			string t;
			vector<pair<char, int>> v;
			for(auto p:m)
				v.PB(p);
			for(int i=1;i<v.size();i+=2)
				for(int j=0;j<v[i].S;j++)
					t += v[i].F;
			for(int i=0;i<v.size();i+=2)
				for(int j=0;j<v[i].S;j++)
					t += v[i].F;
			cout << t << endl;
		}
	}
	
}