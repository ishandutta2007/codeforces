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

const int N = 1000005;
//factorize integers in [0,N)
int fact[N];
void factor_all() {
	for(int i = 1; i < N; ++i)
		fact[i] = i;
	for(int i = 2; i < N; ++i)
		if(fact[i] == i)
			for(ll j = ll(i)*i; j < N; j += i)
				fact[j] = i;
}

set<int> poss,tmp;

vector<pii> events;

void reverse() {
	tmp.clear();
	events.clear();

	for(int x : poss) {
		if(x == fact[x]) continue;
		int y = x;
		while(y != 1) {
			int p = fact[y];
			events.emplace_back(max(p+1,x-p+1),1);
			events.emplace_back(x+1,0);
			y /= p;
		}
	}
	sort(events.begin(),events.end());
	int j = 0,a=0;
	for(int i = 3; i <= 1000000; ++i) {
		while(j < events.size() && events[j].first == i) {
			if(events[j].second == 0) --a;
			else ++a;
			++j;
		}
		if(a) tmp.insert(i);
	}
	swap(tmp,poss);
}

int main() {
	factor_all();
	int x;
	cin >> x;
	poss.insert(x);
	reverse();
	reverse();
	cout << *poss.begin() << "\n";
}