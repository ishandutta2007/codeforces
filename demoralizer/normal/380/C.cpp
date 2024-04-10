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
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1e6+5;

int p[N];

struct query{
	int l,r,id;
	query(int l,int r,int id):l(l),r(r),id(id){}
};

vector<query> q[N];

#define SIZE   N
#define LSB(i) ((i) & -(i)) // zeroes all the bits except the least significant one

int A[SIZE];

int query(int i) // Returns the sum from index 1 to i
{
	int sum = 0;
	while (i > 0) 
		sum += A[i], i -= LSB(i);
	return sum;
}
void update(int i, int k) // Adds k to element with index i
{
	if(i<1)return;
	while (i < SIZE) 
		A[i] += k, i += LSB(i);
}

int ans[N/10 +5];

void solve(){
	string t;
	stack<int> s;
	int n,m;
	cin>>t>>m;
	n=sz(t);
	
	rep(i,0,n){
		if(t[i]=='('){
			s.push(i+1);
		}
		else{
			if(!s.empty()){
				p[i+1]=s.top();
				s.pop();
			}
		}
	}
	
	rep(i,0,m){
		int x,y;
		cin>>x>>y;
		q[y].pb({x,y,i});
	}
	
	rep(i,1,n+1){
		update(p[i],1);
		for(auto x:q[i]){
			ans[x.id] = query(n+1) - query(x.l-1);
		}
	}
	
	rep(i,0,m){
		cout<<ans[i]*2<<"\n";
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