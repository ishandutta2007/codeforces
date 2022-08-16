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

const int N=1<<21;

vector<int> v[N];
int a[N],g,h;
int ptr[N];
int ans[N];

void solve(){
	long long s=0;
	cin>>h>>g;
	int L=(1<<g)-1;
	int U=(1<<h)-1;
	rep(i,1,(1<<h)){
		cin>>a[i];
		ptr[i]=0;
		// v[i].clear();
	}
	for(int i=(1<<h)-1;i>0;i--){
		v[i].pb(a[i]);
		if(2*i>U){
			continue;
		}
		int x=2*i,y=2*i+1;
		if(2*i>L){
			while(ptr[x]<sz(v[x]) && ptr[y]<sz(v[y])){
				if(v[x][ptr[x]] > v[y][ptr[y]]){
					v[i].pb(v[x][ptr[x]]);
					ptr[x]++;
				}
				else{
					v[i].pb(v[y][ptr[y]]);
					ptr[y]++;
				}
			}
			while(ptr[x]<sz(v[x])){
				v[i].pb(v[x][ptr[x]]);
				ptr[x]++;
			}
			while(ptr[y]<sz(v[y])){
				v[i].pb(v[y][ptr[y]]);
				ptr[y]++;
			}
		}
		else{
			// while(sz(v[x])>1 && sz(v[y])>1){
			// 	if(v[x].front() > v[y].front()){
			// 		v[i].push(v[x].front());
			// 	}
			// 	else{
			// 		v[i].push(v[y].front());
			// 	}
			// }
			// while(sz(v[x])>1 && v[x].front() > v[y].front()){
			// 	v[i].push(v[x].front());
			// }
			// while(sz(v[y])>1 && v[y].front() > v[x].front()){
			// 	v[i].push(v[y].front());
			// }
			while(ptr[x]+1<sz(v[x]) && ptr[y]+1<sz(v[y])){
				if(v[x][ptr[x]] > v[y][ptr[y]]){
					v[i].pb(v[x][ptr[x]]);
					ptr[x]++;
				}
				else{
					v[i].pb(v[y][ptr[y]]);
					ptr[y]++;
				}
			}
			while(ptr[x]+1<sz(v[x]) && v[x][ptr[x]]>v[y][ptr[y]]){
				v[i].pb(v[x][ptr[x]]);
				ptr[x]++;
			}
			while(ptr[y]+1<sz(v[y]) && v[y][ptr[y]]>v[x][ptr[x]]){
				v[i].pb(v[y][ptr[y]]);
				ptr[y]++;
			}
			ans[2*i]=sz(v[2*i])-ptr[2*i]-1;
			ans[2*i+1]=sz(v[2*i+1])-ptr[2*i+1]-1;
		}
		if(i<L+1){
			s+=v[i].back();
		}
		v[2*i].clear();
		v[2*i+1].clear();
	}
	ans[1]=sz(v[1])-ptr[1]-1;
	v[1].clear();
	cout<<s<<"\n";
	rep(i,1,L+1){
		int k=ans[i];
		rep(j,0,k){
			cout<<i<<" ";
		}
	}
	cout<<"\n";
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
	while(t--) solve();
	return 0;
}