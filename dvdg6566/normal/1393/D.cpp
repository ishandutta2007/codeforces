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
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define lb lower_bound
const int MAXN=2010;
const ll MOD=998244353;

int N,T,M;

int A[MAXN][MAXN];
int D[MAXN][MAXN];

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
string S;
queue<pi> Q;

int main(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>S;
		for(int j=0;j<M;++j){
			A[i][j]=S[j]-'a';
		}
	}
	for(int i=0;i<N;++i)for(int j=0;j<M;++j){
		for(int k=0;k<4;++k){
			int cx=i+dx[k];
			int cy=j+dy[k];
			if(cx<0||cy<0|cx>=N||cy>=M){
				if(D[i][j]==0)Q.push(mp(i,j));
				D[i][j]=1;
				continue;
			}
			if(A[i][j]!=A[cx][cy]){
				if(D[i][j]==0)Q.push(mp(i,j));
				D[i][j]=1;
			}
		}
	}
	ll ans=0;
	while(SZ(Q)){
		int x=Q.front().f;
		int y=Q.front().s;
		Q.pop();
		// cerr<<D[x][y]<<'\n';
		ans+=D[x][y];
		for(int k=0;k<4;++k){
			int cx=dx[k]+x;
			int cy=dy[k]+y;
			if(cx<0||cy<0|cx>=N||cy>=M)continue;
			if(D[cx][cy])continue;
			D[cx][cy]=D[x][y]+1;
			Q.push(mp(cx,cy));
		}
	}
	cout<<ans;
}