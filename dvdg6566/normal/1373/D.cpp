
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
 
vi V[MAXN];
ll N,a,b,c,d,T,Q,M,x,y,z,u,v,w;
ll A[MAXN];
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		a=0;
		for(int i=1;i<=N;++i){
			cin>>A[i];
			if((i%2)){
				a+=A[i];
				A[i]=-A[i];
			}
		}
		b=0;
		ll largodd=-INF;
		ll largeven=-INF;
		// for(int i=1;i<=N;++i)cout<<A[i]<<' ';cout<<'\n';
		for(int i=1;i<=N;++i)A[i]+=A[i-1];
		for(int i=N;i>=0;--i){
			if(i%2==1){
				b=max(b,largodd-A[i]);
				largodd=max(largodd, A[i]);
			}else{
				b=max(b,largeven-A[i]);
				largeven=max(largeven,A[i]);
			}
			// cerr<<i<<' '<<b<<'\n';
		}
		cout<<a+b<<'\n';
	}
}