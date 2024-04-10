#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end() 
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN=200100;
const ll MAXK=20;
const ll INF = 1e13;
const ll MOD = 1e9+7;

ll N,a,b,c,d,e,M,K,T;
ll A[MAXN], B[MAXN];
deque<int> dq;
vi tmp;
vi out;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		string S;
		cin>>N;
		cin>>S;
		dq.clear();
		for(auto i:S)dq.pb(i-'0');
		cin>>S;
		out.clear();
		for(auto i:S)out.pb(i-'0');
		tmp.clear();
		
		for(int i=1;i<=N;++i){
			tmp.pb(i);
			if(i*2!=N+1)tmp.pb(N+1-i);
			if(i*2>=N)break;
		}
		// for(auto i:tmp)cerr<<i<<' ';cerr<<'\n';
		vi res;
		int flp=0;
		int R=N;
		for(auto i:tmp){
			int tar=out.back();out.pop_back();
			int org=dq[i-1]^flp;
			if(org==tar)res.pb(1);
			res.pb(R);
			--R;
			flp^=1;
		}
		cout<<SZ(res)<<' ';for(auto i:res)cout<<i<<' ';
		cout<<'\n';
		// cerr<<N<<'\n';
		// for(auto t:tmp)cerr<<t<<' ';cerr<<'\n';
	}
}