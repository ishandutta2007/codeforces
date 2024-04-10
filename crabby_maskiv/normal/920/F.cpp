#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const int M=1000005;
template<typename T>inline void read(T &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;return;
}
template<typename T,typename...Args>
    inline void read(T &x,Args &...args){
    read(x);read(args...);
}
int n,m;
ll a[N];
struct sgt{
	int ls,rs,l,r;
	ll mx,sum;
}s[3*N];
int rt,P;
ll D[M];
inline void upd(int p){
	s[p].sum=s[s[p].ls].sum+s[s[p].rs].sum;
	s[p].mx=max(s[s[p].ls].mx,s[s[p].rs].mx);
}
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	s[p].ls=s[p].rs=0;
	if(l==r){
		s[p].sum=s[p].mx=a[l];
		return p;
	}
	int mid=(l+r)/2;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	upd(p);
	return p;
}
void change(int p,int l,int r){
	if(s[p].mx<=2) return;
	if(s[p].l==s[p].r){
		s[p].sum=s[p].mx=D[s[p].sum];
		return;
	}
	int mid=(s[p].l+s[p].r)/2;
	if(r<=mid) change(s[p].ls,l,r);
	else if(l>mid) change(s[p].rs,l,r);
	else{
		change(s[p].ls,l,mid);
		change(s[p].rs,mid+1,r);
	}
	upd(p);
	return;
}
ll query(int p,int l,int r){
	if(s[p].l==l&&s[p].r==r){
		return s[p].sum;
	}
	int mid=(s[p].l+s[p].r)/2;
	if(r<=mid) return query(s[p].ls,l,r);
	else if(l>mid) return query(s[p].rs,l,r);
	else return query(s[p].ls,l,mid)+query(s[p].rs,mid+1,r);
}
int main(){
	int i,j=0;
	read(n,m);
	for(i=1;i<=n;i++) read(a[i]);
	for(i=1;i<M;i++){
		for(j=i;j<M;j+=i)
			D[j]++;
	}
	P=0;
	rt=build(1,n);
	while(m--){
		int op,x,y;
		read(op,x,y);
		if(op==1) change(rt,x,y);
		else printf("%I64d\n",query(rt,x,y));
	}		
	return 0;
}