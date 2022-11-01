#include<bits/stdc++.h>

using namespace std;
#define ll long long

namespace wish{
	int P1 = 998244853, P2 = 993244853, base = 233;
	int Pow(ll x, int y, const int P){
		int ans=1;
		for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
		return ans;
	}
	struct Hash{
		int x, y;
		Hash(){}
		Hash(int a){ x=y=a;}
		Hash(int a, int b){ x=a, y=b;}
		Hash operator+(const Hash &r)const{
			return Hash((x+r.x)%P1, (y+r.y)%P2);
		}
		void operator+=(const Hash &r){
			(x+=r.x)%=P1, (y+=r.y)%=P2;
		}
		Hash operator-(const Hash &r)const{
			return Hash((x-r.x+P1)%P1, (y-r.y+P2)%P2);
		}
		void operator-=(const Hash &r){
			(x+=P1-r.x)%=P1, (y+=P2-r.y)%=P2;
		}
		Hash operator*(int r)const{ return Hash((ll)x*r%P1, (ll)y*r%P2);}
		Hash operator*(const Hash &r)const{
			return Hash((ll)x*r.x%P1, (ll)y*r.y%P2);
		}
		bool operator==(const Hash &r)const{ return x==r.x && y==r.y;}
		bool operator!=(const Hash &r)const{ return x!=r.x || y!=r.y;}
		Hash inv()const{ return Hash(Pow(x, P1-2, P1), Pow(y, P2-2, P2));}
	};
	struct HashFunc{
		size_t operator()(const Hash &x)const{
			return hash<ll>()((ll)x.x<<32|x.y);
		}
	};
}
using namespace wish;

const int N = 300005, M = 20;
int n, m, num, w[M], ww[M], dep[N], h[N], e[N<<1], pre[N<<1], f[M][N];
char s[N];
Hash p[1<<19], g1[M][N], g2[M][N];
void add(int x, int y){ e[++num]=y, pre[num]=h[x], h[x]=num;}
void dfs(int u){
	g1[0][u]=g2[0][u]=s[u]-'a'+1;
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=f[0][u])
		f[0][e[i]]=u, dep[e[i]]=dep[u]+1, dfs(e[i]);
}
int jump(int x, int y){
	if(y<=0) return x;
	for(int i=19; i--;) if(y>>i&1) x=f[i][x];
	return x;
}
int lca(int x, int y){
	if(dep[x]<dep[y]) y=jump(y, dep[y]-dep[x]); else x=jump(x, dep[x]-dep[y]);
	if(x==y) return x;
	for(int i=19; i--;) if(f[i][x]!=f[i][y]) x=f[i][x], y=f[i][y];
	return f[0][x];
}
Hash calc1(int x, int y){
	Hash ans=0;
	for(int i=19; i--;) if(y>>i&1) ans=ans*p[1<<i]+g1[i][x], x=f[i][x];
	return ans;
}
Hash calc2(int x, int y){
	Hash ans=0;
	int now=0;
	for(int i=19; i--;) if(y>>i&1) ans+=g2[i][x]*p[now], now+=1<<i, x=f[i][x];
	return ans;
}
int main() {
	p[0]=1;
	for(int i=1; i<1<<19; ++i) p[i]=p[i-1]*base;
	scanf("%d%s", &n, s+1);
	for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), add(x, y), add(y, x);
	dfs(1);
	for(int i=1; i<19; ++i) for(int j=1; j<=n; ++j)
		f[i][j]=f[i-1][f[i-1][j]],
		g1[i][j]=g1[i-1][j]*p[1<<i>>1]+g1[i-1][f[i-1][j]],
		g2[i][j]=g2[i-1][j]+g2[i-1][f[i-1][j]]*p[1<<i>>1];
	scanf("%d", &m);
	while(m--){
		int a, b, c, d, la, lc, sa, sc;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		la=lca(a, b), lc=lca(c, d);
		if((sa=dep[a]-dep[la]+1)>(sc=dep[c]-dep[lc]+1))
			swap(a, c), swap(b, d), swap(la, lc), swap(sa, sc);
		int ans=0;
		if(calc1(a, sa)!=calc1(c, sa)){
			for(int i=19; i--;)
				if(g1[i][a]==g1[i][c]) ans+=1<<i, a=f[i][a], c=f[i][c];
		}
		else{
			int x=jump(b, dep[b]-dep[la]-(sc-sa));
			if(sc>sa+dep[b]-dep[la] || calc1(a, sa)*p[sc-sa]+calc2(x, sc-sa)!=calc1(c, sc)){
				ans=sa, c=jump(c, sa), w[0]=x, sc=dep[x]-dep[la];
				for(int i=0; i<19; ++i)
					if(sc>>i&1) w[i+1]=f[i][w[i]]; else w[i+1]=w[i];
				for(int i=19; i--;) if(sc>>i&1){
					if(g1[i][c]!=g2[i][w[i]]){
						for(int j=i; j--;)
							if(g1[j][c]!=g2[j][f[j][w[i]]])
								w[i]=f[j][w[i]];
							else ans+=1<<j, c=f[j][c];
						break;
					}
					ans+=1<<i, c=f[i][c];
				}
			}
			else{
				ans=sc, sa=dep[b]-dep[la]-(sc-sa), sc=dep[d]-dep[lc];
				if(sa>sc) b=jump(b, sa-sc), sa=sc; else d=jump(d, sc-sa);
				w[0]=b, ww[0]=d;
				for(int i=0; i<19; ++i)
					if(sa>>i&1) w[i+1]=f[i][w[i]], ww[i+1]=f[i][ww[i]];
					else w[i+1]=w[i], ww[i+1]=ww[i];
				for(int i=19; i--;) if(sa>>i&1){
					if(g2[i][w[i]]!=g2[i][ww[i]]){
						for(int j=i; j--;)
							if(g2[j][f[j][w[i]]]!=g2[j][f[j][ww[i]]])
								w[i]=f[j][w[i]], ww[i]=f[j][ww[i]];
							else ans+=1<<j;
						break;
					}
					ans+=1<<i;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}