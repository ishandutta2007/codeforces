#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int maxn=100010;
ll l,r;
int h,q,n;
pair<ll,ll> p[maxn];

int main(){
	cin >> h >> q;
	l=1LL<<(h-1);
	r=1LL<<h;
	while(q--) {
		ll i,L,R,ans;
		cin >> i >> L >> R >> ans;
		L <<= h-i;
		R = (R+1)<<(h-i);
		if(ans) l=max(l,L),r=min(r,R);
		else p[n++]={L,R};
	}
	sort(p,p+n);
	
	F0R(i,n) if(p[i].first<=l && l<p[i].second) l=p[i].second;
	while(n--) if(p[n].first<r && r<=p[n].second) r=p[n].first;
	if(l>=r) cout << "Game cheated!";
	else if(r-l>1) cout << "Data not sufficient!";
	else cout << l << endl;
	return 0;
}