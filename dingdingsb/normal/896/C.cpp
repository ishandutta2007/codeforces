#include<bits/stdc++.h>
namespace in{
	#ifdef slow
	inline int getc(){return getchar();}
	#else
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	#endif
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
	while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
	char getC(){char c=getc();while(!isalpha(c))c=getc();return c;}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
	inline void puts(char *s){int now=0;while(s[now]!='\0')putc(s[now]),now++;putc('\n');}
}
typedef long long ll;
ll pow(ll a,ll b,ll mod){
	ll res=1;a%=mod;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;b>>=1;
	}return res;
}
struct node{
	int l,r;
	mutable ll v;
	node(int L,int R=-1,ll V=0):l(L),r(R),v(V){}
	bool operator<(const node&rhs)const{
		return l<rhs.l;
	}
};
std::set<node>s;
std::set<node>::iterator split(int pos){
	auto it=s.lower_bound(node(pos));
	if(it!=s.end()&&it->l==pos)return it;
	--it;
	int L=it->l,R=it->r;
	ll V=it->v;
	s.erase(it);
	s.insert(node(L,pos-1,V));
	return s.insert(node(pos,R,V)).first;
}
void add(int l,int r,ll val=1){
	auto itl=split(l),itr=split(r+1);
	for(;itl!=itr;++itl)itl->v+=val;
}
void assign_val(int l,int r,ll val=0){
	auto itl=split(l),itr=split(r+1);
	s.erase(itl,itr);s.insert(node(l,r,val));
}
ll rank(int l,int r,int k){
	std::vector<std::pair<ll,int>>vp;
	auto itl=split(l),itr=split(r+1);
	vp.clear();
	for(;itl!=itr;++itl)
		vp.push_back({itl->v,itl->r-itl->l+1});
	sort(vp.begin(),vp.end());
	for(auto x:vp){
		k-=x.second;
		if(k<=0)return x.first;
	}return -1;
}
ll sum(int l,int r,int ex,int mod){
	auto itl=split(l),itr=split(r+1);
	ll res=0;
	for(;itl!=itr;++itl)
		res=(res+1ll*(itl->r-itl->l+1)*pow(itl->v,ex,mod))%mod;
	return res;
}
const int N=1e5+10;
int n,m;ll seed,vmax;
ll rnd(){
	ll res=seed;
	seed=(seed*7+13)%1000000007;
	return res;
}
ll a[N];
signed main(){
	in::read(n,m,seed,vmax);
	for(int i=1;i<=n;i++)
		a[i]=rnd()%vmax+1,
		s.insert(node(i,i,a[i]));
	s.insert(node(n+1,n+1,0));
	int lines=0;
	for(int i=1;i<=m;i++){
		int op=rnd()%4+1;
		int l=rnd()%n+1;
		int r=rnd()%n+1;
		if(l>r)std::swap(l,r);
		int x,y;
		if(op==3)x=rnd()%(r-l+1)+1;
		else x=rnd()%vmax+1;
		if(op==4)y=rnd()%vmax+1;
		if(op==1)add(l,r,x);
		else if(op==2)assign_val(l,r,x);
		else if(op==3)out::write(rank(l, r, x)),out::putc('\n');
		else out::write(sum(l, r, x, y)),out::putc('\n');
	}
	out::flush();
	return 0;
}