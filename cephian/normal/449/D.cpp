#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int f[1<<20][21]={},n,a;
const ll M = 1e9+7;
ll pw(ll a, ll b) {
	if(!b) return 1;
	if(b&1) return a*pw(a,b-1)%M;
	ll t = pw(a,b/2);
	return t*t%M;
}

int nb(int b) {
	int a=0;
	for(;b;a+=(b&1),b>>=1);
	return a;
}

int main() {
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) {
		scanf("%d",&a);
		++f[a][0];
	}
	for(int k = 1; k <= 20; ++k) {
		for(int m = 0; m < (1<<20); ++m) {
			int r=k-1;
			if(m&(1<<r)) f[m][k] = f[m][k-1];
			else f[m][k] = f[m][k-1]+f[m^(1<<r)][k-1];
		}
	}
	a = 0;
	for(int m = 0; m < (1<<20); ++m) {
		a = (a + ((nb(m)&1)?M-1:1)*pw(2,f[m][20]))%M;
	}
	printf("%d\n",a);

	return 0;
}