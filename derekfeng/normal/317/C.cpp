#include<bits/stdc++.h>
using namespace std;
const int SIZ=50000;
char buf1[SIZ],*p1=buf1,*p2=buf1;
char gchar(){
	if(p1==p2)p1=buf1,p2=buf1+fread(buf1,1,SIZ,stdin);
	return p1==p2?EOF:*p1++;
}
int read(){
	int ret;register int c;
	while((c=gchar())>'9'||c<'0');
	ret=c-'0';
	while((c=gchar())>='0'&&c<='9')ret=ret*10+c-'0';
	return ret;
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,v,e;
int a[303],b[303],p[303];
vector<int>g[303];
bool trees[303],vis[303];
int depth[303];
vector<int>V,ret[3];
void push(int A,int B,int C){
	ret[0].push_back(A);
	ret[1].push_back(B);
	ret[2].push_back(C);
}
void dfsmaketree(int x){
	V.push_back(x),trees[x]=1;
	for(auto to:g[x]){
		if(trees[to])continue;
		p[to]=x,depth[to]=depth[x]+1;
		dfsmaketree(to);
	}
}
bool cmp(int A,int B){
	return depth[A]>depth[B];
}
int dfsinc(int x,int par,int w){
	if(a[x]>=w){
		a[x]-=w;
		push(x,par,w);
		return 0;
	}
	int ww=w-a[x];
	for(auto to:g[x]){
		if(vis[to]||to==par)continue;
		ww=dfsinc(to,x,ww);
		if(ww==0)break;
	}
	a[x]=0;
	int val=w-a[x]-ww;
	int tmp=val+a[x];
	push(x,par,tmp);
	return w-tmp;
}
int dfsdec(int x,int par,int w){
	if(w+a[x]<=v){
		a[x]+=w;
		push(par,x,w);
		return 0;
	}
	int ww=w+a[x]-v;
	for(auto to:g[x]){
		if(vis[to]||to==par)continue;
		ww=dfsdec(to,x,ww);
		if(ww==0)break;
	}
	a[x]=v;
	int val=w+a[x]-v-ww;
	int tmp=v-(a[x]-val);
	push(par,x,tmp);
	return w-tmp;
}
void inc(int x,int w){if(dfsinc(p[x],x,w)>0){puts("NO");exit(0);}}
void dec(int x,int w){if(dfsdec(p[x],x,w)>0){puts("NO");exit(0);}}
int main(){
	n=read(),v=read(),e=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=0;i<e;i++){
		int x=read(),y=read();
		g[x].push_back(y),g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)if(!trees[i]){
		V.clear();
		depth[i]=1,dfsmaketree(i); 
		sort(V.begin(),V.end(),cmp);
		for(auto x:V){
			vis[x]=1;
			if(a[x]==b[x])continue;
			if(a[x]!=b[x]&&p[x]<1){puts("NO");return 0;}
			if(a[x]<b[x])inc(x,b[x]-a[x]);
			else dec(x,a[x]-b[x]);
		}
	}
	write((int)ret[0].size());
	for(int i=0;i<(int)ret[0].size();i++){
		puts("");
		for(int j=0;j<3;j++)write(ret[j][i]),putchar(' ');
	}
}