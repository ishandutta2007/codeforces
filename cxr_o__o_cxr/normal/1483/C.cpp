//starusc
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1,c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=3e5+4;
int n,top,h[N],b[N],st[N],f[N],g[N];
multiset<int>s;
namespace seg{
	#define lc (p<<1)
	#define rc (p<<1|1)
	#define mid ((l+r)>>1)
	int t[N<<2];
	void modify(int p,int l,int r,int x){
		if(l==r){
			t[p]=f[x];
			return;
		}
		if(x<=mid)modify(lc,l,mid,x);
		else modify(rc,mid+1,r,x);
		t[p]=max(t[lc],t[rc]);
	}
	int query(int p,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return t[p];
		if(qr<=mid)return query(lc,l,mid,ql,qr);
		if(mid<ql)return query(rc,mid+1,r,ql,qr);
		return max(query(lc,l,mid,ql,qr),query(rc,mid+1,r,ql,qr));
	}
	#undef lc 
	#undef rc
	#undef mid
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)h[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++){
		while(top&&h[st[top]]>h[i]){
			s.erase(s.find(seg::query(1,0,n,st[top-1],st[top]-1)+b[st[top]]));
			top--;
		}
		st[++top]=i;
		s.insert(seg::query(1,0,n,st[top-1],st[top]-1)+b[i]);
		f[i]=*s.rbegin();
		seg::modify(1,0,n,i);
	}
	cout<<f[n]<<"\n"; 
	return (0-0);
}