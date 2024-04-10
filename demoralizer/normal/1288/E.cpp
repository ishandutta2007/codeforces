#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
// #define int               long long
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

int block;
vector<int> v;
int mn[300005];
int mx[300005];
int li[300005];
vector<pii> q;

int freq[300005];

bool cmp(pii a,pii b){
	if(a.fr/block != b.fr/block)return (a.fr/block < b.fr/block);
	return a.sc<b.sc;
}

void solve(){
	int n,m;
	 cin>>n>>m;
	 block=sqrt(n);
	 rep(i,1,n+1){
	 	mn[i]=i;
	 	li[n+1-i]=sz(v);
	 	v.pb(n+1-i);
	 }
	 rep(i,0,m){
	 	int t;
	 	cin>>t;
	 	mn[t]=1;
	 	q.pb({li[t],sz(v)});
	 	li[t]=sz(v);
	 	v.pb(t);
	 }
	 rep(i,1,n+1){
	 	q.pb({li[i],sz(v)-1});
	 }
	 // for(int x: v)cout<<x<<" ";cout<<"\n";
	 sort(all(q),cmp);
	 
	 int cl=0,cr=0,d=0;
	 freq[v[cl]]++;d=1;
	 for(pii z:q){
	 	int l=z.fr,r=z.sc;
	 	while(cr<r){
	 		cr++;
	 		freq[v[cr]]++;
	 		if(freq[v[cr]]==1)d++;//if(z.fr==0)cou<<"--------\n";
	 	}
	 	while(cl<l){
	 		freq[v[cl]]--;
	 		if(freq[v[cl]]==0)d--;
	 		cl++;
	 	}
	 	while(cl>l){
	 		cl--;
	 		freq[v[cl]]++;
	 		if(freq[v[cl]]==1)d++;
	 	}
	 	while(cr>r){
	 		freq[v[cr]]--;
	 		if(freq[v[cr]]==0)d--;
	 		cr--;
	 	}
	 	// cout<<z<<" "<<d<<"\n";
	 	mx[v[cl]]=max(mx[v[cl]],d);
	 }
	 rep(i,1,n+1){
	 	cout<<mn[i]<<" "<<mx[i]<<"\n";
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
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}