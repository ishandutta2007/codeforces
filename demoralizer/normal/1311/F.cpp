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

const int N=2e5+5;

int x[N];
int v[N];
pii inp[N];
set<int> comp;
map<int, int> coor;

#define SIZE   N
#define LSB(i) ((i) & -(i)) // zeroes all the bits except the least significant one

int A[SIZE];
int B[SIZE];

pii query(int i) // Returns the sum from index 1 to i
{
	int sum = 0,freq=0;
	while (i > 0) 
		sum += A[i], freq += B[i], i -= LSB(i);
	return {sum,freq};
}
void update(int i, int k) // Adds k to element with index i
{
	while (i < SIZE) 
		A[i] += k, B[i]++, i += LSB(i);
}

void solve(){
	int n;
	cin>>n;
	rep(i,0,n){
		cin>>x[i];
	}
	rep(i,0,n){
		cin>>v[i];
		inp[i].fr=x[i];
		inp[i].sc=v[i];
		comp.insert(v[i]);
	}
	int c=2;
	while(!comp.empty()){
		int x=*comp.begin();
		comp.erase(comp.begin());
		coor[x]=c++;
	}
	
	sort(inp,inp+n);
	
	rep(i,0,n){
		x[i]=inp[i].fr;
		v[i]=coor[inp[i].sc];
	}
	
	int ans=0;
	
	rep(i,0,n){
		pii k=query(v[i]);
		ans+=x[i]*k.sc-k.fr;
		update(v[i],x[i]);
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