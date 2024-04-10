#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define go(k,s,b) for(int k=b._Find_next(s);k<N;k=b._Find_next(k))
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define bits bitset<N>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=2005;
bits a[N],b[N],uni[N],row[N],now;
int pa[N],rk[N],fl[N],v[N],n,m;
vector<pii> ans;
char s[N];

int gp(int x){
	return pa[x]==x?x:pa[x]=gp(pa[x]);
}

int solve(bits p){
	if(p.count()<=1) return 1;
	int rt=p._Find_first();
	go(i,rt,p){
		pa[i]=i,fl[i]=0;
		uni[i].reset(),uni[i].set(i);
	}
	rep(i,1,m){
		if(a[i][rt]) continue;
		bits b=a[i]&p;
		int k=b._Find_first();
		b&=~uni[gp(k)];
		for(;b.count();){
			int t=b._Find_first();
			b&=~uni[gp(t)];
			uni[gp(k)]|=uni[gp(t)];
			pa[gp(t)]=gp(k);
		}
	}
	int cnt=0;
	go(i,rt,p){
		rk[++cnt]=i;
		row[i]=b[i]&b[rt];
		v[i]=row[i].count();
	}
	sort(rk+1,rk+cnt+1,[&](int a,int b){
		return v[a]>v[b];
	});
	rep(i,1,cnt){
		int k=rk[i];
		if(!fl[gp(k)]){
			fl[gp(k)]=k;
			ans.pb(mp(rt,k));
			continue;
		}
		if((row[k]&row[fl[gp(k)]])!=row[k])
			return 0;
	}
	go(i,rt,p){
		if(pa[i]==i&&!solve(uni[i])) return 0;
		pa[i]=0;
	}
	return 1;
}

void rmain(){
	read(n),read(m),ans.clear(),now.reset();
	rep(i,1,n) now.set(i),b[i].reset();
	rep(i,1,m){
		scanf("%s",s+1),a[i].reset();
		rep(j,1,n) if(s[j]=='1') 
			a[i].set(j),b[j].set(i);
	}
	if(!solve(now)) return (void)puts("NO");
	puts("YES");
	for(auto x:ans) printf("%d %d\n",x.fi,x.se);
}

int main(){
	int T; read(T);
	while(T--) rmain();
	return 0;
}