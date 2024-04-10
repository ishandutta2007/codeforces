#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=3e5+5;
int n,m;
int a[N],t[N],c[N];
vector<int> v[N];
set<pii> s1,s2;
struct node{
	int x1,x2,p1,p2;
	inline node(int x1,int p1,int x2,int p2):x1(x1),p1(p1),x2(x2),p2(p2){}
	inline bool operator <(const node &b)const{
		return 1ll*(x1+x2)*(v[x1][p1]+v[x2][p2])<1ll*(b.x1+b.x2)*(v[b.x1][b.p1]+v[b.x2][b.p2]);
	}
};
priority_queue<node> q;
inline void put(int x1,int p1,int x2,int p2){
	if(p1<0||p2<0) return;
	if(x1==x2&&p1==p2) return;
	int x=v[x1][p1],y=v[x2][p2];if(x>y) swap(x,y);
	if(s1.find({x,y})!=s1.end()) return;
	s1.insert({x,y});
	q.push(node(x1,p1,x2,p2));
}
void solve(){
	int i,j;
	for(i=1;i<=n;i++) t[i]=a[i];
	sort(t+1,t+n+1);
	for(i=1;i<=n;i++) a[i]=lower_bound(t+1,t+n+1,a[i])-t;
	for(i=1;i<=n;i++) c[a[i]]++;
	for(i=1;i<=n;i++)
		v[c[i]].push_back(t[i]);
	for(i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
	vector<int> b;
	for(i=1;i<=n;i++)
		if(!v[i].empty()) b.push_back(i);
	for(i=0;i<b.size();i++){
		put(b[i],(int)v[b[i]].size()-1,b[i],(int)v[b[i]].size()-2);
		for(j=0;j<i;j++)
			put(b[i],(int)v[b[i]].size()-1,b[j],(int)v[b[j]].size()-1);
	}
	while(!q.empty()){
		node u=q.top();q.pop();
		int x=v[u.x1][u.p1],y=v[u.x2][u.p2];if(x>y) swap(x,y);
		put(u.x1,u.p1-1,u.x2,u.p2);
		put(u.x1,u.p1,u.x2,u.p2-1);
		if(s2.find({x,y})!=s2.end()) continue;
		cout<<1ll*(u.x1+u.x2)*(x+y)<<endl;
		return;
	}
}
int main(){
	int i,j;
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _;cin>>_;
	while(_--){
		cin>>n>>m;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<=m;i++){
			int x,y;cin>>x>>y;if(x>y) swap(x,y);
			s2.insert({x,y});
		}
		solve();
		for(i=1;i<=n;i++) c[i]=0;
		for(i=1;i<=n;i++) v[i].clear();
		s1.clear();s2.clear();
		while(!q.empty()) q.pop();
	}
	return 0;
}