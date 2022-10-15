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
const int MAXN=1010;
const int MAXK=18;
const int INF = 1e9;
const ll MOD = 998244353;

vi V[MAXN];
ll N,a,b,c,d,T,Q,M,x,y,z,u,v,w;
ll A[MAXN];
ll O[MAXN];
vpi res;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){cin>>A[i];O[i]=A[i];}
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			if(A[i]>A[j]){
				V[i].pb(j);
			}
		}
	}
	for(int i=0;i<N;++i){
		vpi tmp;
		// cerr<<SZ(V[i])<<'\n';
		for(auto t:V[i]){
			tmp.pb(O[t],t);
		}
		sort(ALL(tmp));
		reverse(ALL(tmp));
		for(auto x:tmp){
			res.pb(i,x.s);
			// cerr<<"Swap "<<i<<' '<<x.s<<'\n';
			swap(A[x.s],A[i]);
		}
		// for(int i=0;i<N;++i)cout<<A[i]<<' ';cout<<'\n';
	}
	// for(int i=0;i<N;++i)cout<<A[i]<<' ';cout<<'\n';
	cout<<SZ(res)<<'\n';
	for(auto i:res)cout<<i.f+1<<' '<<i.s+1<<'\n';
}