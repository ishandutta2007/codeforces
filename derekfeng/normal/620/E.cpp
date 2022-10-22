#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,n_=1,q,cnt,ld[400004],rd[400004],cl[400004],tms[1048600],clf[1048600],tt[1048600];
ll dat[1048600];
vector<int>g[400004];
void dfs(int x,int par){
	ld[x]=cnt;cnt++;
	for (int i=0;i<g[x].size();i++) if (g[x][i]!=par)
		dfs(g[x][i],x);
	rd[x]=cnt-1;
}
void init(int l,int r,int id){
	if (l==r) return;
	init(l,(l+r)/2,id*2+1),init((l+r)/2+1,r,id*2+2);
	dat[id]=dat[id*2+1]|dat[id*2+2];
}
void upd(int l,int r,int id,int a,int b,int c,int Tc){
	if (r<a || b<l) return;
	if (a<=l && r<=b){
		dat[id]=(1ll<<c);
		tms[id]=Tc;
		clf[id]=c,tt[id]=Tc;
		return;
	}
	if (tms[2*id+1]<tt[id]) dat[id*2+1]=(1ll<<clf[id]),tms[2*id+1]=tt[2*id+1]=tt[id],clf[id*2+1]=clf[id];
	if (tms[2*id+2]<tt[id]) dat[id*2+2]=(1ll<<clf[id]),tms[2*id+2]=tt[2*id+2]=tt[id],clf[id*2+2]=clf[id];
	upd(l,(l+r)/2,id*2+1,a,b,c,Tc),upd((l+r)/2+1,r,id*2+2,a,b,c,Tc);dat[id]=dat[id*2+1]|dat[id*2+2];
	tms[id]=Tc;
}
pair<int,ll> ans(int l,int r,int id,int a,int b){
	if (r<a || b<l) return make_pair(1e9,0);
	if (a<=l && r<=b) return make_pair(tms[id],dat[id]);
	ll res=0;
	pair<int,ll> a1=ans(l,(l+r)/2,id*2+1,a,b),a2=ans((l+r)/2+1,r,id*2+2,a,b);
	if (a1.first<tt[id]) res|=(1ll<<clf[id]); 
	else res|=a1.second;
	if (a2.first<tt[id]) res|=(1ll<<clf[id]); 
	else res|=a2.second;
	return make_pair(tt[id],res);
}
int got(ll x){
	if (x==0) return 0;
	return got(x-(x&-x))+1;
}
int main(){
	read(n),read(q);while (n_<n) n_<<=1;
	for (int i=1;i<=n;i++) read(cl[i]),cl[i]--;
	for (int i=0;i<n-1;i++){
		int x,y;read(x),read(y);
		g[x].push_back(y),g[y].push_back(x);  
	}
	memset (tt,-1,sizeof(tt)); 
	dfs(1,-1);
	for (int i=1;i<=n;i++) dat[ld[i]+n_-1]=(1ll<<cl[i]);
	init(0,n_-1,0);
	while (q--){
		int oper;
		read(oper);
		if (oper==1){
			int x,c;read(x),read(c),c--;
			upd(0,n_-1,0,ld[x],rd[x],c,4e5-q);
		}else{
			int x;read(x);
			write(got(ans(0,n_-1,0,ld[x],rd[x]).second)),puts("");
		}
	}
}