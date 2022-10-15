#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end() 
#define SZ(x) (ll)x.size()
#define f first
#define s second
const int MAXN=200100;
const int MAXK=18;
const int INF = 1e9;
const ll MOD = 1e9+7;

ll N,R,K,a,b,c;
vi A,B,C;
multiset<int> W,X,Y;
multiset<int> uW;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;++i){
		cin>>a>>b>>c;
		A.pb(a);B.pb(b);C.pb(c);

		if(b&&c)W.insert(a);
		else if(b)X.insert(a);
		else if(c)Y.insert(a);
	}
	ll cur=0;
	ll ans=1e18;
	ll R=min(K,SZ(W));
	for(int i=0;i<R;++i){
		ll a=*W.begin();
		W.erase(W.begin());
		uW.insert(a);
		cur+=a;
	}
	// cout<<R<<' '<<cur<<'\n';
	ll leftcnt=0;
	while(1){
		// cout<<leftcnt<<' '<<SZ(uW)<<'\n';
		while(leftcnt+SZ(uW) < K){
			++leftcnt;
			if(SZ(X)==0||SZ(Y)==0){
				if(ans==(ll)1e18)ans=-1;
				cout<<ans;return 0;
			}
			cur+=*X.begin();X.erase(X.begin());
			cur+=*Y.begin();Y.erase(Y.begin());
		}
		// cout<<cur<<'\n';
		ans=min(ans,cur);

		if(SZ(uW)==0)break;	
		ll h=*(--uW.end());
		uW.erase(--uW.end());
		cur-=h;
	}
	// cout<<ans<<' '<<1e18<<'\n';
	if(ans==(ll)1e18)ans=-1;
	cout<<ans;
}