#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int u1[51], u2[51];

int main() {
	int n;
	cin >> n;
	F0R(i,n*n) {
		int a,b;
		cin >> a >> b;
		if (!u1[a] && !u2[b]) {
			u1[a] = 1, u2[b] = 1;
			cout << (i+1) << " ";
		}
	}
	return 0;
}