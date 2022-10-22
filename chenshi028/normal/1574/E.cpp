#include<cstdio>
#include<map>
#include<utility>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=1e6+10,MOD=998244353;
int n,m,k,rw,cl,col,f[o][2],g[o][2],h1,h2,pw[o],z[o];map<pair<int,int>,int> mp;
inline void clear(int x,int y){
	--z[(x&1)^(y&1)^(mp[make_pair(x,y)]-1)];
	if(!--f[x][col=(mp[make_pair(x,y)]-1)^(y&1)])
		if(f[x][!col]) --h1;else ++rw;
	if(!--g[y][col=(mp[make_pair(x,y)]-1)^(x&1)])
		if(g[y][!col]) --h2;else ++cl;
}
inline int calc(){
	int res=0;
	if(!h1) res=pw[rw];
	if(!h2) res=(res+pw[cl])%MOD;
	if(!z[0]) --res;
	if(!z[1]) --res;
	if(res<0) res+=MOD;
	return res;
}
int main(){
	read(n);read(m);read(k);rw=n;cl=m;
	for(int i=pw[0]=1;i<=n||i<=m;++i) pw[i]=pw[i-1]*2%MOD;
	for(int x,y,t;k--;printf("%d\n",calc())){
		read(x);read(y);read(t);
		if(mp[make_pair(x,y)]) clear(x,y);
		if(mp[make_pair(x,y)]=t+1){
			++z[(x&1)^(y&1)^t];
			if(!f[x][col=t^(y&1)]++)
				if(f[x][!col]) ++h1;else --rw;
			if(!g[y][col=t^(x&1)]++)
				if(g[y][!col]) ++h2;else --cl;
		}
	}
	return 0;
}