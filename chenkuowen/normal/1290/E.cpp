#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
typedef long long ll;
struct K{ int mi1,mi2,cnt,sz; ll sum; };
inline K merge(K a,K b){
	if(a.mi1>b.mi1) swap(a,b);
	if(a.mi1==b.mi1) 
		return (K){a.mi1,min(a.mi2,b.mi2),a.cnt+b.cnt,a.sz+b.sz,a.sum+b.sum};
	else return (K){a.mi1,min(a.mi2,b.mi1),a.cnt,a.sz+b.sz,a.sum+b.sum};
}
struct JRYSEG{
	struct Node{ K key; int tag1; };
	vector<Node> t;
	int L,R;
	void up(int p){ t[p].key=merge(t[p+p].key,t[p+p+1].key); }
	void put_tag(int p,int tag1,int tag2){
		t[p].tag1+=tag1; 
		t[p].key.mi1+=tag1;
		t[p].key.mi2+=tag1;
		t[p].key.sum+=1ll*tag1*t[p].key.sz;
		if(tag2<t[p].key.mi1) return;
		if(tag2<t[p].key.mi2){
			t[p].key.sum+=1ll*t[p].key.cnt*(tag2-t[p].key.mi1);
			t[p].key.mi1=tag2;
			return;
		}
		put_tag(p+p,t[p].tag1,tag2);
		put_tag(p+p+1,t[p].tag1,tag2);
		up(p); t[p].tag1=0;
	}
	void down(int p){
		put_tag(p+p,t[p].tag1,t[p].key.mi1);
		put_tag(p+p+1,t[p].tag1,t[p].key.mi1);
		t[p].tag1=0;
	}
	void change(int p,int l,int r,int x,K key){
		if(l==r){
			t[p].key=key;
			return;
		}
		int m=l+r>>1; down(p);
		if(x<=m) change(p+p,l,m,x,key);
		else change(p+p+1,m+1,r,x,key);
		up(p);
	}
	void change(int x,K key){ change(1,L,R,x,key); }
	void modify(int p,int l,int r,int x,int y,int tag1,int tag2){
		if(y<l||r<x) return;
		if(x<=l&&r<=y) return put_tag(p,tag1,tag2);
		int m=l+r>>1; down(p);
		modify(p+p,l,m,x,y,tag1,tag2);
		modify(p+p+1,m+1,r,x,y,tag1,tag2);
		up(p);
	}
	void modify(int x,int y,int tag1,int tag2){ modify(1,L,R,x,y,tag1,tag2); }
	K query(int p,int l,int r,int x,int y){
		if(y<l||r<x) return (K){(int)5e8,(int)1e9,0,0,0};
		if(x<=l&&r<=y) return t[p].key;
		int m=l+r>>1; down(p);
		return merge(query(p+p,l,m,x,y),query(p+p+1,m+1,r,x,y));
	}
	K query(int x,int y){ return query(1,L,R,x,y); }
	void build(int p,int l,int r){
		t[p].tag1=0;
		if(l==r){
			t[p].key=(K){(int)5e8,(int)1e9,0,0,0};
			return;
		}
		int m=l+r>>1;
		build(p+p,l,m);
		build(p+p+1,m+1,r);
		up(p);
	}
	void init(int _L,int _R){
		L=_L,R=_R; t.resize((R-L+1)*4+5);
		build(1,L,R);
	}
}seg;

void solve(ll ans[],int a[],int n){
	static int pos[N];
	for(int i=1;i<=n;++i) pos[a[i]]=i;
	seg.init(1,n);
	for(int i=1;i<=n;++i){
		seg.change(pos[i],(K){0,(int)1e9,1,1,0});
		int p=seg.query(1,pos[i]).sz;
		seg.modify(pos[i]+1,n,1,p);
		ans[i]=seg.query(1,n).sum;
	}
}
int a[N];
ll ans1[N],ans2[N];
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	solve(ans1,a,n);
	reverse(a+1,a+n+1);
	solve(ans2,a,n);
	for(int i=1;i<=n;++i)
		printf("%lld\n",1ll*i*i-ans1[i]-ans2[i]);
	return 0;
}