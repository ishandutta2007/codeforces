#include<bits/stdc++.h>
struct segment{int l,r;};
const int K=18,N=1e5+3;
int n,m,a[N],b[N],ans,lz[1<<K];
struct data{
	int mx,mn,mx1,mn1,px,pn;
	segment px1,pn1;
	friend inline data operator+(data a,data b){
		if(b.mx1>a.mx1)a.mx1=b.mx1,a.px1=b.px1;
		if(b.mx-a.mn>a.mx1)a.mx1=b.mx-a.mn,a.px1=(segment){a.pn,b.px};
		if(b.mn1<a.mn1)a.mn1=b.mn1,a.pn1=b.pn1;
		if(b.mn-a.mx<a.mn1)a.mn1=b.mn-a.mx,a.pn1=(segment){a.px,b.pn};
		if(b.mx>a.mx)a.mx=b.mx,a.px=b.px;
		if(b.mn<a.mn)a.mn=b.mn,a.pn=b.pn;
		return a;
	}
}s[1<<K];
#define M (L+R>>1)
inline void Add1(int a,int k){s[k].mx+=a,s[k].mn+=a,lz[k]+=a;}
inline void Down(int k){
	if(!lz[k])return;
	Add1(lz[k],k<<1),Add1(lz[k],k<<1|1);
	lz[k]=0;
}
void Build(int L,int R,int k){
	if(L==R){s[k]=(data){b[L],b[R],0,0,L,R,L,R,L,R};return;}
	Build(L,M,k<<1),Build(M+1,R,k<<1|1);
	s[k]=s[k<<1]+s[k<<1|1];
}
void Add(int p,int a,int L,int R,int k){
	if(p<=L){Add1(a,k);return;}
	Down(k);
	if(p<=M)Add(p,a,L,M,k<<1);
	Add(p,a,M+1,R,k<<1|1);
	s[k]=s[k<<1]+s[k<<1|1];
}
data Query(int l,int r,int L,int R,int k){
	if(l<=L&&R<=r)return s[k];
	Down(k);
	if(r<=M)return Query(l,r,L,M  ,k<<1  );
	if(l> M)return Query(l,r,M+1,R,k<<1|1);
	return Query(l,r,L,M,k<<1)+Query(l,r,M+1,R,k<<1|1);
}
#undef M
struct node{
	segment seg;data a;bool f;
	inline int Get()const{return f?-a.mn1:a.mx1;}
	bool operator<(const node&b)const{return Get()<b.Get();}
};
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",i+a),b[i]=a[i]+b[i-1];
	Build(0,n,1);
	scanf("%d",&m);
	for(int o,x,y,z;m--;){
		scanf("%d%d%d",&o,&x,&y);
		if(o){
			scanf("%d",&z),--x;
			ans=0;
			std::priority_queue<node>q;
			auto Push=[&](segment seg,bool f){q.push((node){seg,Query(seg.l,seg.r,0,n,1),f});};
			Push((segment){x,y},0);
			for(;z--;){
				node u=q.top();q.pop();
				ans+=std::max(0,u.Get());
				if(u.f){
					Push(u.a.pn1,0);
					Push((segment){u.seg.l,u.a.pn1.l},1);
					Push((segment){u.a.pn1.r,u.seg.r},1);
				}
				else{
					Push(u.a.px1,1);
					Push((segment){u.seg.l,u.a.px1.l},0);
					Push((segment){u.a.px1.r,u.seg.r},0);
				}
			}
			printf("%d\n",ans);
		}
		else{
			Add(x,y-a[x],0,n,1);
			a[x]=y;
		}
	}
	return 0;
}