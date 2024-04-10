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

int t[N];

void solve(){
	int n;
	cin>>n;
	set<int> s;
	rep(i,0,n){
		cin>>t[i];
		s.insert(t[i]);
	}
	if(sz(s)==1){
		cout<<"1\n";
		rep(i,0,n)cout<<"1 ";
		return;
	}
	
	if(n%2==0 || t[0]==t[n-1]){
		cout<<"2\n";
		rep(i,0,n){
			cout<<i%2+1<<" ";
		}
		return;
	}
	
	bool chk=0;
	rep(i,0,n-1){
		if(t[i]==t[i+1])chk=1;
	}
	if(chk){
		cout<<"2\n1 ";
		int c=1;
		rep(i,1,n){
			if(chk && t[i]==t[i-1]){
				c++;
				chk=0;
			}
			cout<<c%2 +1<<" ";
			c++;
		}
		return;
	}
	cout<<"3\n3 ";
	rep(i,1,n){
		cout<<i%2+1<<" ";
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
	cin>>t;
	while(t--) solve(),cout<<"\n";
	return 0;
}