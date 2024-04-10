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

const int N = 1e5+5;
ll a[N];
ll b[N] = {}, c[N] = {};

int main() {	
	fio;
	int n;
	ll p,q,r;
	cin >> n >> p >> q >> r;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i) {
		b[i] = p*a[i];
		if(i) b[i] = max(b[i],b[i-1]);
	}
	swap(b,c);
	for(int i = 0; i < n; ++i) {
		b[i] = q*a[i] + c[i];
		if(i) b[i] = max(b[i],b[i-1]);
	}
	swap(b,c);
	for(int i = 0; i < n; ++i) {
		b[i] = r*a[i] + c[i];
		if(i) b[i] = max(b[i],b[i-1]);
	}
	cout << b[n-1] << "\n";
}