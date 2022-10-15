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
#define ub upper_bound
const int MAXN=500100;

ll A[MAXN];
ll N,M,K,Q,a,b,c,d;
ll B[MAXN];

ll T;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>N>>K;
		string S;cin>>S;
		int fail=0;
		for(int i=K;i<N;++i){
			if(S[i]==S[i%K])continue;
			if(S[i]=='?')continue;
			if(S[i%K]=='?'){
				S[i%K]=S[i];
				continue;
			}
			fail=1;
		}
		int o=0;
		int z=0;
		for(int i=0;i<K;++i){
			if(S[i]=='?')continue;
			if(S[i]=='1')++o;
			else ++z;
		}
		if(o>K/2||z>K/2)fail=1;
		
		if(!fail)cout<<"YES\n";
		else cout<<"NO\n";
	}
}