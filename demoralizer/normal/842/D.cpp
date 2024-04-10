#include <bits/stdc++.h>
using namespace std;
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

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=3e5+5;

struct node
{
	node* next[2]={0};
} ns[19*N];
int cnt=1;
node* create(){
	if(cnt<19*N) return ns+cnt++;
	else return new node();
}

void insert(int x){
	node *tmp=ns;
	for(int i=19;i>=0;i--){
		int k=x>>i&1;
		if(!tmp->next[k])tmp->next[k]=create();
		tmp=tmp->next[k];
	}
}

int query(int x){
	node *tmp=ns;
	int ans=0;
	for(int i=19;i>=0;i--){
		int k=x>>i&1;
		if(tmp->next[k]){
			tmp=tmp->next[k];
		}
		else{
			ans+=(1<<i);
			tmp=tmp->next[!k];
		}
	}
	return ans;
}

void solve(){
	set<int> s;
	rep(i,0,1<<19){
		s.insert(i);
	}
	int n,m;
	cin>>n>>m;
	rep(i,0,n){
		int x;
		cin>>x;
		s.erase(x);
	}
	for(int x:s){
		insert(x);
	}
	int prev=0;
	rep(i,0,m){
		int q;
		cin>>q;
		prev^=q;
		cout<<query(prev)<<"\n";
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