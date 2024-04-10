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

int f3(ll a, ll b) {
	if(a > b) return 0;
	return 1+f3(3*a,b);
}

int f2(ll a, ll b) {
	if(a > b) return 0;
	return 1 + f2(2*a,b) + f3(3*a,b);
}

int main() {	
	ll l,r;
	cin >> l >> r;
	cout << f2(1,r) - f2(1,l-1) << "\n";
}