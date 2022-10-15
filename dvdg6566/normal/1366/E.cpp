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
const int MAXN=200110;
const ll MOD=998244353;

int N,T,M;
int A[MAXN];
int B[MAXN];
vi des;
int L[MAXN];
int R[MAXN];
int mid[MAXN];

int main(){
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		cin>>A[i];des.pb(A[i]);
	}
	sort(ALL(des));des.resize(unique(ALL(des))-des.begin());
	for(int i=1;i<=N;++i)A[i]=lb(ALL(des),A[i])-des.begin()+1;
	for(int i=1;i<=M;++i){
		cin>>B[i];
		int t=lb(ALL(des),B[i])-des.begin()+1;
		if(des[t-1] !=B[i]){
			cout<<0;
			return 0;
		}
		B[i]=t;
	}
	for(int i=1;i<=N;++i){
		L[A[i]]=i;
	}
	for(int i=1;i<=M;++i){
		mid[i]=L[B[i]];
	}
	memset(L,0,sizeof(L));
	for(int i=1;i<=M;++i){
		int m=mid[i];
		int l=mid[i];
		while(l>1){
			if(A[l-1]>=B[i])--l;
			else break;
		}
		int r=mid[i];
		while(r<N){
			if(r+1 == mid[i+1])break;
			if(A[r+1]<=B[i]){
				cout<<0;
				return 0;
			}
			++r;
		}
		L[i]=l;R[i]=r;
		// cout<<L[i]<<' '<<mid[i]<<' '<<R[i]<<'\n';
	}
	if(L[1]>1){
		cout<<0;return 0;
	}
	ll ans=1;
	for(int i=1;i<M;++i){
		if(R[i] < L[i+1]-1){
			cout<<0;return 0;
		}
		int ov=R[i]-L[i+1]+2;
		ans=(ans*(ll)ov)%MOD;
	}
	cout<<ans;
}