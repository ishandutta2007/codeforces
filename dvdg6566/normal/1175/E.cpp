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
#define MAXL 500100
#define MAXLOG 20
ll INF = 1e9;

int A[MAXL];
int nxt[MAXL][MAXLOG];
int N,Q,a,b;

int main(){
	// freopen("in.txt","r",stdin);
	cin>>N>>Q;
	for (int i=1;i<=N;++i){
		cin>>a>>b;
		A[a] = max(A[a],b);
	}
	int l = 0;
	for (int i=0;i<=MAXL;++i){
		l = max(A[i], l);
		if (l <= i)nxt[i][0] = i;
		else nxt[i][0] = l;
	}
	
	for (int i=MAXL-1;i>=0;--i){
		for (int j=1;j<MAXLOG;++j){
			if (nxt[i][j-1] != -1)nxt[i][j] = nxt[nxt[i][j-1]][j-1];
		}
	}
	for (int i=0;i<Q;++i){
		cin>>a>>b;
		if (nxt[a][MAXLOG-1] < b){
			cout<<-1<<'\n';
		}else{
			int ans=0;
			for (int i=MAXLOG-1;i>=0;--i){
				if (nxt[a][i] < b){
					ans += (1<<i);
					a = nxt[a][i];
				}				
			}
			if (a < b)++ans;
			cout<<ans<<'\n';
		}
	}
}