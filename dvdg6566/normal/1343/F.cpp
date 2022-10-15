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
const int MAXN=210;
const int MAXK=18;
const ll INF = 1e9;
const ll MOD = 1e9+7;

ll N,K,R,C,T,a,b,c,OX;
vi A[MAXN];
vi res;
int dne[MAXN];

bool test(int a,int b){
	// cerr<<"Test "<<a<<' '<<b<<'\n';
	memset(dne,0,sizeof(dne));
	res.clear();res.pb(a);res.pb(b);
	dne[a]=dne[b]=1;
	while(SZ(res)<N){
		// for(int i=1;i<=N;++i)cout<<dne[i]<<' ';cout<<'\n';
		int tar=-1;
		int w=-1;
		for(int i=1;i<N;++i){
			int r=0;
			for(auto t:A[i])if(!dne[t])++r;
			if(r==1)tar=i;
		}
		if(tar==-1)return 0;
		for(auto t:A[tar])if(!dne[t])w=t;
		res.pb(w);
		dne[w]=1;
	}
	if(SZ(res)==N){
		// for(auto t:res)cout<<t<<' ';cout<<'\n';
		set<int> X;
		int ind[MAXN];
		for(int i=0;i<N;++i)ind[res[i]]=i+1;
		for(int k=1;k<N;++k){
			int lwst=INF;
			int r=0;
			for (auto t:A[k]){
				r=max(r,ind[t]);
				lwst=min(lwst,ind[t]);
			}
			if(X.find(r)!=X.end())return 0;
			if(r-lwst+1!=SZ(A[k]))return 0;
			// cout<<r<<'\n';
			X.insert(r);
		}

		for(auto t:res)cout<<t<<' ';cout<<'\n';
		return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=1;i<N;++i){
			cin>>R;
			A[i].clear();
			for(int j=0;j<R;++j){
				cin>>a;A[i].pb(a);
			}

		}
		for(int i=1;i<=N;++i)if(SZ(A[i])==2){
			int a=A[i][0];
			int b=A[i][1];
			if(test(a,b))break;
			if(test(b,a))break;			
		}
	}
}