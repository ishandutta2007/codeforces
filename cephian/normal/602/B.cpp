#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

multiset<int> m;
set<int> elems;

void add(int x) {
	elems.insert(x);
	m.insert(x);
}

void remove(int x) {
	m.erase(m.find(x));
	if(m.find(x) == m.end())
		elems.erase(x);
}

int a[100005];

int main() {	
	int n;
	cin >> n;
	int j = 0, ans = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		add(a[i]);
		while(elems.size() > 2)
			remove(a[j++]);
		ans = max(ans,(int)m.size());
	}
	cout << ans << "\n";
}