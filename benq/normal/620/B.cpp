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
 
const int MOD = 1000000007;
const int MAX = 10000005;

int a,b, segments[1000001];
	
int find_value (int x) {
	int asdf = 0;
	string v = to_string(x);
	F0R(i,v.length()) {
		asdf += segments[v[i]-'0'];
	}
	return asdf;
}

int main() {
	segments[0] = 6;
	segments[1] = 2;
	segments[2] = 5;
	segments[3] = 5;
	segments[4] = 4;
	segments[5] = 5;
	segments[6] = 6;
	segments[7] = 3;
	segments[8] = 7;
	segments[9] = 6;
	FOR(i,10,1000001) segments[i] = segments[(i/10)]+segments[(i % 10)];
	cin >> a >> b;
	int ans=0;
	FOR(i,a,b+1) ans += segments[i];
	cout << ans;
	return 0;
}