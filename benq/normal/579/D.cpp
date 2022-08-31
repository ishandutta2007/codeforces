#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define vi vector<int>

#define F0R(i, a) for (int i=0; i<a; i++)

int n,k,x,bits[32];
ll a[200000], m1, ans, prod = 1, num;

int main() {
	cin >> n >> k >> x;
	F0R(i,k) prod *= x;
	F0R(i,n) {
		cin >> a[i];
		F0R(j,32) if (a[i] & (1<<j)) bits[j] ++;
		m1 = max(a[i],m1);
	}
	F0R(i,32) if (bits[i]) num |= (1<<i);
	F0R(i,n) {
		ll z = prod*a[i], num1 = num;
		F0R(j,32) if ((a[i] & (1<<j)) && bits[j] == 1) num1 -= (1<<j);
		ans = max(ans,num1|z);
	}
	cout << ans;
}