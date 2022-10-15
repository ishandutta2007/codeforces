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
const ll MAXN = 210000;
const ll MAXK = 17;
const ll INF = 1e18;
const ll MOD = 1e9+7;

ll N,E,a,b,c,T;
vi V[MAXN];
ll H[MAXN];
ll A[MAXN];

int main(){
	cin>>T;
	while(T--){
		cin>>N>>E;
		for(int i=1;i<=N;++i){
			V[i].clear();
			H[i]=0;
			A[i]=0;
		}
		for (int i=0;i<E;++i){
			cin>>a>>b;
			V[a].pb(b);
		}
		for (int i=1;i<=N;++i)sort(ALL(V[i]));
		for (int i=1;i<=N;++i){
			if(H[i]==0){
				A[i]=1;
				for (auto t:V[i])H[t]=max(H[t],1LL);
				continue;
			}
			else if(H[i] == 1){
				A[i]=1;
				for (auto t:V[i])H[t]=2;
				continue;
			}else{
				A[i]=0;
			}
		}
		vi out;
		for (int i=1;i<=N;++i)if(A[i] == 0){
			out.pb(i);
		}
		cout<<SZ(out)<<'\n';
		for (auto t:out)cout<<t<<' ';cout<<'\n';
	}
}