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
const int MAXN = 60;
const int MAXL = 500100;

int dp[MAXL];
int B[MAXL];
int A[MAXN];
int N,D,T;
multiset<int> S;

int main(){
	cin>>N>>D;
	for (int i=1;i<=N;++i){cin>>A[i];T += A[i];}
	dp[0]=1;
	for (int i=1;i<=N;++i){
		for (int j=T;j>=A[i];--j){
			if (dp[j-A[i]])dp[j] = 1;
		}
	}
	for (int i=1;i<=T;++i)B[i] = 1e9;
	B[0] = 0;
	int tmax = 0;
	S.insert(0);
	for (int i=1;i<=T;++i){
		if (i - D - 1 >= 0)S.erase(S.find(B[i-D-1]));
		if (dp[i] == 1){
			// cout<<i<<'\n';
			B[i] = *S.begin();
			++B[i];
			if (B[i]<=T)tmax= max(tmax,i);
		}
		S.insert(B[i]);
	}
	cout<<tmax<<' '<<B[tmax];

}