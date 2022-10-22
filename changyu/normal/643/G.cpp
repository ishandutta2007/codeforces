#include<bits/stdc++.h>
typedef std::pair<int,int> pii;
const int N=150003,P=5,K=19;
int n,m,p,a[N],lz[1<<K];
struct node{
	std::vector<pii>a;
	inline void Print(){printf("%llu",a.size());for(pii x:a)printf(" %d",x.second);puts("");}
	friend inline node operator+(node a,node b){
		for(int i=0;i<a.a.size();i++)
			for(int j=0;j<b.a.size();j++)
				if(a.a[i].second==b.a[j].second)
					a.a[i].first+=b.a[j].first,b.a[j].first=0;
		a.a.insert(a.a.end(),b.a.begin(),b.a.end());
		std::sort(a.a.begin(),a.a.end(),[](const pii&a,const pii&b){return a>b;});
		for(int i=(int)a.a.size()-1;i>=p;i--)
			for(int j=i-p;j<=i;j++)a.a[j].first-=a.a[i].first;
		for(;!a.a.empty()&&!a.a.back().first;a.a.pop_back());
		return a;
	}
}s[1<<K];
#define M (L+R>>1)
void Build(int L,int R,int k){
	if(L==R){s[k].a.assign(1,pii(1,a[L]));return;}
	Build(L,M,k<<1),Build(M+1,R,k<<1|1);
	s[k]=s[k<<1]+s[k<<1|1];
}
inline void Down(int L,int R,int k){
	if(!lz[k])return;
	lz[k<<1  ]=lz[k],s[k<<1  ].a.assign(1,pii(M-L+1,lz[k]));
	lz[k<<1|1]=lz[k],s[k<<1|1].a.assign(1,pii(R-M  ,lz[k]));
	lz[k]=0;
}
void Update(int l,int r,int x,int L,int R,int k){
	if(l<=L&&R<=r){lz[k]=x,s[k].a.assign(1,pii(R-L+1,x));return;}
	Down(L,R,k);
	if(l<=M)Update(l,r,x,L,M  ,k<<1  );
	if(r> M)Update(l,r,x,M+1,R,k<<1|1);
	s[k]=s[k<<1]+s[k<<1|1];
}
node Query(int l,int r,int L,int R,int k){
	if(l<=L&&R<=r)return s[k];
	Down(L,R,k);
	if(r<=M)return Query(l,r,L,M  ,k<<1  );
	if(l> M)return Query(l,r,M+1,R,k<<1|1);
	return Query(l,r,L,M,k<<1)+Query(l,r,M+1,R,k<<1|1);
}
int main(){
	int o,l,r,x;
	scanf("%d%d%d",&n,&m,&p),p=100/p;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	Build(1,n,1);
	for(;m--;){
		scanf("%d%d%d",&o,&l,&r);
		if(o==1)scanf("%d",&x),Update(l,r,x,1,n,1);
		else Query(l,r,1,n,1).Print();
	}
	return 0;
}