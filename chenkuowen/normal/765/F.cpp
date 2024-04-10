#include<bits/stdc++.h>
using namespace std;
const int N=5+3e5;
namespace __SEG{
	struct Node{
		int s[2],mx;
	}t[N*32];
	int top=0;
	inline int new_node(){
		t[++top]=(Node){{0,0},0};
		return top;
	}
	inline void up(int x){ t[x].mx=max(t[t[x].s[0]].mx,t[t[x].s[1]].mx); }
	struct II{II(){ t[0]=(Node){{0,0},0}; }}__ii;
	struct SEG{
		int rt;
		SEG(){ rt=0; }
		void add(int& p,int l,int r,int x,int key){
//			cerr<<l<<" "<<r<<endl;
			if(p==0) p=new_node();
			if(l==r){
				t[p].mx=max(t[p].mx,key);
				return;
			}
			int m=l+r>>1; 
			if(x<=m) add(t[p].s[0],l,m,x,key);
			else add(t[p].s[1],m+1,r,x,key);
			up(p);
//			printf("{%d %d %d %d}",p,l,r,t[p].mx);
		}
		void add(int x,int key){ add(rt,0,(1<<30)-1,x,key); }
		int query(int p,int l,int r,int x,int y){
//			cerr<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
			if(y<l||r<x||p==0) return 0;
			if(x<=l&&r<=y) return t[p].mx;
			int m=l+r>>1;
			return max(query(t[p].s[0],l,m,x,y),query(t[p].s[1],m+1,r,x,y));
		}
		int query(int x,int y){ return query(rt,0,(1<<30)-1,x,y); }
	};
}
using __SEG::SEG;
SEG seg;
int a[N];
map<int,int> s;
void s_insert(int x,int key){
	auto it=s.lower_bound(x);
	if(it!=s.end()&&it->second<key) return;
	while(1){
		auto it=s.lower_bound(x);
		if(it==s.begin()) break;
		it=prev(it);
		if(it->second>=key) s.erase(it);
		else break;
	}
	s[x]=key;
}
void queryl(int x){
	int l=0,r=a[x];
	while(1){
		int y=seg.query(l,r);
		if(y==0) return;
		s_insert(y,abs(a[x]-a[y]));
		if(l==r) return;
		l=a[x]+a[y]+1>>1;
	}
	return;
}
void queryr(int x){
	int l=a[x],r=(1<<30)-1;
	while(1){
		int y=seg.query(l,r);
		if(y==0) return;
		s_insert(y,abs(a[x]-a[y]));
		if(l==r) return;
		r=a[x]+a[y]>>1;
	}
	return;
}
struct Q{ int l,r,id; };
vector<Q> q[N];
int ans[N];
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int m; scanf("%d",&m);
	for(int i=1;i<=m;++i){
		Q x; scanf("%d%d",&x.l,&x.r); x.id=i;
		q[x.r].push_back(x);
	}
	for(int i=1;i<=n;++i){
		queryl(i); queryr(i); seg.add(a[i],i);
		for(auto d:q[i]) ans[d.id]=s.lower_bound(d.l)->second;
	}
	for(int i=1;i<=m;++i) printf("%d\n",ans[i]);
	return 0;
}