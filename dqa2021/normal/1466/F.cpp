#include<bits/stdc++.h>
#define pb push_back
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
typedef long long ll;
const int mod=1e9+7;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,int y){x=upd(x+y-mod);}
inline void iadd(int &x,int y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}

int n,m;
int p[500010];
int fat[500010];
int find(int x){
	return fat[x]?fat[x]=find(fat[x]):x;
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if (x==y) return;
	fat[x]=y;
}
bool ins(int a,int b){
	while (1){
		if (a==b) a=b=-1;
		if (a<b) swap(a,b);
		if (!~a) return 0;
		if (!p[a]){
			if (~b&&p[b]) b=p[b];
			p[a]=b;
			if (~b){
				merge(a,b);
			}
			else merge(a,m+1);
			return 1;
		}
		int c=p[a];
		if (~c){
			c=find(c);
			if (c==m+1) c=-1;
		}
		a=c;
	}
}
void solve(){
	n=read(),m=read();
	vector<int> S;
	for (int i=1;i<=n;i++){
		int t=read();
		int a=read(),b=-1;
		if (t>1) b=read();
		if (ins(a,b)) S.pb(i);
	}
	printf("%d %d\n",qpow(2,int(S.size())),int(S.size()));
	for(int x: S) printf("%d ",x);
	puts("");
}
int main()
{
	for (int T=1;T--;) solve();
}