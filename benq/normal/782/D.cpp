#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define vi vector<int>

int n;
map<string,int> tim;
map<string,multiset<int>> take;
vector<string> posi[1000];
string ans[1000];

void init() {
	cin >> n;
	F0R(i,n) {
		string s1, s2; cin >> s1 >> s2;
		s1 = s1.substr(0,3);
		tim[s1] ++;
		posi[i].pb(s1);
		posi[i].pb(s1.substr(0,2)+s2[0]);
	}
}

void prin() {
	cout << "YES\n";
	F0R(i,n) cout << ans[i] << "\n";	
}

bool check() {
	for (auto a: take) if (a.s.size() > 2) return 0;
	return 1;
}

void tak(string s) {
	//cout << "HI " << take[s].size() << "\n";
	for (int a: take[s]) {
		//cout << "a " << a << "\n";
		posi[a].erase(find(posi[a].begin(),posi[a].end(),s));
	}
	take[s].clear();
}

int main() {
	init();
	F0R(i,n) if (tim[posi[i][0]] > 1) posi[i].erase(posi[i].begin());
	F0R(i,n) for (string j: posi[i]) take[j].insert(i);
	while (1) {
		bool flag = 0;
		F0R(i,n) if (ans[i].size() == 0) {
			if (posi[i].size() == 0) {
				cout << "NO\n";
				return 0;
			} else if (posi[i].size() == 1) {
				ans[i] = posi[i][0];
				tak(ans[i]);
				flag = 1;
			}
		}
		if (!flag) {
			F0R(i,n) if (ans[i].size() == 0) if (posi[i].size() == 2) {
				ans[i] = posi[i][1];
				tak(ans[i]);
				take[posi[i][0]].erase(i);
				flag = 1;
				break;
			}
		}
		if (!flag) break;
	}
	prin();
}