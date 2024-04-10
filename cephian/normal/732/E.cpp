#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;

const int N = 200005;
int n,m;
vector<pii> s,sp;
int a[N] = {0};
int b[N] = {0};
bool matched[N]={0};
set<pii> p;

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		int q;
		cin >> q;
		p.insert(pii(q,i));
	}
	for(int i = 1;  i <= m; ++i) {
		int q;
		cin >> q;
		s.push_back(pii(q,i));
	}
	int diff = 0;
	int adapters = 0;
	int connected=0;
	while(s.size()) {
		for(int i = 0; i < s.size(); ++i) {
			set<pii>::iterator j = p.upper_bound(pii(s[i].first,-1));
			if(j == p.end() || j->first != s[i].first) continue;
			adapters += diff;
			++connected;
			a[s[i].second] = diff;
			b[j->second] = s[i].second;
			p.erase(j);
			matched[s[i].second] = 1;	
		}
		sp.clear();
		for(int i = 0; i < s.size(); ++i) {
			if(s[i].first > 1 && !matched[s[i].second])
				sp.push_back(pii((s[i].first+1)/2,s[i].second));
				
		}
		swap(s,sp);
		++diff;
	}
	cout << connected << " " << adapters << "\n";
	for(int i = 1; i <= m; ++i) {
		cout << a[i] << " ";
	}
	cout << "\n";
	for(int i = 1; i <= n; ++i) {
		cout << b[i] << " ";
	}
	cout << "\n";
}