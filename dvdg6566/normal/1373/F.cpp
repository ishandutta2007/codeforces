#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
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
const int MAXN=310000;
const int MAXK=18;
const ll INF = 1e15;
const ll MOD = 998244353;

ll Q,N,a,b;
vi A,B;

ll run(ll fst){
	ll spill=0;
	ll over=0;
	over=B[0]-fst;
	if(over<0)return -1;
	for(int i=1;i<N;++i){
		// cout<<over<<'\n';
		ll b=A[i]-over;
		// cout<<b<<'\n';
		if(b<0){
			spill+=abs(b);
			b=0;
		}
		if(b>B[i]){
			return -1;
		}
		over=B[i]-b;
	}
	return spill;
}

ll res=0;
void ask(){
	ll lower=0;
	ll upper=min(A[0],B[0]);
	while(upper>lower){
		ll m=(lower+upper)/2;
		ll h=run(m);
		// cout<<"Ask "<<m<<' '<<h<<'\n';
		if(h!=-1&&h<=res){
			cout<<"YES\n";
			return;
		}
		if (h == -1){
			upper=m-1;
		}else{
			lower=m+1;
		}
	}
	ll h=run(lower);
	if(h!=-1&&h<=res){
		cout<<"YES\n";
		return;
	}
	cout<<"NO\n";
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>Q;
	while(Q--){
		cin>>N;
		A.clear();B.clear();
		for(int i=1;i<=N;++i){cin>>a;A.pb(a);}
		for(int i=1;i<=N;++i){cin>>a;B.pb(a);}
		res=0;
		for(auto i:B)res+=i;
		for(auto i:A)res-=i;

		ask();
		// return 0;
	}
}