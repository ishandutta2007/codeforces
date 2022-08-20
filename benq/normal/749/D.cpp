#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

#define mp make_pair
#define pb push_back
#define f first
#define s second

int n,q;
set<pii> bids;
unordered_map<int,vi> people;

void binsearch(int person, int val) {
	int low = 0, high = people[person].size()-1;
	while (low != high) {
		int mid = (low+high+1)/2;
		if (people[person][mid]<val) high = mid-1;
		else low = mid;
	}
	cout << person << " " << people[person][low] << "\n";
}

void solve() {
	if (bids.size() == 0) cout << "0 0\n";
	else if (bids.size() == 1) {
		int person = (*bids.begin()).s;
		cout << person << " " << people[person][people[person].size()-1] << "\n";
	} else binsearch((*prev(bids.end())).s,(*prev(prev(bids.end()))).f);
}

void input() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
		int x,y; cin >> x >> y;
		people[x].pb(y);
	}
	for (auto a: people) {
		reverse(people[a.f].begin(),people[a.f].end());
		bids.insert(mp(people[a.f][0],a.f));
	}
	cin >> q;
}

int main() {
	input();
	F0R(i,q) {
		int k; cin >> k;
		vi notgoing;
		F0R(j,k) {
			int x; cin >> x; 
			if (people.find(x) != people.end()) {
				bids.erase(mp(people[x][0],x));
				notgoing.pb(x);
			}
		}
		solve();
		for (int j: notgoing) bids.insert(mp(people[j][0],j));
	}
}