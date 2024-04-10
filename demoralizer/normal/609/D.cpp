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
#define disp(v)         for(auto x:v)cout<<x<<" ";
#define displn(v)         for(auto x:v)cout<<x<<"\n";

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=2e12;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=2e5+5;

int a[N],b[N];

struct gad
{
	int c,id;
	operator int() const{
		return c;
	}
};

void solve(){
	int n,m,k,s;
	cin>>n>>m>>k>>s;
	rep(i,0,n){
		cin>>a[i];
		if(i)amin(a[i],a[i-1]);
	}
	rep(i,0,n){
		cin>>b[i];
		if(i)amin(b[i],b[i-1]);
	}
	vector<gad> v[2];
	rep(i,0,m){
		int t,c;
		cin>>t>>c;
		v[t-1].pb({c,i+1});
	}
	sort(all(v[0]));
	sort(all(v[1]));
	int L=0,U=n;
	while(L<U){
		int m=(L+U)/2;
		int x=a[m],y=b[m];
		int i=0,j=0,c=0;
		rep(z,0,k){
			if(j==sz(v[1]) || (i<sz(v[0]) && x*v[0][i] < y*v[1][j])){
				c+=x*v[0][i++];
			}
			else{
				c+=y*v[1][j++];
			}
		}
		if(c<=s){
			U=m;
		}
		else{
			L=m+1;
		}
	}
	if(L==n){
		cout<<-1;
		return;
	}
	cout<<L+1<<"\n";
	int x,y,i=0,j=0;
	rep(i,0,L+1){
		if(a[i]==a[L]){
			x=i;
			break;
		}
	}
	rep(i,0,L+1){
		if(b[i]==b[L]){
			y=i;
			break;
		}
	}
	rep(z,0,k){
		if(j==sz(v[1]) || (i<sz(v[0]) && a[L]*v[0][i] < b[L]*v[1][j])){
			cout<<v[0][i++].id<<" "<<x+1<<"\n";
		}
		else{
			cout<<v[1][j++].id<<" "<<y+1<<"\n";
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}