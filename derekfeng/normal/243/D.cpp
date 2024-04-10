#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SIZ=10000000;
char buf1[SIZ],*p1=buf1,*p2=buf1;
char gchar(){if(p1==p2)p1=buf1,p2=buf1+fread(buf1,1,SIZ,stdin);return p1==p2?EOF:*p1++;}
int read(){int ret=0,f=1;register int c;while((c=gchar())>'9'||c<'0')if(c=='-')f=-1;ret=c-'0';while((c=gchar())>='0'&&c<='9')ret=ret*10+c-'0';return ret*f;}
int n,vx,vy,a[1003][1003],b[1003][1003];
ll ans;
vector<tuple<int,int,int> >qry;
#define g0 get<0>
#define g1 get<1>
#define g2 get<2>
vector<int>w;
int cnt,n_=1,dat[2097252],d[2097252];
int lb(int x){
	return upper_bound(w.begin(),w.end(),x)-w.begin()-1;
}
int got(int l,int r,int id,int a,int b,int x){
	if(r<a||b<l)return 1e9+1;
	if(a<=l&&r<=b){
		int ret=dat[id];
		dat[id]=max(dat[id],x),d[id]=max(d[id],x);
		return ret;
	}
	int mid=(l+r)/2,ans=1e9+1;
	ans=min(got(l,mid,id*2+1,a,b,x),got(mid+1,r,id*2+2,a,b,x));
	ans=max(ans,d[id]);
	dat[id]=max(d[id],min(dat[id*2+1],dat[id*2+2]));
	return ans;
}
int sol(int L,int R,int x){
	int tmp=got(0,n_-1,0,L,R-1,x);
	return max(0,x-tmp);
}
int main(){
	n=read(),vx=read(),vy=read();
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=read();
	while(vx<0||vy<0){
		swap(vx,vy);vx*=-1;
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)b[i][j]=a[i][j];
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=b[j][n-1-i];
	}
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)qry.push_back(make_tuple(i*vx+j*vy,i,j));sort(qry.begin(),qry.end());
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)w.push_back(i*vy-j*vx);
	sort(w.begin(),w.end());w.erase(unique(w.begin(),w.end()),w.end());
	cnt=(int)w.size();while(n_<cnt)n_<<=1;
	for(auto it:qry){
		int x=g1(it),y=g2(it);
		int L=x*vy-y*vx-vx,R=x*vy-y*vx+vy;
		int tmp=sol(lb(L),lb(R),a[x][y]);
		ans+=tmp;
	}
	printf("%I64d",ans);
}