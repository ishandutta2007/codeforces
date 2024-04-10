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

#define lld I64d

const int N = 2e6;
int n;
ll tmp[N+5] = {0}, fs[N+5]={}, f[N+5]={};
ll x,y;

ll gx(ll i, ll j) {
	if(j < i) return 0;
	return x * (f[j] - f[i-1]);
}

ll gy(ll i, ll j) {
	ll q = y * (fs[j] - fs[i-1] - f[i-1]*(j-i+1));
	return q;
}

int main() {	
	scanf("%d%lld%lld",&n,&x,&y);
	for(int i = 0; i < n; ++i) {
		int a;
		scanf("%d",&a);
		++f[a];
	}
	for(int i = 1; i < N+5; ++i) {
		f[i] += f[i-1];
		fs[i] = fs[i-1] + f[i-1];
	}
	ll k = (x+(y-1))/y;
	ll ans = 1LL<<60;
	for(int i = 2; i <= N; ++i) {
		ll a = 0;
		for(int j = i; j <= N; j += i) {
			a += gy(max(ll(j-i+1),j-(k-1)),j);
			a += gx(j-i+1,j-k);
		}
		ans = min(ans,a);
	}
	printf("%lld\n",ans);
}