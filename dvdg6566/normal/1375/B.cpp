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
const int MAXN=310;
const int MAXK=18;
const int INF = 1e9;
const ll MOD = 998244353;

vi V[MAXN];
ll N,a,b,c,d,T,Q,M,x,y,z,u,v,w;
ll A[MAXN][MAXN];
ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};
ll R,C;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>Q;
	while(Q--){
		cin>>R>>C;
		for(int i=0;i<R;++i)for(int j=0;j<C;++j)cin>>A[i][j];
		int fail=0;

		for(int i=0;i<R;++i)for(int j=0;j<C;++j){
			int x=0;
			for(int k=0;k<4;++k){
				int cx=i+dx[k];
				int cy=j+dy[k];
				if(cx<0||cy<0||cx>=R||cy>=C)continue;
				++x;
			}
			if (A[i][j]>x)fail=1;
		}
		if (fail)cout<<"NO\n";
		else{
			cout<<"YES\n";
			for(int i=0;i<R;++i)for(int j=0;j<C;++j){
				int x=0;
				for(int k=0;k<4;++k){
					int cx=i+dx[k];
					int cy=j+dy[k];
					if(cx<0||cy<0||cx>=R||cy>=C)continue;
					++x;
				}
				cout<<x<<' ';
				if(j+1==C)cout<<'\n';
			}
		}
	}
}