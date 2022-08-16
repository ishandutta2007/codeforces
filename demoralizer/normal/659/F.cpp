#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1025;

 
int parent[N*N],size[N*N];
int findParent(int i)
{
    if(parent[parent[i]]!=parent[i])
        parent[i]=findParent(parent[i]);
    return parent[i];
}
void unionNodes(int a,int b)
{
    int parent_a=findParent(a),parent_b=findParent(b);
    if(parent_a==parent_b)
        return;
    if(size[parent_a]>=size[parent_b])
    {
         size[parent_a]+=size[parent_b];
         parent[parent_b]=parent_a;
    }
    else
    {
         size[parent_b]+=size[parent_a];
         parent[parent_a]=parent_b;
    }
    return;
}
void cleardsu(int n){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		size[i]=1;
	}
}

int n,m,k;
int a[N][N];
int b[N][N];
int cnt = 0;
int vis[N][N];

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

struct ms
{
	int v,x,y;
	operator int(){
		return -v;
	}
};

int hsh(int x,int y){
	return (1005*x+y);
}

void dfs(int x,int y,int v){
	if(vis[x][y])return;
	vis[x][y] = 1;
	if(a[x][y] >= v){
		b[x][y]=v;
		cnt++;
		if(cnt*v == k){
			rep(i,1,n+1){
				rep(j,1,m+1){
					cout<<b[i][j]<<" ";
				}
				cout<<"\n";
			}
			exit(0);
		}
	}
	else return;
	rep(i,0,4){
		dfs(x+dx[i],y+dy[i],v);
	}
}

void solve(){
	cin>>n>>m>>k;
	vector<ms> v;
	rep(i,1,n+1){
		rep(j,1,m+1){
			cin>>a[i][j];
			v.pb({a[i][j],i,j});
		}
	}
	cleardsu(N*N - 2);
	sort(all(v));
	for(auto x:v){
		rep(i,0,4){
			if(a[x.x][x.y] <= a[x.x+dx[i]][x.y+dy[i]]){
				unionNodes(hsh(x.x,x.y),hsh(x.x+dx[i],x.y+dy[i]));
			}
		}
		int p = findParent(hsh(x.x,x.y));
		if(size[p]*a[x.x][x.y] >= k && k%a[x.x][x.y] == 0){
			cout<<"YES\n";
			dfs(x.x,x.y,a[x.x][x.y]);
		}
	}
	cout<<"NO";
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}