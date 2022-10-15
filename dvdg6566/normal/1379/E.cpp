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
const ll MAXN=200100;
const ll MAXK=16000000;
const ll INF = 1e9;
const ll MOD = 1e9+7;

int A[MAXN];
int B[MAXN];
vi spec;

void generate(int c,int l,int r,int k){
	// cerr<<c<<' '<<l<<' '<<r<<' '<<k<<'\n';
	int n=(r-l+1);
	A[l]=c;
	if(n==1)return;
	if(k==0){
		assert(B[n]);
		int mid=(l+r)/2;
		generate(l,l+1,mid,0);
		generate(l,mid+1,r,0);
		return;
	}
	if(k==1){
		int L=-1;
		for(auto i:spec){
			int a=i;
			int b=n-1-i;
			if(b<0)continue;
			L=max(a,L);
			// cerr<<a<<' '<<b<<'\n';
			if(a>b)swap(a,b);
			if(a*2>=b){
				// breaks cleanly
				generate(l,l+1,l+i,0);
				generate(l,l+i+1,r,1);
				return;
			}
		}
		generate(l,l+1,l+L,0);
		generate(l,l+L+1,r,0);
		return;
	}
	if(k>2){
		if(n==11&&k==3){
			generate(l,l+1,l+3,0);
			generate(l,l+4,r,k-1);
			return;
		}
		//split one off
		generate(l,l+1,l+1,0);
		generate(l,l+2,r,k-1);
		return;
	}
	assert(k==2);
	if(B[n-2]){
		generate(l,l+1,l+3,0);
		generate(l,l+4,r,k-1);
	}else{
		generate(l,l+1,l+1,0);
		generate(l,l+2,r,k-1);
	}
}

int main(){
	int N,K;
	for(int k=0;k<18;++k){
		B[(1<<k)-1]++;
		spec.pb((1<<k)-1);
	}
	cin>>N>>K;
	if(N==1&&K==0){cout<<"YES\n";cout<<0<<'\n';return 0;}
	if(N==9&&K==2){cout<<"NO\n";return 0;}
	if(N%2==0){cout<<"NO";return 0;}
	if((K+1)*2>=N){cout<<"NO";return 0;}
	if(B[N]&&K==1){cout<<"NO";return 0;}
	if(!B[N]&&K==0){cout<<"NO";return 0;}
	cout<<"YES\n";
	generate(0,1,N,K);
	for(int i=1;i<=N;++i)cout<<A[i]<<' ';
}