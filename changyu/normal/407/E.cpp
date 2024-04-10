#include<bits/stdc++.h>
typedef long long ll;
const ll INF=1e16;
const int N=2e5+3,K=19;
int n,k,st[N],tp,l0[N],l1[N],la[N];
ll d,a[N];
std::map<ll,int>mp;
#define M (L+R>>1)
struct segment_tree{
	struct node{int mn,mn0,mn1,lz0,lz1;}s[1<<K];
	inline void Init(){
		for(int i=1;i<(1<<K);i++)s[i].mn=s[i].mn0=s[i].mn1=INF,s[i].lz0=s[i].lz1=-1;
	}
	inline void Up(int k){
		s[k].mn=std::min(s[k<<1].mn,s[k<<1|1].mn);
		s[k].mn0=std::min(s[k<<1].mn0,s[k<<1|1].mn0);
		s[k].mn1=std::min(s[k<<1].mn1,s[k<<1|1].mn1);
	}
	inline void Do_min(ll a,int L,int R,int k){
		s[k].mn=s[k].mn0-a;
		s[k].mn1=L*d-a;
	}
	inline void Do_max(ll a,int L,int R,int k){
		s[k].mn=s[k].mn1+a;
		s[k].mn0=L*d+a;
	}
	inline void Down(int L,int R,int k){
		if(s[k].lz0>=0){
		  Do_min(s[k].lz0,L,M,k<<1),Do_min(s[k].lz0,M+1,R,k<<1|1);
		  s[k<<1].lz0=s[k<<1|1].lz0=s[k].lz0;
		}
		if(s[k].lz1>=0){
		  Do_max(s[k].lz1,L,M,k<<1),Do_max(s[k].lz1,M+1,R,k<<1|1);
		  s[k<<1].lz1=s[k<<1|1].lz1=s[k].lz1;
		}
		s[k].lz0=s[k].lz1=-1;
	}
	void Min(int l,int r,ll a,int L,int R,int k){
		if(l>r)return;
		if(l<=L&&R<=r){
		  Do_min(a,L,R,k),s[k].lz0=a;
		  return;
		}
		Down(L,R,k);
		if(l<=M)Min(l,r,a,L,M,k<<1);
		if(r> M)Min(l,r,a,M+1,R,k<<1|1);
		Up(k);
	}
	void Max(int l,int r,ll a,int L,int R,int k){
		if(l>r)return;
		if(l<=L&&R<=r){
		  Do_max(a,L,R,k),s[k].lz1=a;
		  return;
		}
		Down(L,R,k);
		if(l<=M)Max(l,r,a,L,M,k<<1);
		if(r> M)Max(l,r,a,M+1,R,k<<1|1);
		Up(k);
	}
	void Update(int p,ll a,int L,int R,int k){
		if(L==R){
		  s[k].mn=L*d;
		  s[k].mn0=L*d+a;
		  s[k].mn1=L*d-a;
		  return;
		}
		Down(L,R,k);
		p<=M?Update(p,a,L,M,k<<1):Update(p,a,M+1,R,k<<1|1);
		Up(k);
	}
	int Find(ll a,int L,int R,int k){
		if(s[k].mn>a)return-1;
		if(L==R)return L;
		Down(L,R,k);
		if(s[k<<1].mn<=a)return Find(a,L,M,k<<1);
		return Find(a,M+1,R,k<<1|1);
	}
	int Query(int l,int r,ll a,int L,int R,int k){
		if(l<=L&&R<=r)return Find(a,L,R,k);
		Down(L,R,k);
		int tmp;
		if(l<=M&&~(tmp=Query(l,r,a,L,M,k<<1)))return tmp;
		if(r> M&&~(tmp=Query(l,r,a,M+1,R,k<<1|1)))return tmp;
		return-1;
	}
}t;
int main(){
	int mx=-1,p=0,tmp;
	scanf("%d%d%lld",&n,&k,&d);
	for(int i=1;i<=n;i++)scanf("%lld",a+i),a[i]+=10000000001;
	if(!d){
	  int l=0,r=0,mx=0;
	  for(int i=1;i<=n;i++){
		l=a[i]==a[i-1]?l+1:1;
		if(l>mx)mx=l,r=i;
	  }
	  printf("%d %d\n",r-mx+1,r);
	  return 0;
	}
	tp=0;
	for(int i=1;i<=n;i++){
	  for(;tp&&a[st[tp]]>a[i];tp--);
	  l0[i]=st[tp];
	  st[++tp]=i;
	}
	tp=0;
	for(int i=1;i<=n;i++){
	  for(;tp&&a[st[tp]]<a[i];tp--);
	  l1[i]=st[tp];
	  st[++tp]=i;
	}
	for(int i=1;i<=n;i++)
	  la[i]=mp[a[i]],mp[a[i]]=i;
	t.Init();
	for(int i=1,l=1;i<=n;i++){
	  t.Min(l0[i]+1,i-1,a[i],1,n,1);
	  t.Max(l1[i]+1,i-1,a[i],1,n,1);
	  t.Update(i,a[i],1,n,1);
	  if(a[i]%d!=a[i-1]%d)l=i;
	  l=std::max(la[i]+1,l);
	  tmp=i-t.Query(l,i,(k+i)*d,1,n,1);
	  if(tmp!=i+1&&tmp>mx)mx=tmp,p=i;
	}
	printf("%d %d\n",p-mx,p);
	return 0;
}