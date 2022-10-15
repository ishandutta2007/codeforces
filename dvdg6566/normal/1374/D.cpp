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
const int MAXN=7;
const int MAXK=18;
const int INF = 1e9;
const ll MOD = 1e9+7;

ll N,R,K,a,b,c;
vi A,B,C;
map<int,int> M;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>R;
	while(R--){
		M.clear();

		cin>>N>>K;for(int i=0;i<N;++i){
			cin>>a;
			M[a%K]++;
		}
		pi worst=mp(-1,-1);
		for(auto i:M){
			int occ=i.s;
			int need=(K-i.f)%K;
			if(need==0)continue;
			worst=max(worst,mp(occ,need));
			// cout<<need<<' '<<occ<<'\n';
			// if(occ>worst.f)worst=mp(occ,need);
		}
		cout<<max((worst.f-1)*K+worst.s+1,0LL)<<'\n';
	}
}