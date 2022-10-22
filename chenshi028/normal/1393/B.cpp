#include<cstdio>
using namespace std;
template<class T>inline void read(T&a){
	char c=getchar();int f=1;a=0;
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') a=(a<<1)+(a<<3)+c-48,c=getchar();
	a*=f;
}
template<class T>void write(T a){
	if(a<0) putchar('-'),a=-a;
	if(a>9) write(a/10);
	putchar(a%10+48); 
}
const int o=1e5+10;
int n,q,x,s[o],cnt,ans[4];char opt;
struct Splay{
	int rt,z,ls[o],rs[o],s[o],v[o],f[o],cnt[o];
	inline bool rel(int x){return ls[f[x]]-x;}
	inline void update(int x){if(x) s[x]=cnt[x]+s[ls[x]]+s[rs[x]];}
	inline void rotate(int x){
		int t1=f[x],t2=f[f[x]];bool rl=rel(x);
		if(rl){
			rs[t1]=ls[x];f[rs[t1]]=t1;ls[x]=t1;f[t1]=x;f[x]=t2;
			if(t2) if(ls[t2]-t1) rs[t2]=x;else ls[t2]=x;
		}
		else{
			ls[t1]=rs[x];f[rs[x]]=t1;rs[x]=t1;f[t1]=x;f[x]=t2;
			if(t2) if(ls[t2]-t1) rs[t2]=x;else ls[t2]=x;
		}
		update(t1);update(x);
	}
	inline void splay(int x){for(int fa;fa=f[x];rotate(x)) if(f[fa]) rotate(rel(fa)-rel(x)?x:fa);rt=x;}
	inline void insert(int x){
		if(!rt){rt=++z;ls[z]=rs[z]=f[z]=0;s[z]=cnt[z]=1;v[z]=x;return;}
		for(int now=rt,fa=0;1;fa=now,now=v[now]>x?ls[now]:rs[now])
			if(!now){++z;ls[z]=rs[z]=0;f[z]=fa;s[z]=cnt[z]=1;v[z]=x;if(x<v[fa]) ls[fa]=z;else rs[fa]=z;update(fa);splay(z);return;}
			else if(x==v[now]){++cnt[now];update(now);update(fa);splay(now);return;}
	}
	inline int quen(int x){
		for(int now=rt;1;)
			if(x<=s[ls[now]]) now=ls[now];
			else if((x-=(s[ls[now]]+cnt[now]))<=0) return v[now];else now=rs[now];
	}
	inline int quer(int x){
		for(int now=rt,ans=0;1;)
			if(x<v[now]) now=ls[now];
			else{
				ans+=s[ls[now]];
				if(x==v[now]){splay(now);return ans+1;}
				ans+=cnt[now];now=rs[now];
			}
	}
	inline int pre(){int now=ls[rt];for(;rs[now];now=rs[now]);return now;}
	inline int nxt(){int now=rs[rt];for(;ls[now];now=ls[now]);return now;}
	inline void erase(int x){
		quer(x);
		if(cnt[rt]-1){--cnt[rt];update(rt);return;}
		if(!ls[rt]&&!rs[rt]){rt=0;return;}
		if(!ls[rt]){rt=rs[rt];f[rt]=0;;return;}
		else if(!rs[rt]){rt=ls[rt];f[rt]=0;;return;}
		int t=rt;splay(pre());rs[rt]=rs[t];f[rs[rt]]=rt;update(rt);
	}
}bt;
int main(){
	read(n);for(int i=1;i<=n;++i) read(x),++s[x];
	for(int i=1;i<o;++i) if(s[i]) bt.insert(s[i]),++cnt;
	read(q);while(q--){
		opt=getchar();read(x);
		if(opt=='+'){if(s[x]) bt.erase(s[x]),--cnt;bt.insert(++s[x]);++cnt;}
		else{if(s[x]) bt.erase(s[x]),--cnt;bt.insert(--s[x]);++cnt;}
		for(int i=0;i<cnt&&i<3;++i) ans[i]=bt.quen(cnt-i);
		if(cnt&&ans[0]>7){printf("YES\n");continue;}
		if(cnt>1&&ans[0]>5&&ans[1]>1){printf("YES\n");continue;}
		if(cnt>1&&ans[0]>3&&ans[1]>3){printf("YES\n");continue;}
		if(cnt>2&&ans[0]>3&&ans[1]>1&&ans[2]>1){printf("YES\n");continue;}
		printf("NO\n");
	}
	return 0;
}