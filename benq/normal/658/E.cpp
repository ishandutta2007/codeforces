#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

ll cur[5], last[5], ans=1000000000000000000,b,c;
queue<int> track[5][5];
int n,k, users[200000];

ll query(int x, int y) {
	ll v = (ll)(y-x);
	return (v/5)*b+(v%5)*c;
}

void add(int x, int i) {
	int y = x % 5, y1 = users[i] % 5;
	if (y < 0) y += 5;
	if (y1 < 0) y1 += 5;
	cur[y] += (ll)min(i,k)*b*((x-last[y])/5);
	if (i >= k) {
		ll max1 = -1, max2 = -1;
		F0R(z,5) {
			if (track[y][z].size() > 0) {
				ll w = query(track[y][z].front(),x);
				if (w > max1) max1 = w, max2 = z;
			}
		}
		cur[y] -= max1;
		track[y][max2].pop();
	}
	track[y][y1].push(users[i]);
	cur[y] += query(users[i],x), last[y] = x;
	if (i >= (k-1)) ans = min(cur[y],ans);
}

int main() {
	cin >> n >> k >> b >> c;
	b = min(b,5*c);
	F0R(i,n) scanf("%d",&users[i]);
	sort(users,users+n);
	F0R(i,n) F0R(j,5) add(users[i]+j,i);
	cout << ans;
	return 0;
}