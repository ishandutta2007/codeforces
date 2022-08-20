#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

ll a[200001], t[200001],n,w,k;
ll ans = 0, cur = 0;
multiset<int> m1, m2;

void input() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> w >> k;
	FOR(i,1,n+1) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	FOR(i,1,n+1) cin >> t[i];
}

void update(bool rem, int num) {
	if (rem == 0) {
		if (m2.find(num) != m2.end()) {
			m2.erase(m2.find(num));
			cur -= num;
			return;
		} 
		m1.erase(m1.find(num));
		cur -= (num+1)/2;
		if (m2.size()) {
			int temp = *prev(m2.end());
			m1.insert(temp);
			m2.erase(m2.find(temp));
			cur -= temp;
			cur += (temp+1)/2;
		}
		return;
	} 
	if (m1.size()<w) {
		m1.insert(num);
		cur += (num+1)/2;
		return;
	}
	if (num>*m1.begin()) {
		m1.insert(num);
		cur += (num+1)/2;
		int temp = *m1.begin();
		m1.erase(m1.find(temp)); m2.insert(temp);
		cur -= (temp+1)/2;
		cur += temp;
		return;
	}
	m2.insert(num);
	cur += num;
}

int main() {
	input();
	int r = 0;
	FOR(l,1,n+1) {
		if (r == l-2) r++;
		else if (l != 1) update(0,t[l-1]);
		while (r<n) {
			update(1,t[++r]);
			if (cur>k) {
				update(0,t[r--]);
				break;
			}
		}
		ans = max(ans,a[r]-a[l-1]);
	}
	cout << ans;
}