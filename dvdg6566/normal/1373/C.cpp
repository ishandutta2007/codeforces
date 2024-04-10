
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
	cin>>T;
	while(T--){
		string S;
		cin>>S;
		ll ans=0;
		ll sum=0;
		ll low=0;
		ll ind=0;
		for(auto i:S){
			++ind;
			if(i=='+')++sum;
			else{
				--sum;
				if(sum<low){
					// cerr<<"Adding at "<<sum<<' '<<ind<<'\n';
					ans+=ind;
					--low;
				}
			}
		}
		cout<<ans+SZ(S)<<'\n';
	}
}