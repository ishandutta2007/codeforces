#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
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
const ll MAXN = 1010;
const ll MAXK = 17;
const ll INF = 1e18;
const ll MOD = 1e9+7;

string S;
int zeroes[MAXN];
int ones[MAXN];

int main(){
	ll N,T;
	cin>>T;
	while(T--){
		cin>>S;
		memset(zeroes,0,sizeof(zeroes));
		memset(ones,0,sizeof(ones));
		N=SZ(S);
		for (int i=1;i<=N;++i){
			zeroes[i]=zeroes[i-1];
			ones[i]=ones[i-1];
			if (S[i-1]=='0')++zeroes[i];
			else ++ones[i];
		}
		int ans=0;
		for (int i=1;i<=N+1;++i){
			int a=zeroes[i-1]+ones[N]-ones[i-1];
			ans=max(ans,a);
			int b=ones[i-1]+zeroes[N]-zeroes[i-1];
			ans=max(ans,b);
		}
		cout<<N-ans<<'\n';
	}
}