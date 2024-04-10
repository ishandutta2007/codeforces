#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,tp,stk[N],a[N],ls[N],rs[N];
ll s[N],st0[N][18],st1[N][18];
inline void init(){
	for(int i=0;i<=n;i++)st0[i][0]=st1[i][0]=s[i],ls[i]=rs[i]=0;
	for(int j=1;(1<<j)<=n+1;j++)
		for(int i=0;i+(1<<j)-1<=n;i++){
			st0[i][j]=min(st0[i][j-1],st0[i+(1<<j-1)][j-1]);
			st1[i][j]=max(st1[i][j-1],st1[i+(1<<j-1)][j-1]);	
		}
	tp=0;
	for(int i=1;i<=n;i++){
		while(tp && a[stk[tp]]<a[i])ls[i]=stk[tp--];
		rs[stk[tp]]=i,stk[++tp]=i;
	}
}
bool ok;
inline ll qmin(int l,int r){
	int k=__lg(r-l+1);
	return min(st0[l][k],st0[r-(1<<k)+1][k]);	
}
inline ll qmax(int l,int r){
	int k=__lg(r-l+1);
	return max(st1[l][k],st1[r-(1<<k)+1][k]);	
}
void dfs(int x,int l,int r){
	if(!x)return;
	ok&=max(s[x]-qmin(l-1,x-1),qmax(x,r)-s[x-1])<=a[x];
	dfs(ls[x],l,x-1),dfs(rs[x],x+1,r);
}
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),s[i]=s[i-1]+a[i];
	init(),ok=true,dfs(max_element(a+1,a+n+1)-a,1,n);
	puts(ok?"YES":"NO");
}
int main(){	
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while(test--)work();
	return 0;
}