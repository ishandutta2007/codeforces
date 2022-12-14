#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
ll n, m, ans;

ll gcd(ll a, ll b){
	if(!b) return a;
	else{
		ans += a / b;
		return gcd(b, a % b);
	}
}


int main(){
	cin >> n >> m;
	gcd(n, m);
	cout << ans << endl;
	return 0;
}