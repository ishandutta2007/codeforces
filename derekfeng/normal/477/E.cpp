#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
namespace IO{
	const int SIZ=(1<<25);
	char buf1[SIZ],*p1=buf1,*p2=buf1;
	char buf2[SIZ],*p3=buf2,*p4=buf2;
	char gchar(){if(p1==p2)p1=buf1,p2=buf1+fread(buf1,1,SIZ,stdin);return p1==p2?EOF:*p1++;}
	void pchar(char c){*p4++=c;if(p4-p3==SIZ)fwrite(buf2,1,SIZ,stdout),p4=buf2;}
	void output(){fwrite(buf2,1,p4-p3,stdout);}
}
using namespace IO;
int read(){int ret=0;int c;while((c=gchar())>'9'||c<'0');ret=c-'0';while((c=gchar())>='0'&&c<='9')ret=ret*10+c-'0';return ret;}
void write(int x){if(x>9)write(x/10);pchar(x%10+'0');}
const int N=4e5+4,B=19,inf=1e9;
int n,q,a[N],ans,l[N],r[N],x[N],y[N];
int sx,sy,tx,ty,res[N];pii tmp;
int par[N][B+1],rap[N][B+1];
int val[N][B+1],lav[N][B+1];
void init(){
	a[0]=a[n+1]=-inf;
	for(int i=0;i<B;i++)par[n+1][i]=n+1;
	stack<int>s1,s2;
	s1.push(0);for(int i=1;i<=n;i++){
		while(!s1.empty()&&a[s1.top()]>=a[i])s1.pop();
		par[i][0]=s1.top(),val[i][0]=a[i]-i-i,s1.push(i);
	}
	s2.push(n+1);for(int i=n;i;i--){
		while(!s2.empty()&&a[s2.top()]>=a[i])s2.pop();
		rap[i][0]=s2.top(),lav[i][0]=a[i]+i+i,s2.push(i);
	}
	for(int i=1;i<=B;i++)
		for(int j=1;j<=n;j++){
			par[j][i]=par[par[j][i-1]][i-1];
			rap[j][i]=rap[rap[j][i-1]][i-1];
			val[j][i]=min(val[j][i-1],val[par[j][i-1]][i-1]);
			lav[j][i]=min(lav[j][i-1],lav[rap[j][i-1]][i-1]);
		}
}
int get_min(int l,int r){
	for(int i=B;~i;i--)
		if(par[r][i]>=l)r=par[r][i];
	return r;
}
pii qry(int p,int v,int lim){
	int cur=inf;
	for(int i=B;~i;i--){
		int nx=par[p][i];
		if(nx>=lim&&a[nx]>=v)
			cur=min(val[p][i],cur),p=nx;
	}
	return {p,min(val[p][0],cur)};
}
pii yrq(int p,int v,int lim){
	int cur=inf;
	for(int i=B;~i;i--){
		int nx=rap[p][i];
		if(nx<=lim&&a[nx]>=v)
			cur=min(lav[p][i],cur),p=nx;
	}
	return {p,min(lav[p][0],cur)};
}
void calc(){
	int pos=get_min(sx,tx);
	int pos_y=min(sy,a[pos]);
	ans=min(ans,tx-sx+abs(pos_y-ty));
	tmp=yrq(tx,ty,n);
	ans=min(ans,tmp.se-sx-tx-ty+(pos_y<ty));
	int z=rap[tmp.fi][0];
	if(z<=n)ans=min(ans,z+z-sx-tx+ty-a[z]+(pos_y<ty));
	int g=qry(sx,a[pos],1).fi;
	g=par[g][0];
	if(g>0){
		if(a[g]>=ty){
			tmp=qry(g,ty,1);
			ans=min(ans,tmp.se+sx+tx-ty+(pos_y<ty));
			z=par[tmp.fi][0];
			if(z>0)ans=min(ans,sx+tx-z-z+ty-a[z]+(pos_y<ty));
		}else ans=min(ans,sx+tx-g-g+ty-a[g]+(pos_y<ty));
	}
	int tf=qry(tx,ty,sx).fi;
	ans=min(ans,tx-sx+a[tf]-ty+1);
	tf=par[tf][0];
	if(tf>=sx)ans=min(ans,tx-sx+ty-a[tf]+1);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	init();q=read();
	for(int i=1;i<=q;i++)l[i]=read(),x[i]=read(),r[i]=read(),y[i]=read();
	for(int i=1;i<=q;i++)if(l[i]<=r[i]){
		sx=l[i],sy=x[i],tx=r[i],ty=y[i];
		ans=ty+tx-sx+1,calc(),res[i]=ans;
	}reverse(a+1,a+n+1),init();
	for(int i=1;i<=q;i++)l[i]=n-l[i]+1,r[i]=n-r[i]+1;
	for(int i=1;i<=q;i++)if(l[i]<r[i]){
		sx=l[i],sy=x[i],tx=r[i],ty=y[i];
		ans=ty+tx-sx+1,calc(),res[i]=ans;
	}for(int i=1;i<=q;i++)write(res[i]),pchar('\n');
	output();
}