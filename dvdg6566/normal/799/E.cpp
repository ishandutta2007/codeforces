#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define MAXN 210000
#define MAXL 18

ll N,M,K;
ll A,B;
ll P,Q;
ll AL[MAXN], BL[MAXN];
ll W[MAXN];
ll a,b;
ll cur,ans;
priority_queue<ll,vi,greater<ll>> extras;
vi ABC,AC,BC;
multiset<ll> U;
ll used;

int main(){
	cin>>N>>M>>K;
	for (ll i=1;i<=N;++i)cin>>W[i];
	cin>>P;
	for (ll i=1;i<=P;++i){
		cin>>a;
		AL[a]=1;
	}
	cin>>Q;
	for (ll i=1;i<=Q;++i){
		cin>>a;
		BL[a]=1;
	}
	for (ll i=1;i<=N;++i){
		if (AL[i] && BL[i])ABC.pb(W[i]);
		else if (AL[i])AC.pb(W[i]);
		else if (BL[i])BC.pb(W[i]);
		else extras.push(W[i]);
	}
	sort(ALL(AC));
	sort(ALL(BC));
	sort(ALL(ABC));

	while (SZ(AC) > K){
		extras.push(AC.back());
		AC.pop_back();
	}
	while(SZ(BC) > K){
		extras.push(BC.back());
		BC.pop_back();
	}
	while(SZ(ABC) > K){
		extras.push(ABC.back());
		ABC.pop_back();
	}
	while(SZ(AC) > SZ(BC)){extras.push(AC.back());AC.pop_back();}
	while(SZ(BC) > SZ(AC)){extras.push(BC.back());BC.pop_back();}
	for (auto i:AC)cur+=i;
	for (auto i:BC)cur+=i;
	ans = 1e17;
	ll minreq = K - SZ(AC);

	if (minreq > SZ(ABC)){
		cout<<-1;
		return 0;
	}
	for (ll i=0;i<minreq;++i)cur += ABC[i];
	used = minreq + SZ(AC) + SZ(BC);

	while (used < M){
		if (SZ(extras)){
			int w = extras.top();extras.pop();
			++used;
			cur += w;
			U.insert(w);
		}else break;
	}
	while (used > M){
		if (SZ(U)){
			int w = *(--U.end()); U.erase(--U.end());
			cur -= w;
			--used;
			extras.push(w);
		}else break;
	}
	if (used==M)ans=min(ans,cur);

	for (ll i=minreq+1;i<=SZ(ABC);++i){
		ll w = ABC[i-1];
		ll l=i-1;
		++used;
		cur += w;
		// Inserting
		if (SZ(AC)){
			U.insert(AC.back());
			U.insert(BC.back());
			AC.pop_back();
			BC.pop_back();
			int w = *(--U.end());
			cur -= w;
			U.erase(--U.end());
			extras.push(w);
			w = *(--U.end());
			cur -= w;
			U.erase(--U.end());
			extras.push(w);
			used -= 2;
		}
		while (used < M){
			if (SZ(extras)){
				int w = extras.top();extras.pop();
				++used;
				cur += w;
				U.insert(w);
			}else break;
		}
		while (used > M){
			if (SZ(U)){
				int w = *(--U.end()); U.erase(--U.end());
				cur -= w;
				--used;
				extras.push(w);
			}else break;
		}
		if (SZ(U)&&SZ(extras))assert(*(--U.end()) <= extras.top());
		if (used==M){ans = min(ans, cur);}
	}
	if (ans == 1e17)cout<<-1;
	else cout<<ans;
}