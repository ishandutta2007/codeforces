// Problem: D. Hemose in ICPC ?
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.ml/contest/1592/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=1e3+100;
int n;
vector<int>g[N];
pair<int,int>e[N];int cnt=0;
void bfs(int u){
	queue<pair<int,int>>q;q.push({u,0});
	while(q.size()){
		u=q.front().fi;int fa=q.front().se;
		q.pop();
		for(auto v:g[u])if(v!=fa)
			e[++cnt]=mp(u,v),q.push({v,u});
	}
}
void work(int l,int r,int kk){
	if(l==r){
		cout<<"! "<<e[l].fi<<" "<<e[l].se<<endl;
		exit(0);
	}
	set<int>num;
	for(int i=l;i<=mid;i++)
		num.insert(e[i].fi),num.insert(e[i].se);
	cout<<"? "<<num.size()<<" ";
	for(auto x:num)
		cout<<x<<" ";
	cout<<endl;
	int x;cin>>x;
	if(x==kk)work(l,mid,kk);
	else work(mid+1,r,kk);
}
signed main(){
	srand(time(0));
	cin>>n;
	for(int i=1,u,v;i<n;i++)
		read(u,v),g[u].pb(v),g[v].pb(u);
	bfs(rand()%n+1);
	int x;;
	cout<<"? "<<n<<" ";
	for(int i=1;i<=n;i++)
		cout<<i<<" ";
	cout<<endl;
	cin>>x;
	work(1,n-1,x);
}