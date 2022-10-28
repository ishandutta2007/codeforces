// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


const int N = 1e3+5;

vector<int>g[N];

int par[N];

int d[N];

int vis[N];

int reqd;

void dfs(int u,int v){
	for(auto i:g[u]){
		if(i!=v){
			d[i] = d[u] + 1;
			par[i] = u;
			dfs(i,u);
		}
	}
}

vector<int>t;
void dfs2(int u){
	reqd--;
	t.push_back(u);
	if(reqd == 0){
		return;
	}
	vis[u] = 1;
	for(auto i:g[u]){
		if(!vis[i]){
			dfs2(i);
			t.push_back(u);
			if(reqd == 0)return;
		}
	}
}

int solve(){
 		int n; cin >> n;
 		vector<int>a(2*n+1),b(2*n+1);
 		rep(i,1,2*n+1){
 			cin >> a[i];
 			b[i] = a[i];
 		}
 		auto check = [&](){
 			rep(i,1,2*n+1){
 				if(a[i] != i){
 					return 0;
 				}
 			}
 			return 1;
 		};
 		auto op1 = [&](){
 			for(int i = 1; i <= 2*n; i+=2){
 				swap(a[i],a[i+1]);
 			}
 		};
 		auto op2 = [&](){
 			for(int i = 1; i <= n; i++){
 				swap(a[i],a[i+n]);
 			}
 		};
 		int k = 2*n;
 		int mn = hell;
 		bool f = 0;
 		int cnt = 0;
 		while(k--){
 			if(check()){
 				mins(mn,cnt);
 				break;
 			}
 			if(f == 0){
 				op1();
 			}
 			else{
 				op2();
 			}
 			cnt++;
 			f ^= 1;
 		}
 		k = 2*n;
 		f = 1;
 		a = b;
 		cnt=0;
 		while(k--){
 			if(check()){
 				mins(mn,cnt);
 				break;
 			}
 			if(f == 0){
 				op1();
 			}
 			else{
 				op2();
 			}
 			f ^= 1;
 			cnt++;
 		}
 		if(mn == hell){
 			cout << -1 << endl;
 		}
 		else{
 			cout << mn << endl;
 		}
 		return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}