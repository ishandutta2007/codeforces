#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define MAXN 210000
#define MAXL 18

int T,R,C;
int A[15][3000];
vpi V;
int B[15][15];

int E[15];

int main(){
	cin>>T;
	while(T--){
		V.clear();
		cin>>R>>C;
		E[0] = 1;
		for (int i=1;i<=5;++i)E[i] = E[i-1] * R;
		for (int i=0;i<R;++i){
			for (int j=0;j<C;++j){
				cin>>A[i][j];
			}
		}
		for (int j=0;j<C;++j){
			int mv = 0;
			for (int i=0;i<R;++i)mv = max(mv, A[i][j]);
			V.pb(mv,j);
		}

		sort(ALL(V));
		reverse(ALL(V));

		for (int i=0;i<R && i < C;++i){
			int col = V[i].s;
			for (int j=0;j<R;++j){
				B[i][j] = A[j][col];
				// cout<<B[i][j]<<' ';
			}
			// cout<<'\n';
		}

		C = min(C,R);
		
		// Power is number of rows to the power of number of col
		int T = E[C];
		int res= 0 ;
		for (int bm=0;bm<T;++bm){
			int ans[5];
			memset(ans,0,sizeof(ans));
			for (int i=0;i<C;++i){
				int startind = (bm % E[i+1]) / E[i];
				// cout<<startind<<'\n';
				for (int j=0;j<R;++j){
					int ind = (startind + j)%R;
					ans[ind]  =max(ans[ind], B[i][j]);
					// cout<<B[i][j]<<' ';
				}
				// cout<<'\n';
			}
			int t = 0;
			for (int i=0;i<R;++i)t += ans[i];
			res = max(res,t);
		}
		cout<<res<<'\n';
	}
}