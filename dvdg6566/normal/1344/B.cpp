#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define emp emplace
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 1010;
const int INF = 1e9;
const ll MOD = 1e9+7;
const int H = 500;

ll N,L,ans,D,M,a,b;
ll A[MAXN][MAXN],B[MAXN][MAXN];
ll R,C;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void dfs(int x, int y){
	B[x][y]=1;
	for(int k=0;k<4;++k){
		int cx=x+dx[k];
		int cy=y+dy[k];
		if(cx<0||cy<0||cx>=R||cy>=C)continue;
		if(A[cx][cy]==0||B[cx][cy]==1)continue;
		dfs(cx,cy);
	}
}

int main(){
	// freopen("movie.in","r",stdin);
	// freopen("movie.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>R>>C;
	for(int i=0;i<R;++i){
		string S;cin>>S;
		for(int j=0;j<C;++j){
			if(S[j]=='#')A[i][j]=1;
			else A[i][j]=0;
		}
	}
	int alcol=1;
	int alrow=1;
	for(int i=0;i<R;++i){
		int st=0;
		for(int j=0;j<C;++j){
			if(A[i][j]==0&&st==1)st=2;
			else if(A[i][j]==1){
				if(st==0)st=1;
				if(st==2){
					cout<<-1;
					return 0;
				}
			}
		}
		if(st==0)alrow=0;
	}
	for(int j=0;j<C;++j){
		int st=0;
		for(int i=0;i<R;++i){
			if(A[i][j]==0&&st==1)st=2;
			else if(A[i][j]==1){
				if(st==0)st=1;
				if(st==2){
					cout<<-1;
					return 0;
				}
			}
		}
		if(st==0)alcol=0;
	}
	if(alcol!=alrow){
		cout<<-1;return 0;
	}
	int h=0;
	for(int i=0;i<R;++i)for(int j=0;j<C;++j){
		if(A[i][j]&&!B[i][j]){dfs(i,j);++h;}
	}
	cout<<h;
}