#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define be begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

int main() {
	int z;
	cin >> z;
	int n[100001], m[100001], k;
	FOR(i,1,100001) {
		if (i % 5 == 0) n[i] = n[i/5]+1;
		else n[i] = 1;
	}
	FOR(i,1,100001) {
		m[i] = n[i]+m[i-1];
	}
	int ind = int(lb(m,m+100001,z)-m);
	if (m[ind] == z) {
		cout << 5 << endl;
		F0R(i,5) {
			cout << (5*ind+i) << " ";
		}
	} else cout << 0;
}