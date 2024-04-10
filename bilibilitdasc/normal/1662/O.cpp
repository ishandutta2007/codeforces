#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sz(a) ((int)a.size())
#define re return
#define all(a) a.begin(),a.end()
#define int long long
#define rept(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) rept(i,0,a)
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int MOD=1000000007,INF=1000000000000000000;
template<typename T>inline void Mx(T &a,T b){a=max(a,b);}
template<typename T>inline void Mi(T &a,T b){a=min(a,b);}
inline int ad(int &a,int b,int c=MOD){re a=(a+b)%c;}
template<typename T>inline T read(){T a;cin>>a;re a;}
inline bool is_digit(int msk,int d){re (msk>>d)&1;}
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int ok[25][360];
set<pii>edge[25][360];
void dfs(int i,int j){
	ok[i][j]=1;
	for(pii k:edge[i][j])if(!ok[k.F][k.S]){
		dfs(k.F,k.S);
	}
}
void run(){
	rep(i,23)rep(j,360)edge[i][j].clear(),ok[i][j]=0;
	rep(i,20)rep(j,360){
		edge[i][j].insert({i+1,j});
		edge[i+1][j].insert({i,j});
	}
	rep(i,21){
		edge[i][0].insert({i,359});
		edge[i][359].insert({i,0});
		rep(j,359){
			edge[i][j].insert({i,j+1});
			edge[i][j+1].insert({i,j});
		}
	}
	int n;
	cin>>n;
	rep(_,n){
		string s;
		int a,b,c;
		cin>>s>>a>>b>>c;
		if(s=="C"){
			if(b<=c){
				rept(i,b,c){
					edge[a][i].erase({a-1,i});
					edge[a-1][i].erase({a,i});
				}
			}
			else{
				rept(i,b,360){
					edge[a][i].erase({a-1,i});
					edge[a-1][i].erase({a,i});
				}
				rep(i,c){
					edge[a][i].erase({a-1,i});
					edge[a-1][i].erase({a,i});
				}
			}
		}
		else{
			rept(i,a,b){
				edge[i][c].erase({i,(c+359)%360});
				edge[i][(c+359)%360].erase({i,c});
			}
		}
	}
	dfs(0,0);
	if(ok[20][0])cout<<"YES\n";
	else cout<<"NO\n";
}
signed main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	for(int tc=read<int>();tc;tc--)
		run();
	re 0;
}