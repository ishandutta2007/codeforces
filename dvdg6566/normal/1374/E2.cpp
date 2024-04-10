#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
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
const ll INF = 1e9;
const ll MOD = 1e9+7;

ll N,M,K,a,b,c,OX;
vi A,B,C;

ll run(){
	priority_queue<pi,vpi,greater<pi>> W,X,Y,Z;
	priority_queue<pi> uX,uY,uZ;
	for(int i=0;i<N;++i){
		a=A[i];b=B[i];c=C[i];

		if(b&&c)W.emplace(a,i+1);
		else if(b)X.emplace(a,i+1);
		else if(c)Y.emplace(a,i+1);
		else Z.emplace(a,i+1);
	}
	while(SZ(X)<N)X.emplace(1e10,-1);
	while(SZ(Y)<N)Y.emplace(1e10,-1);
	while(SZ(Z)<N)Z.emplace(1e10,-1);
	multiset<int> res;
	
	ll minReq=max(0LL,2*K-M);
	if(minReq>SZ(W)){cout<<-1;exit(0);}
	ll cur=0;
	ll ans=1e18;

	for(int i=0;i<minReq;++i){
		pi t=W.top();W.pop();
		res.insert(t.s);
		cur+=t.f;
	}

	ll oth=K-minReq;
	for(int i=0;i<oth;++i){
		pi t=X.top();X.pop();
		uX.push(t);
		res.insert(t.s);
		cur+=t.f;
		t=Y.top();Y.pop();
		uY.push(t);
		res.insert(t.s);
		cur+=t.f;
	}
	while(SZ(X)){Z.push(X.top());X.pop();}
	while(SZ(Y)){Z.push(Y.top());Y.pop();}

	assert(SZ(res)<=M);
	while(SZ(res) < M){
		pi t=Z.top();Z.pop();
		res.insert(t.s);
		uZ.push(t);
		cur+=t.f;
	}

	if(cur==OX){
		cout<<cur<<'\n';
		for(auto t:res)cout<<t<<' ';
		exit(0);
	}

	ans=min(ans,cur);
	while(1){
		if(SZ(W)==0)break;
		minReq++;
		if(minReq>M)break;
		pi t=W.top();W.pop();
		res.insert(t.s);
		cur+=t.f;

		// Release X and Y
		if(SZ(uX)){
			t=uX.top();uX.pop();
			cur-=t.f;
			res.erase(res.find(t.s));
			Z.push(t);

			t=uY.top();uY.pop();
			cur-=t.f;
			res.erase(res.find(t.s));
			Z.push(t);
		}
		// cerr<<"Minreq "<<minReq<<' '<<cur<<'\n';
		// rebalance 0Z
		for(int i=0;i<2&&SZ(uZ);++i){
			pi t=uZ.top();uZ.pop();
			Z.push(t);
			res.erase(res.find(t.s));
			cur-=t.f;
		}
		while(SZ(res) < M){
			pi t=Z.top();Z.pop();
			res.insert(t.s);
			uZ.push(t);
			cur+=t.f;
		}
		if(cur==OX){
			cout<<cur<<'\n';
			for(auto t:res)cout<<t<<' ';
			exit(0);
		}
		assert(SZ(res)==M);
		ans=min(ans,cur);
		// cout<<"Ignoring "<<SZ(W)<<' '<<cur<<'\n';
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M>>K;
	for(int i=0;i<N;++i){
		cin>>a>>b>>c;
		A.pb(a);B.pb(b);C.pb(c);
	}

	OX=-INF;

	OX=run();
	if(OX>1e10){
		cout<<-1;
		return 0;
	}

	run();
}