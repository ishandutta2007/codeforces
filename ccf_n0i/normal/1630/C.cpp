#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
int n,a[233333],f[233333],fir[233333];
int tag[833333];
void update(int x,int l,int r,int L,int R,int v){
	if(L<=l&&r<=R){
		tag[x]=max(tag[x],v);
		return;
	}
	int mid=(l+r)/2;
	if(L<=mid) update(x+x,l,mid,L,R,v);
	if(R>mid) update(x+x+1,mid+1,r,L,R,v);
}
int query(int x,int l,int r,int y){
	if(l==r) return tag[x];
	int mid=(l+r)/2,s=tag[x];
	if(y<=mid) s=max(s,query(x*2,l,mid,y)); else s=max(s,query(x*2+1,mid+1,r,y));
	return s;
}
int main(){
	memset(tag,-0x3f,sizeof(tag));
	int i;
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) if(!fir[a[i]]) fir[a[i]]=i;
	rep(i,n){
		f[i]=f[i-1];
		if(fir[a[i]]!=i){
			int tmp=query(1,1,n,fir[a[i]])-(n-i+1);
			tmp=max(tmp,f[fir[a[i]]-1]+(i-fir[a[i]]-1));
			f[i]=max(tmp,f[i]);
			update(1,1,n,fir[a[i]],i,tmp+(n-i));
		}
	}
	cout<<f[n]<<endl;
	return 0;
}