#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define emp emplace
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 510;
const ll INF = 1e18;
const ll MOD = 1e9+7;
const ll H = 500;

int A[MAXN][MAXN];
int N,a,b,c,d;

int main(){
	cin>>N;
	while(N--){
		cin>>a>>b>>c>>d;
		if(d*b!=a*c){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		int cur=0;
		for(int i=0;i<a;++i)for(int j=0;j<b;++j)A[i][j]=0;
		for(int i=0;i<a;++i){
			for (int k=0;k<c;++k){
				A[i][cur]=1;
				++cur;
				if(cur==b)cur=0;
			}
		}
		for(int i=0;i<a;++i){
			for(int j=0;j<b;++j)cout<<A[i][j];
			cout<<'\n';
		}
	}
}