#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

int n, m, need[N], take[N], buy[2*N];
pi offer[N];

bool ok(int day) {
	memset(take, 0, sizeof take);
	memset(buy, 0, sizeof buy);
	
	int req = 0;
	for(int i=1;i<=n;i++)
		req += need[i] * 2;
	if(day >= req) return true;
	int offer_need = req - day;
	for(int i=m-1;i>=0;i--) {
		if(offer[i].F > day) continue;
		if(take[offer[i].S] < need[offer[i].S]) {
			int ttake = min(need[offer[i].S] - take[offer[i].S], offer_need);
			offer_need -= ttake;
			take[offer[i].S] += ttake;
			buy[offer[i].F] += ttake;
		}
	}
	if(offer_need) return false;
	int money = 0;
	for(int i=1;i<=day;i++) {
		money++;
		money -= buy[i];
		if(money < 0) return false;
	}
	return true;

}

signed main()
{
	IO_OP;
	
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> need[i];	
	for(int i=0;i<m;i++)
		cin >> offer[i].F >> offer[i].S;
	sort(offer, offer+m);
	int l = 0, r = 4e5 + 7;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(ok(mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << l << endl;

}