#include<bits/stdc++.h>
#define int long long
const int N=1e5+3,K=18;
int n,m,a[N],c[N],s[N];
std::vector<int>b[N];
#define M (L+R>>1)
struct segment_tree{
	int lz[1<<K],mn[1<<K];
	inline void Add1(int a,int k){lz[k]+=a,mn[k]+=a;}
	inline void Down(int k){
		Add1(lz[k],k<<1),Add1(lz[k],k<<1|1);
		lz[k]=0;
	}
	void Build(int L,int R,int k){
		lz[k]=0;
		if(L==R){lz[k]=0,mn[k]=-(m-L+1);return;}
		Build(L,M,k<<1),Build(M+1,R,k<<1|1);
		mn[k]=std::min(mn[k<<1],mn[k<<1|1]);
	}
	void Add(int r,int a,int L,int R,int k){
		if(r<1)return;
		if(R<=r){
			Add1(a,k);
			return;
		}
		Down(k);
		Add(r,a,L,M,k<<1);
		if(r>M)Add(r,a,M+1,R,k<<1|1);
		mn[k]=std::min(mn[k<<1],mn[k<<1|1]);
	}
	int Min(){return mn[1];}
}t;
signed main(){
	int T;scanf("%lld",&T);for(;T--;){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	std::sort(a+1,a+1+n,[=](const int&a,const int&b){return a>b;});
	t.Build(1,m,1);
	for(int i=1;i<=m;i++){
		scanf("%lld",&c[i]),b[i].clear(),b[i].resize(c[i]),s[i]=0;
		for(int j=0;j<c[i];j++)scanf("%lld",&b[i][j]),s[i]+=b[i][j];
		t.Add(std::upper_bound(a+1,a+1+m,(s[i]+c[i]-1)/c[i],[=](const int&a,const int&b){return a>b;})-a-1, 1,1,m,1);
	}
	for(int i=1;i<=m;i++){
		t.Add(std::upper_bound(a+1,a+1+m,(s[i]+c[i]-1)/c[i],[=](const int&a,const int&b){return a>b;})-a-1,-1,1,m,1);
		for(int j=0;j<c[i];j++){
			t.Add(std::upper_bound(a+1,a+1+m,((s[i]-b[i][j])+(c[i]-1)-1)/(c[i]-1),[=](const int&a,const int&b){return a>b;})-a-1, 1,1,m,1);
			putchar(t.Min()>=0?'1':'0');
			t.Add(std::upper_bound(a+1,a+1+m,((s[i]-b[i][j])+(c[i]-1)-1)/(c[i]-1),[=](const int&a,const int&b){return a>b;})-a-1,-1,1,m,1);
		}
		t.Add(std::upper_bound(a+1,a+1+m,(s[i]+c[i]-1)/c[i],[=](const int&a,const int&b){return a>b;})-a-1, 1,1,m,1);
	}
	puts("");
	}return 0;
}