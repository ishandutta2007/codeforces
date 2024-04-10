#include<bits/stdc++.h>
#define int long long
namespace in{
	#ifndef slow
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	#else
	inline int getc(){return getchar();}
	#endif
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
	void puts(char *s){int now=0;while(s[now]!='\0')putc(s[now++]);putc('\n');}
}
using namespace std;
const int N=1e5+100;
int n,m,k,p;
int h[N],a[N],ht[N];
bool chk(int MaxH){
	fill(ht+1,ht+1+n,MaxH);
	priority_queue<pair<int,int>,
	vector<pair<int,int>>,
	greater<pair<int,int>>>q;
	for(int i=1;i<=n;i++)if(MaxH-m*a[i]<h[i])q.push({MaxH/a[i],i});
	for(int i=1;i<=m;i++)
		for(int j=1;j<=k;j++){
			if(q.empty())return true;
			auto now=q.top();q.pop();
			if(now.first<i)return false;
			ht[now.second]+=p;
			now.first=ht[now.second]/a[now.second];
			if(ht[now.second]-m*a[now.second]<h[now.second])q.push(now);
		}
	return q.empty();
}
signed main(){
	in::read(n,m,k,p);
	for(int i=1;i<=n;i++)in::read(h[i],a[i]);
	int l=0,r=1ll<<60,ans=0;
	while(l<r){
		int mid=l+r>>1;
		if(chk(mid))ans=mid,r=mid;
		else l=mid+1;
	}
	out::write(ans);
	out::flush();
	return 0;
}