
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
const int INF = 1e9;
const ll MOD = 998244353;
 
vi V[MAXN];
ll N,a,b,c,d,T,Q,M,x,y,z,u,v,w;
ll A[MAXN];
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>Q;
	while(Q--){
		cin>>N;
		vi V;
		set<int> leftovers;
		for(int i=1;i<=N;++i){
			cin>>a;
			V.pb(a);
			leftovers.insert(i);
		}
 
		while(SZ(V)>1){
			// for (auto i:leftovers)cout<<i<<' ';cout<<'\n';
			int low=0;
			for (int i=SZ(V)-1;i>=0;--i){
				if(V[i] == *(leftovers.begin())){low=i;break;}
			}
			if(V[low]==V.back())break;
			int t=V.back();V.pop_back();
			while(V.back()!=V[low]){
				leftovers.erase(V.back());
				V.pop_back();
			}
			leftovers.erase(V.back());
			V.pop_back();
			V.pb(t);
		}
		if(SZ(V)>1)cout<<"NO\n";
		else cout<<"YES\n";
	}
}