#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;
const int MXN=35011,MXK=53,MXT=131077,inf=0x3f3f3f3f;
int f[MXK][MXN],a[MXN],lst[MXN];

struct Seg{
	int mx,ad;
	inline void add(int x){mx+=x,ad+=x;}
}sg[MXT];
inline void psup(int no){sg[no].mx=max(sg[no<<1].mx,sg[no<<1|1].mx);}
inline void psdw(int no){if(sg[no].ad)sg[no<<1].add(sg[no].ad),sg[no<<1|1].add(sg[no].ad),sg[no].ad=0;}

inline void upd(int no,int l,int r,int x,int v){
	if(l==r)sg[no].mx=v;
	else{
		psdw(no);
		int mid=(l+r)>>1;
		if(x<=mid)upd(no<<1,l,mid,x,v);
		else upd(no<<1|1,mid+1,r,x,v);
		psup(no);
	}
}
inline void add(int no,int l,int r,int ll,int rr,int v){
	if(ll<=l&&rr>=r)sg[no].add(v);
	else{
		psdw(no);
		int mid=(l+r)>>1;
		if(ll<=mid)add(no<<1,l,mid,ll,rr,v);
		if(rr>mid)add(no<<1|1,mid+1,r,ll,rr,v);
		psup(no);
	}
}
inline void clr(int no,int l,int r){
	sg[no].mx=~inf,sg[no].ad=0;
	if(l<r){
		int mid=(l+r)>>1;
		clr(no<<1,l,mid),clr(no<<1|1,mid+1,r);
	}
}

int n,k;

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=k;i++){
		clr(1,0,n);
		memset(lst,0,sizeof(lst));
		upd(1,0,n,i-1,f[i-1][i-1]);
		for(int j=i;j<=n;j++){
			add(1,0,n,lst[a[j]],j-1,1);lst[a[j]]=j;
			f[i][j]=sg[1].mx;
			upd(1,0,n,j,f[i-1][j]);
		}
	}
	printf("%d\n",f[k][n]);
	return 0;
}