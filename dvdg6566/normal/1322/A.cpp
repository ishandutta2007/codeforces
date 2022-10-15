#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 50100;
const ll INF = 1e9;

ll T,N,a,b,c,d,ans,M,E,K;
ll A[MAXN];
ll cnt;
string S;

int main(){
	cin>>N>>S;
	int curind = 0;
	while(curind < N){
		int below = 0;
		int l = curind;
		cnt = 0;
		while (curind < N){
			if (S[curind] == '(')++cnt;
			else --cnt;
			++curind;
			if (cnt<0)below = 1;
			if (cnt ==0)break;
		}
		if (cnt!=0){
			cout<<-1;
			return 0;
		}
		if (!below)continue;
		ans += (curind - l);
		// cout<<l<<' '<<curind<<'\n';
	}
	cout<<ans;
}