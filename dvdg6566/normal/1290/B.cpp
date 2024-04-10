#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb emplace_back
#define mp make_pair
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define lb lower_bound
#define up upper_bound

ll MOD = 1e9+7;
#define MAXN 200100

ll N,a,b,c,d,e,f,T,M,K;
int A[MAXN][26];
vi V;
vi cur;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	string S;
	cin>>S>>N;
	for (int i=1;i<=SZ(S);++i){
		int t = S[i-1]-'a';
		A[i][t]++;
	}
	for (int i=0;i<26;++i){
		for (int j=1;j<=SZ(S);++j){
			A[j][i] += A[j-1][i];
			// cout<<A[j][i]<<' ';
		}
		// cout<<'\n';
	}
	while (N--){
		int l,r;
		cin>>l>>r;
		if (l == r){
			cout<<"YES\n";
			continue;
		}
		ll b = 0;

		for (int i=0;i<26;++i){
			if (A[r][i] - A[l-1][i] > 0){++b;}
		}
		
		if (b == 1){
			cout<<"NO\n";
		}
		else if (b == 2 && S[l-1] == S[r-1]){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
		}
	}
}