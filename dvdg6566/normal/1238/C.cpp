#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 1010000
#define MAXL 18
	
int dp[MAXN];
 
int N,H,Q,a;
vi V;
 
int main(){
	cin>>Q;
	while(Q--){
		V.clear();
		cin>>H>>N;
		for (int i=1;i<=N;++i){cin>>a;V.pb(a);}
		int ans=0;
		V.pb(0);
		int lst = H;
		for (int i=0;i<N;++i){
			// cout<<V[i]<<' '<<lst<<'\n';
			if (lst == V[i] + 1){
				// If next is ok
				if (V[i+1] == V[i] - 1){
					lst = V[i+1];
					continue;
				}else{
					lst = V[i+1]+1;
					++ans;
				}
			}else{
				lst = V[i+1] + 1;
			}
		}
		cout<<ans<<'\n';
	}
}