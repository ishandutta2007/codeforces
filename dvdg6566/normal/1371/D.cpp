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
#define SZ(x) (int)x.size()
#define f first
#define s second
const int MAXN=500100;
const int MAXK=16;
const int INF = 1e9;
const ll MOD = 1e9+7;

ll N,a,b,c,d;

int main(){
	cin>>N;
	for(int i=0;i<N;++i){
		ll M,K;
		cin>>M>>K;
		vpi V;
		bool ans[301][301];
		for(int i=0;i<M;++i)for(int j=0;j<M;++j){
			ans[i][j]=0;
			V.pb(mp(i,j));
		}
		int lower=K/M;
		int lft=K%M;
		int l=0;
		if(lft==0)cout<<0<<'\n';
		else cout<<2<<'\n';
		for(int row=0;row<M;++row){
			if(lft){
				--lft;
				for(int k=0;k<lower+1;++k){
					ans[row][l]=1;
					++l;
					l%=M;
				}
			}else{
				for(int k=0;k<lower;++k){
					ans[row][l]=1;
					++l;
					l%=M;
				}
			}
		}
		for(int i=0;i<M;++i){
			for(int j=0;j<M;++j)cout<<ans[i][j];
			cout<<'\n';
		}
	}
}