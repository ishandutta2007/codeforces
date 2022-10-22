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
const int o=4e5+10,inf=1e9+10;
#define int long long
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
}bt,bt2;
int n,tp,d,ans,x,tmp,tot2;
inline int f(){
	if(!tot2) return 0;
	bt2.insert(0);tmp=bt2.v[bt2.nxt()];bt2.erase(0);
	if(tmp<x) return 0;
	bt.insert(x);tmp-=bt.v[bt.pre()];bt.erase(x);
	return tmp;
}
signed main(){
	read(n);bt.insert(x=inf);while(n--){
		read(tp);read(d);
		if(tp) if(d>0){
			bt2.insert(d);ans+=d;bt.insert(d);++tot2;
			if(x<d) ans+=d;
			else bt.insert(x),tmp=bt.v[bt.pre()],bt.erase(x),ans+=(x=tmp);
			write(ans-f());putchar('\n');
		}
			else{
				ans-=(d=-d);bt2.erase(d);--tot2;
				if(x<d) ans-=d;
				else ans-=x,bt.insert(x),tmp=bt.v[bt.nxt()],bt.erase(x),x=tmp;
				bt.erase(d);write(ans-f());putchar('\n');
		}
		else if(d>0){bt.insert(d);if(x>d) ans+=d;else ans+=2*d-x,bt.insert(x),tmp=bt.v[bt.nxt()],bt.erase(x),x=tmp;write(ans-f());putchar('\n');}
		else{ans-=(d=-d);if(x<=d) bt.insert(x),tmp=bt.v[bt.pre()],bt.erase(x),ans-=d-(x=tmp);bt.erase(d);write(ans-f());putchar('\n');}
	}
	return 0;
}