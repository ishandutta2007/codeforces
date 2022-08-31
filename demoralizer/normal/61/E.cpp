#include <bits/stdc++.h>
using namespace std;
#define int               long long
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

#define SIZE   N
#define LSB(i) ((i) & -(i)) // zeroes all the bits except the least significant one

struct fenwick
{	
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
		while (i < SIZE) 
			A[i] += k, i += LSB(i);
	}
}u,v;

int a[N];

void solve(){
	int n;
	cin>>n;
	set<int> coor;
	map<int, int> cocom;
	rep(i,0,n){
		cin>>a[i];
		coor.insert(a[i]);
	}
	int cnt=1;
	for(int x:coor){
		cocom[x]=cnt++;
	}
	rep(i,0,n){
		a[i]=cocom[a[i]];
	}
	reverse(a,a+n);
	int ans=0;
	rep(i,0,n){
		ans+=v.query(a[i]);
		v.update(a[i],u.query(a[i]));
		u.update(a[i],1);
	}
	cout<<ans;
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