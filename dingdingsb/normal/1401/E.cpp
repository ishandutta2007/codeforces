#include<bits/stdc++.h>
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
	    while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
using namespace std;
#define pb push_back
#define mp make_pair
#define N 1000010
#define ll long long
int n,m,y[N],lx[N],rx[N],x[N],ly[N],ry[N],tree[N];
ll ans;
#define lowbit(x) ((x)&-(x))
inline void add(int x,int v){for(int i=x;i<=1e6;i+=lowbit(i))tree[i]+=v;}
inline int sum(int x){int ans=0;for(int i=x;i>0;i-=lowbit(i))ans+=tree[i];return ans;}
vector<pair<int,int>>a[N];
vector<int>c[N];
int main(){
	in::read(n,m);
	for(int i=1;i<=n;++i){
		in::read(y[i],lx[i],rx[i]);
		if(rx[i]-lx[i]==1000000) ans++;
		a[lx[i]].pb({i,1});
		a[rx[i]+1].pb({i,-1});
	}
	for(int i=1;i<=m;++i){
		in::read(x[i],ly[i],ry[i]);
		if(ry[i]-ly[i]==1000000) ans++;
		c[x[i]].push_back(i);
	}
	for(int i=0;i<=1000000;++i){
		for(auto Seg:a[i])add(y[Seg.first],Seg.second);
		for(auto Seg:c[i]){
			if(ly[Seg]==0) ans+=sum(ry[Seg]);
			else ans+=sum(1000000)-sum(ly[Seg]-1);
		}
	}
	cout<<ans+1;
    return 0;
}