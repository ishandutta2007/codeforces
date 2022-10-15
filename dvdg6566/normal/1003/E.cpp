#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define lb lower_bound
const int MAXN=300001;
const ll MOD=998244353;
const int MAXL = 8000100;
const ll INF = 1e18;


int N,K,D;
vpi res;
int C;

void construct(int x,int h,int m1){
	if(h==0)return;
	if(C>=N)return;
	// cerr<<x<<' '<<h<<'\n';
	int deg=K-m1;
	for(int i=0;i<deg;++i)if(C<N){
		++C;
		res.pb(x,C);
		construct(C,h-1,1);
	}
}


int main(){
	cin>>N>>D>>K;++D;
	if(K == 1){
		if(N==2&&D==2){
			cout<<"YES\n1 2";
		}
		else cout<<"NO\n";
		return 0;
	}
	for(int i=1;i<D;++i){
		res.pb(i,i+1);
	}
	C=D;
	for(int i=1;i<=D;++i){
		int t=min(i,D-i+1)-1;
		construct(i,t,2);
	}
	if(C==N){
		cout<<"YES\n";
		for(auto i:res)cout<<i.f<<' '<<i.s<<'\n';
	}else{
		cout<<"NO"<<'\n';
	}
}