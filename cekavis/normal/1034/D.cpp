#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<set>
#include<vector>

using namespace std;
#define ll long long
#define pb push_back

inline char read() {
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s==t?t=(s=buf)+fread(buf,1,IN_LEN,stdin),(s==t?-1:*s++):*s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig=false, c=read(); !isdigit(c); c=read()) {
		if (c == '-') iosig=true;
		if (c == -1) return;
	}
	for (x=0; isdigit(c); c=read()) x=((x+(x<<2))<<1)+(c^'0');
	if (iosig) x=-x;
}

const int N = 300005, inf = 1e9+1;
int mx, n, k, id, a[N], b[N], len[N];
struct seg{
	int l, r, col;
	inline bool operator <(const seg &rhs)const{ return l<rhs.l || (l==rhs.l && r<rhs.r);}
};
set<seg> s;
vector<seg> e[N];
inline void init(){
	s.insert((seg){0, inf, 0});
	for(int i=1; i<=n; ++i){
		auto it=s.lower_bound((seg){a[i], inf, 0});
		--it;
		// for(auto j:s) printf("----------------%d %d %d\n", j.l, j.r, j.col);
		// printf(">>%d %d %d\n", it->l, it->r, it->col);
		if(it->r >= b[i]){
			e[i].pb((seg){a[i], b[i], it->col});
			if(it->l < a[i]) s.insert((seg){it->l, a[i]-1, it->col});
			if(it->r > b[i]) s.insert((seg){b[i]+1, it->r, it->col});
			s.erase(it);
			s.insert((seg){a[i], b[i], i});
			continue;
		}
		e[i].pb((seg){a[i], it->r, it->col});
		if(it->l < a[i]) s.insert((seg){it->l, a[i]-1, it->col});
		s.erase(it++);
		if(it->r<a[i]) ++it;
		while(it->r < b[i]) e[i].pb(*it), s.erase(it++);
		e[i].pb((seg){it->l, b[i], it->col});
		if(it->r > b[i]) s.insert((seg){b[i]+1, it->r, it->col});
		s.erase(it);
		s.insert((seg){a[i], b[i], i});
	}
	// for(int i=1; i<=n; ++i) for(auto j:e[i]) printf("%d : %d %d %d\n", i, j.l, j.r, j.col);
}
inline bool check(int x){
	int sum=0;
	ll cnt=0;
	for(int i=1, l=1; i<=n; ++i){
		sum+=(len[i]=b[i]-a[i]+1);
		for(auto j:e[i]){
			len[j.col]-=j.r-j.l+1;
			if(j.col && j.col>=l) sum-=j.r-j.l+1;
		}
		while(sum>=x) sum-=len[l], ++l;
		cnt+=l-1;
	}
	return cnt>=k;
}
inline ll solve(int x){
	int sum=0;
	ll ans=0, cnt=0, now=0;
	for(int i=1, l=1; i<=n; ++i){
		sum+=(len[i]=b[i]-a[i]+1);
		for(auto j:e[i]){
			len[j.col]-=j.r-j.l+1;
			if(j.col && j.col>=l) sum-=j.r-j.l+1;
			if(j.col && j.col<l) now-=(ll)j.col*(j.r-j.l+1);
		}
		// printf(" >> %d %d\n", sum, l);
		while(sum>=x) sum-=len[l], now+=(ll)l*len[l], ++l;
		// for(int j=1; j<=i; ++j) printf("[%d]", len[j]); puts("");
		ans+=now+(ll)sum*(l-1);
		cnt+=l-1;
	}
	return ans-(ll)(cnt-k)*x;
}
int main() {
	read(n), read(k);
	for(int i=1; i<=n; ++i) read(a[i]), read(b[i]), --b[i];
	init();
	int l=1, r=1e9, ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1, ans=mid; else r=mid-1;
	}
	return printf("%lld", solve(ans)), 0;
}