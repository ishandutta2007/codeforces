#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int n,m, ok[1000][1000];
int xdir[4] = {1,0,-1,0}, ydir[4] = {0,1,0,-1};
pii S,T;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	F0R(i,n) F0R(j,m) {
		char c; cin >> c;
		if (c == 'S') S = {i,j};
		else if (c == 'T') T = {i,j};
		else if (c == '*') ok[i][j] = -1;
	}
	F0R(i,4) {
		pii cur = S;
		while (cur.f >= 0 && cur.f<n && cur.s>=0 && cur.s<m && ok[cur.f][cur.s] != -1) {
			ok[cur.f][cur.s] = 1;
			cur.f += xdir[i];
			cur.s += ydir[i];
		} 
	}
	F0R(i,4) {
		pii cur = T;
		while (cur.f >= 0 && cur.f<n && cur.s>=0 && cur.s<m && ok[cur.f][cur.s] != -1) {
			if (ok[cur.f][cur.s] == 1) {
				cout << "YES";
				return 0;
			}
			ok[cur.f][cur.s] = 2;
			cur.f += xdir[i];
			cur.s += ydir[i];
		} 
	}
	F0R(i,n) {
		bool b1 = 0, b2 = 0;
		F0R(j,m) {
			if (ok[i][j] == -1) b1 = b2 = 0;
			else if (ok[i][j] == 1) b1 = 1;
			else if (ok[i][j] == 2) b2 = 1;
			if (b1 == 1 && b2 == 1) {
				cout << "YES";
				return 0;
			}
		}
	}
	F0R(j,m) {
		bool b1 = 0, b2 = 0;
		F0R(i,n) {
			if (ok[i][j] == -1) b1 = b2 = 0;
			else if (ok[i][j] == 1) b1 = 1;
			else if (ok[i][j] == 2) b2 = 1;
			if (b1 == 1 && b2 == 1) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}