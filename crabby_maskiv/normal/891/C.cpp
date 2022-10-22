#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
namespace nqio{const unsigned R=4e5,W=4e5;char*a,*b,i[R],o[W],*c=o,*d=o+W,h[40],*p=h,y;bool s;struct q{void r(char&x){x=a==b&&(b=(a=i)+fread(i,1,R,stdin),a==b)?-1:*a++;}void f(){fwrite(o,1,c-o,stdout);c=o;}~q(){f();}void w(char x){*c=x;if(++c==d)f();}q&operator>>(char&x){do r(x);while(x<=32);return*this;}q&operator>>(char*x){do r(*x);while(*x<=32);while(*x>32)r(*++x);*x=0;return*this;}template<typename t>q&operator>>(t&x){for(r(y),s=0;!isdigit(y);r(y))s|=y==45;if(s)for(x=0;isdigit(y);r(y))x=x*10-(y^48);else for(x=0;isdigit(y);r(y))x=x*10+(y^48);return*this;}q&operator<<(char x){w(x);return*this;}q&operator<<(char*x){while(*x)w(*x++);return*this;}q&operator<<(const char*x){while(*x)w(*x++);return*this;}template<typename t>q&operator<<(t x){if(!x)w(48);else if(x<0)for(w(45);x;x/=10)*p++=48|-(x%10);else for(;x;x/=10)*p++=48|x%10;while(p!=h)w(*--p);return*this;}}qio;}using nqio::qio;
int n,m,Q;
int uu[N],vv[N],ww[N];
inline bool cmp(const int &x,const int &y){
	return ww[x]<ww[y];
}
vector<int> q[N];
bool ans[N];
vector<int> a[N];
int fa[N],sz[N];
int id[N];
int rt(int u){
	if(fa[u]==u) return u;
	return rt(fa[u]);
}
int stk[N],top;
bool merge(int u,int v){
	u=rt(u);v=rt(v);
	if(u==v) return 0;
	if(sz[u]>sz[v]) swap(u,v);
	fa[u]=v;
	stk[++top]=u;
	sz[v]+=sz[u];
	return 1;
}
int main(){
	int i,j;
	qio>>n>>m;
	for(i=1;i<=m;i++)
		qio>>uu[i]>>vv[i]>>ww[i];
	for(i=1;i<=m;i++) id[i]=i;
	sort(id+1,id+m+1,cmp);
	int Q;qio>>Q;
	for(i=1;i<=Q;i++){
		int k;qio>>k;q[i].resize(k);
		for(j=0;j<k;j++) qio>>q[i][j];
		sort(q[i].begin(),q[i].end(),cmp);
		for(j=0;j<k;j++){
			if(j==0||ww[q[i][j]]>ww[q[i][j-1]])
				a[ww[q[i][j]]].push_back(i);
		}
	}
	for(i=1;i<=n;i++)
		fa[i]=i,sz[i]=1;
	for(i=1;i<=Q;i++) ans[i]=1;
	int pos=1;
	for(i=1;i<N;i++){
		ww[0]=i;
		for(auto c:a[i]){
			int x=lower_bound(q[c].begin(),q[c].end(),0,cmp)-q[c].begin();
			top=0;
			for(j=x;j<q[c].size()&&ww[q[c][j]]==i;j++)
				ans[c]&=merge(uu[q[c][j]],vv[q[c][j]]);
			while(top){
				int u=stk[top];top--;
				sz[fa[u]]-=sz[u];
				fa[u]=u;
			}
		}
		while(pos<=m&&ww[id[pos]]==i){
			merge(uu[id[pos]],vv[id[pos]]);
			pos++;
		}
		top=0;
	}
	for(i=1;i<=Q;i++){
		if(ans[i]) qio<<"YES\n";
		else qio<<"NO\n";
	}
	return 0;
}