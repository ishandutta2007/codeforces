#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T>pair<T,T> operator+=(pair<T,T> &a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-=(pair<T,T> &a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T>pair<T,T> operator+(pair<T,T> a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-(pair<T,T> a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const int N=0;


int dp[1<<8];
int tmp[1<<8];
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	pii x[n];
	rep(i,0,n){
		cin>>x[i];
	}
	sort(x,x+n);
	map<int, vector<pii>> v;
	set<int> coor;
	rep(i,0,n){
		v[x[i].fr].pb({0,i});
		v[x[i].sc].pb({1,i});
		coor.insert(x[i].fr);
		coor.insert(x[i].sc);
	}
	
	deque<int> op;
	int prev=*coor.begin();
	for(int y:coor){
		for(int i=0;i<(1<<(sz(op)));i++){
			if(ppc(i)&1)dp[i]+=(y-prev);
		}
		sort(all(v[y]));
		for(pii z:v[y]){
			if(!z.fr){
				for(int i=(1<<sz(op))-1;i>=0;i--){
					dp[i<<1]=dp[i];
					if((ppc((i<<1)+1))%2){
						dp[(i<<1)+1]=dp[i] + 1;
					}
					else{
						dp[(i<<1)+1]=dp[i] - 1;
					}
				}
				op.pf(z.sc);
			}
			else{
				int idx;
				rep(i,0,sz(op)){
					if(op[i]==z.sc){
						idx=i;
						break;
					}
				}
				rep(i,idx,sz(op)-1){
					op[i]=op[i+1];
				}
				op.ppb();
				// int e=1<<idx;
				for(int i=0;i<(1<<(sz(op)));i++){
					// int f=i%e;
					// int g=i-f;
					// int h=(g<<1)+
					int f=((i>>idx)<<idx);
					int g=(i^f);
					int h=((f<<1)|g);
					int p=h,q=(h^(1<<idx));
					tmp[i]=max(dp[p],dp[q]);
				}
				for(int i=0;i<(1<<(sz(op)));i++){
					dp[i]=tmp[i];
				}
			}
		}
		// for(int d:op)cout<<d<<" ";cout<<"=="<<y<<"\n";
		// for(int i=0;i<(1<<(sz(op)));i++){
			// cout<<bitset<8>(i).to_string()<<" "<<dp[i]<<"\n";
			// dp[i];
		// }
		// cout<<"\n";
		prev=y;
	}
	cout<<dp[0];
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