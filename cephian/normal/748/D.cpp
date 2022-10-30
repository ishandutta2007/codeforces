#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

string s,r;
map<int,vi> m;
map<string,int> ind;
set<int> pals;
int ctr = 1;

void rev(string& s) {
	r=s;
	for(int i = 0; i < s.size(); ++i)
		r[s.size()-1-i] = s[i];
}

int main() {
	ios::sync_with_stdio(0); cin.tie();
	int n,l;
	cin >> n >> l;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> s >> a;
		int j = ctr;
		if(ind.count(s))
			j=ind[s];
		if(j==ctr) {
			ctr++;
			ind[s] = j;
			rev(s);
			if(s!=r) ind[r] = -j;
			else pals.insert(j);
		}
 		m[j].push_back(a);
	}
	for(auto& v : m)
		sort(v.second.rbegin(),v.second.rend());
	int ans = 0;
	int change = 0;
	for(auto& v : m) {
		if(v.first < 0) continue;
		//if pal-part
		if(pals.count(v.first)) {
			int norm = 0;
			for(int i = 0; i+1 < v.second.size(); i+=2) {
				if(v.second[i]+v.second[i+1] <= 0) break;
				norm += v.second[i]+v.second[i+1];
			}
			int spec = max(0,v.second[0]);
			for(int i = 1; i+1 < v.second.size(); i+=2) {
				if(v.second[i]+v.second[i+1] <= 0) break;
				spec += v.second[i]+v.second[i+1];
			}
			ans += norm;
			change = max(change,spec-norm);
		}
		else {
			vi& w = v.second;
			vi& u = m[-v.first];
			for(int i = 0; i < min(w.size(),u.size()) && w[i]+u[i]>0; ++i)
				ans += w[i]+u[i];
		}
	}
	cout << ans+change << "\n";
	return 0;
}