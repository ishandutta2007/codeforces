#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
#include <numeric>
#include <random>
#include <map>
#include <queue>
#include <bitset>
#include <string.h>
#include <assert.h>
using namespace std;
 
#define ll long long
#define ld double
const ll mod = 1e9 + 7;
const ll inv2 = (mod + 1) / 2ll;
const ll inv32 = 281250002ll;
const int MX = 1000005;
 
int main(){
	//cin.tie(0) -> sync_with_stdio(0);
 
	int tc; scanf("%d", &tc);
	for(ll n; tc --;){
		scanf("%lld", &n);
		ll up = (2ll * ((n % mod) * 1ll * (n % mod)) % mod) % mod;
		up = (up + (14ll * (n % mod)) % mod) % mod;
		up = (up + 21ll) % mod;
		if(n % 2 == 1) up = (up + mod - ((2ll * n) % mod + 7)) % mod;
		else up = (up + (2ll * n) % mod + 7ll) % mod;
		if(n % 4 < 2) up = (up + 4ll) % mod;
		else up = (up + mod - 4ll) % mod;
 
		up = (up * 1ll * inv32) % mod;
		printf("%lld\n", up);
	}
 
	return 0;
}