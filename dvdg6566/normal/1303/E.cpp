#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
#define lb lower_bound
#define ub upper_bound
const ll MAXN=410;
const int INF=1e9;
// segment tree over prefix ranges
int T;
string AA,BB;
int memo[2][MAXN][MAXN];

int ask(int i,int l,int r,int index){	
	int ans=-1e9;
	ans=max(ans,memo[i^1][l][r]);
	if(AA[index]==BB[l]){
		ans=max(ans,memo[i^1][l+1][r]);
	}
	if(AA[index]==BB[r]){
		ans=max(ans,memo[i^1][l][r+1]);
	}
	return memo[i][l][r]=ans;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>AA>>BB;
		for(int i=0;i<2;++i)for(int j=0;j<=SZ(BB);++j)for(int k=0;k<=SZ(BB);++k)memo[i][j][k]=-1;
		int ind=1;

		// for index i=SZ(AA)
		for(int l=0;l<=SZ(BB);++l)for(int r=0;r<=SZ(BB);++r){
			if(r==SZ(BB))memo[1][l][r]=l;
			else memo[1][l][r]=-1;
		}

		for(int i=SZ(AA)-1;i>=0;--i){
			ind^=1;
			for(int l=0;l<=SZ(BB);++l)for(int r=0;r<=SZ(BB);++r)ask(ind,l,r,i);
		}


		int ans=0;
		for(int div=0;div<SZ(BB);++div){
			int x=memo[ind][0][div];
			// cerr<<"Start "<<0<<' '<<div<<' '<<x<<'\n';
			if(x>=div)ans=1;
		}
		if(ans)cout<<"YES\n";
		else cout<<"NO\n";
	}
}