#include <bits/stdc++.h>
using namespace std;
// #define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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
const int32_t MM=998244353;

const int N=1005;

struct ps{
	int n,m;
	int a[N][N];
	int arr[N][N];
	int M[N][N][11][11];
	int log[N];

	int* operator[] (int x){
		return a[x];
	}
	void build(){
		cin>>n>>m;
		rep(i,1,n+1){
			rep(j,1,m+1){
				cin>>a[i][j];
			}
		}
		rep(i,1,n+1){
			rep(j,1,1+m){
				a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			}
		}
		
		rep(i,1,n+1){
			rep(j,1,m+1){
				int L=0,U=min(n+1-i,m+1-j);
				while(L<=U){
					int m=(L+U)/2;
					if(check(i,j,m)){
						arr[i][j]=m;
						L=m+1;
					}
					else{
						U=m-1;
					}
				}
			}
		}
		
		n++,m++;
		int i,j,x,y;
		for(i=0;(1<<i)<=n;i++)
		{
			for(j=0;(1<<j)<=m;j++)
			{
				for(x=0; (x+(1<<i)-1)<n; x++)
				{
					for(y=0; (y+(1<<j)-1)<m; y++)
					{
						if(i==0 && j==0)
							M[x][y][i][j]=arr[x][y];
						else
							if(i==0)
								M[x][y][i][j] = max(M[x][y][i][j-1],M[x][y+(1<<(j-1))][i][j-1]);
							else
								if(j==0)
									M[x][y][i][j]=max(M[x][y][i-1][j],M[x+(1<<(i-1))][y][i-1][j]);
								else
								{
									int tempa = max(M[x+(1<<(i-1))][y][i-1][j-1],M[x][y+(1<<(j-1))][i-1][j-1]);
									int tempb = max(M[x][y][i-1][j-1],M[x+(1<<(i-1))][y+(1<<(j-1))][i-1][j-1]);
									M[x][y][i][j]=max(tempa,tempb);
								}
					}
				}
			}
		}
		log[1]=0;
		rep(i,2,N){
			log[i]=log[i/2]+1;
		}
		n--,m--;
	}
	bool check(int x1,int y1,int s){
		return ((a[x1+s-1][y1+s-1]+a[x1-1][y1-1]-a[x1+s-1][y1-1]-a[x1-1][y1+s-1]) == (s*s));
	}
	
	int query(int x,int y,int x1,int y1){
		int k = log[x1 - x + 1];
		int l = log[y1 - y + 1];
		int tempa = max(M[x][y][k][l], M[x1 - (1<<k) + 1][y][k][l]);
		int tempb =  max(M[x][y1 - (1<<l) + 1][k][l], M[x1 - (1<<k) + 1][y1 - (1<<l) + 1][k][l]);
		return max(tempa,tempb);
	}
	
	bool operator() (int x1,int y1,int x2,int y2,int s){
		return (query(x1,y1,x2+1-s,y2+1-s) >= s);
	}
	
}a;

void solve(){
	a.build();
	
	int q;
	cin>>q;
	rep(i,0,q){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		int L=0,U=min(x2-x1,y2-y1)+1;
		int ans=0;
		while(L<=U){
			int m=(L+U)/2;
			if(a(x1,y1,x2,y2,m)){
				ans=m;
				L=m+1;
			}
			else{
				U=m-1;
			}
		}
		cout<<ans<<"\n";
	}
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