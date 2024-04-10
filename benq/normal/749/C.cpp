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

bool canvote[200000];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	string x; cin >> x;
	queue<int> todo, d, r;
	F0R(i,n) {
		canvote[i] = 1;
		todo.push(i);
		if (x[i] == 'D') d.push(i);
		else r.push(i);
	}
	while (1) {
		while (d.size()>0 && canvote[d.front()] == 0) d.pop();
		while (r.size()>0 && canvote[r.front()] == 0) r.pop();
		if (d.size() == 0 || r.size() == 0) break;
		int z = todo.front(); todo.pop();
		if (!canvote[z]) continue;
		if (d.front() == z) {
			d.pop();
			canvote[r.front()] = 0; r.pop();
			d.push(z), todo.push(z);
		} else {
			r.pop();
			canvote[d.front()] = 0; d.pop();
			r.push(z), todo.push(z);
		}
		if (d.size() == 0 || r.size() == 0) break;
	}
	if (d.size()>0) cout << 'D';
	else cout << 'R';
}