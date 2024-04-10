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

char arr[150][150];
int ans=0,dir=1;
pii cpos = mp(0,0);
int n,m, lastrow = -1; 

void move() {
	if (cpos.f >= lastrow) {
		if (dir == 1) {
			int mx = cpos.s;
			F0Rd(i,m) 
				if (arr[cpos.f][i] == 'W') {
					mx = max(mx,i);
					break;
				}
			ans += mx-cpos.s;
		} else {
			int mx = cpos.s;
			F0R(i,m) 
				if (arr[cpos.f][i] == 'W') {
					mx = min(mx,i);
					break;
				}
			ans += cpos.s-mx;
		}
		cpos.f++;
	} else {
		if (dir == 1) {
			int mx = cpos.s;
			F0Rd(i,m)
				if (arr[cpos.f][i] == 'W' || arr[cpos.f+1][i] == 'W') {
					mx = max(mx,i);
					break;
				}
			ans += mx-cpos.s;
			cpos = mp(cpos.f+1,mx);
		} else {
			int mx = cpos.s;
			F0R(i,m)
				if (arr[cpos.f][i] == 'W' || arr[cpos.f+1][i] == 'W') {
					mx = min(mx,i);
					break;
				}
			ans += cpos.s-mx;
			cpos = mp(cpos.f+1,mx);
		}
		ans++;
		dir = -dir;
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	F0R(i,n) F0R(j,m) cin >> arr[i][j];
	bool flag = 0;
	F0Rd(i,n) {
		F0R(j,m) if (arr[i][j] == 'W') {
			lastrow = i;
			flag = 1;
			break;
		}
		if (flag == 1) break;
	}
	while (1) {
		move ();
		if (cpos.f > lastrow) break;
	}
	cout << ans;
}