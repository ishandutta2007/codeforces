#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int solve(){
 	int n,m;cin>>n>>m;
 	vector<int>a(n+1),b(m+1);
 	int v1=0,v2=0;
 	rep(i,1,n+1)cin>>a[i],v1^=a[i];
 	rep(i,1,m+1)cin>>b[i],v2^=b[i];
 	vector<vector<int>>vec(n+1,vector<int>(m+1));
 	if(v1!=v2){
 		cout<<"NO"<<endl;return 0;
 	}
 	for(int j=29;j>=0;j--){
 		set<int>x,y;
 		set<int>s1,s2;
 		int val=(1LL<<j);
 		for(int i=1;i<=n;i++){
 			if(a[i]&val){
 				x.insert(i);
 			}
 		}
 		for(int i=1;i<=m;i++){
 			if(b[i]&val){
 				y.insert(i);
 			}
 		}
 		while(!x.empty() && !y.empty()){
 			int r=*x.begin();
 			int c=*y.begin();
 			x.erase(r);y.erase(c);
                        vec[r][c]|=val;
 		}
 		if(sz(y)%2 || sz(x)%2){
 			cout<<"NO"<<endl;return 0;
 		}
 		if(sz(y)){
 		     while(!y.empty()){	
 			int y1=*y.begin();
 			y.erase(y1);
 			int y2=*y.begin();
 			y.erase(y2);
 			for(int i=1;i<=n;i++){
 				if(((val&vec[i][y1])==0) && ((val&vec[i][y2])==0)){
 					vec[i][y1]|=(val);
 					vec[i][y2]|=(val);
 					break;
 				}
 			}
 		     }	
 		}
 		if(sz(x)){
 		    while(!x.empty()){	
 			int x1=*x.begin();
 			x.erase(x1);
 			int x2=*x.begin();
 			x.erase(x2);
 			for(int i=1;i<=m;i++){
 				if(((val&vec[x1][i])==0) && ((val&vec[x2][i])==0)){
 					vec[x1][i]|=(val);
 					vec[x2][i]|=(val);
 					break;
 				}
 			}
 		     }	
 		}
 	}
 	cout<<"YES"<<endl;
 	rep(i,1,n+1){
 		rep(j,1,m+1)cout<<vec[i][j]<<" ";cout<<endl;
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