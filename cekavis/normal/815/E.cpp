#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>
#include<map>

using namespace std;
#define ll long long

const int N = 600005;

ll n, k, x;
map<ll,ll> f;
inline ll solve(ll l, ll r){
	// printf(">> %lld %lld %lld %lld\n", l, r, (r-l)/2, f[(r-l)/2]);
	if((r-l)/2==x) return (l+r)/2+k-1;
	if(k<=f[(r-l)/2]) return solve(l, (l+r)/2);
	else return k-=f[(r-l)/2], solve((l+r)/2, r);
}
int main() {
	scanf("%lld%lld", &n, &k);
	if(k==1) puts("1"); else if(k==2) printf("%lld", n);
	else{
		f[n-1]=1;
		ll p=k-2;
		auto i=f.end();
		while((--i)->second<p)
			p-=i->second, f[i->first/2]+=i->second, f[(i->first+1)/2]+=i->second;
			// printf("%lld %lld %lld\n", i->first, i->second, p);
		k-=2, x=i->first/2;
		if(i->first&1) f[i->first-1];
		for(auto &t:f){
			if(t.first>>1 > x) k-=t.second, t.second=f[t.first/2]+f[(t.first+1)/2];
			else if(t.first>>1 == x) t.second=1+(t.first==3);
			else t.second=0;
			// printf("-- %lld %lld\n", t.first, t.second);
		}
		// printf(">> %d\n", k);
		printf("%lld", solve(1, n));
	}
	return 0;
}