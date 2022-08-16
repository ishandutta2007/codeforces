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

template<typename T1,typename T2>
std::istream& operator>>(std::istream& in,pair<T1,T2> &a)
{
	in>>a.fr>>a.sc;
	return in;
}
template<typename T1,typename T2>
std::ostream& operator<<(std::ostream& out,pair<T1,T2> &a)
{
	out<<a.fr<<" "<<a.sc;
	return out;
}

const int N=1e5+5;

int p[N];

void solve(){
	int n,m;
	cin>>n>>m;
	int tm=m;
	vector<int> v[4];
	rep(i,0,n){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
	}
	v[3].resize(N);
	rep(i,1,4)sort(all(v[i]),greater<int>());
	
	rep(i,1,N){
		p[i]=p[i-1]+v[3][i-1];
	}
	int a=0,b=0,ans=0,t=0;
	ans=max(ans,t+p[m/3]);
	while((a<sz(v[1]) || b<sz(v[2])) && m>=0){
		ans=max(ans,t+p[m/3]);
		if(m<1)break;
		if(b<sz(v[2]) && a+1<sz(v[1])){
			if(v[1][a]+v[1][a+1]>v[2][b]){
				t+=v[1][a]+v[1][a+1];
				a+=2;
				m-=2;
			}
			else{
				t+=v[2][b];
				b++;
				m-=2;
			}
		}
		else if(b<sz(v[2])){
			t+=v[2][b];
			b++;
			m-=2;
		}
		else if(a+1<sz(v[1])){
			t+=v[1][a]+v[1][a+1];
			a+=2;
			m-=2;
		}
		else break;
	}
	if(m>=0)ans=max(ans,t+p[m/3]);
	if(sz(v[1])){
		m=tm-1;
		a=1;
		b=0;
		t=v[1][0];
		ans=max(ans,t+p[m/3]);
		while((a<sz(v[1]) || b<sz(v[2])) && m>=0){
			ans=max(ans,t+p[m/3]);
			if(m<1)break;
			if(b<sz(v[2]) && a+1<sz(v[1])){
				if(v[1][a]+v[1][a+1]>v[2][b]){
					t+=v[1][a]+v[1][a+1];
					a+=2;
					m-=2;
				}
				else{
					t+=v[2][b];
					b++;
					m-=2;
				}
			}
			else if(b<sz(v[2])){
				t+=v[2][b];
				b++;
				m-=2;
			}
			else if(a+1<sz(v[1])){
				t+=v[1][a]+v[1][a+1];
				a+=2;
				m-=2;
			}
			else break;
		}
		if(m>=0)ans=max(ans,t+p[m/3]);
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
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}