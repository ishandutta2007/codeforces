#include<bits/stdc++.h>
#define int long long
const int N=1e5+3;
#define M (L+R>>1)
struct segment_tree{
	int s[1<<20],lz[1<<20];
	inline void Clear(){
		for(int i=0;i<(1<<20);i++)s[i]=0,lz[i]=0;
	}
	inline void Down(int L,int R,int k){
		s[k<<1]+=lz[k]*(M-L+1),s[k<<1|1]+=lz[k]*(R-M);
		lz[k<<1]+=lz[k],lz[k<<1|1]+=lz[k];
		lz[k]=0;
	}
	int Sum(int l,int r,int L,int R,int k){
		if(l<=L&&R<=r)return s[k];
		Down(L,R,k);
		if(l>M)return Sum(l,r,M+1,R,k<<1|1);
		if(r<=M)return Sum(l,r,L,M,k<<1);
		return Sum(l,r,M+1,R,k<<1|1)+Sum(l,r,L,M,k<<1);
	}
	void Add1(int l,int r,int L,int R,int k){
		if(l<=L&&R<=r){s[k]+=R-L+1,lz[k]++;return;}
		Down(L,R,k);
		if(l<=M)Add1(l,r,L,M,k<<1);
		if(r>M)Add1(l,r,M+1,R,k<<1|1);
		s[k]=s[k<<1]+s[k<<1|1];
	}
}t;
struct segment{int l,r,ll,rr;}a[N];
int n,t0[N],t1[N],tmp[N*4],k;
bool Cmp0(const int&i,const int&j){return a[i].l<a[j].l;}
bool Cmp1(const int&i,const int&j){return a[i].r<a[j].r;}
bool Cmp2(const int&i,const int&j){return a[i].ll<a[j].ll;}
bool Cmp3(const int&i,const int&j){return a[i].rr<a[j].rr;}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
	  scanf("%lld%lld%lld%lld",&a[i].l,&a[i].r,&a[i].ll,&a[i].rr);
	  tmp[++k]=a[i].l,tmp[++k]=a[i].r,tmp[++k]=a[i].ll,tmp[++k]=a[i].rr;
	  t0[i]=i;
	  t1[i]=i;
	}
	std::sort(tmp+1,tmp+1+n*4);
	k=0;
	for(int i=1;i<=n*4;i++)if(tmp[i]!=tmp[i-1])tmp[++k]=tmp[i];
	for(int i=1;i<=n;i++){
	  a[i].l=std::lower_bound(tmp+1,tmp+1+k,a[i].l)-tmp;
	  a[i].r=std::lower_bound(tmp+1,tmp+1+k,a[i].r)-tmp;
	  a[i].ll=std::lower_bound(tmp+1,tmp+1+k,a[i].ll)-tmp;
	  a[i].rr=std::lower_bound(tmp+1,tmp+1+k,a[i].rr)-tmp;
	}
	t.Clear();
	std::sort(t0+1,t0+1+n,Cmp0);
	std::sort(t1+1,t1+1+n,Cmp1);
	for(int p=1,q=1;p<=n;p++){
	  for(;a[t1[q]].r<a[t0[p]].l&&q<=n;q++)t.Add1(a[t1[q]].ll,a[t1[q]].rr,1,k,1);
	  if(t.Sum(a[t0[p]].ll,a[t0[p]].rr,1,k,1))return 0*puts("NO");
	}
	t.Clear();
	std::sort(t0+1,t0+1+n,Cmp2);
	std::sort(t1+1,t1+1+n,Cmp3);
	for(int p=1,q=1;p<=n;p++){
	  for(;a[t1[q]].rr<a[t0[p]].ll&&q<=n;q++)t.Add1(a[t1[q]].l,a[t1[q]].r,1,k,1);
	  if(t.Sum(a[t0[p]].l,a[t0[p]].r,1,k,1))return 0*puts("NO");
	}
	puts("YES");
	return 0;
}