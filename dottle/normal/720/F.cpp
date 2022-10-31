#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
const int N=100005,inf=1e12;
using namespace std;

int n,k;
int a[N],s[N],mins[N],ss[N],sd[N];
int b[N],ls[N],sb;
pr f[N],g[N];

int getpos(int k){return upper_bound(b,b+sb,k)-b;}

struct BIT_ADD{
    int a[N];
    void clear(){memset(a,0,sizeof(a));}
    void add(int k,int p){while(k<=sb+1)a[k]+=p,k+=k&-k;}
    int sum(int k){int ans=0;while(k)ans+=a[k],k-=k&-k;return ans;}
}SM,SP;
struct BIT_MAX{
    int a[N];
    void clear(){for(auto&x:a)x=inf;}
    void add(int k,int p){while(k<=sb+1)a[k]=min(a[k],p),k+=k&-k;}
    int sum(int k){int ans=inf;while(k)ans=min(ans,a[k]),k-=k&-k;return ans;}
}MN;
struct BIT_PR{
    pr a[N];
    void clear(){for(auto&x:a)x={-inf,0};}
    void add(int k,pr p){k=n-k+1;while(k<=n+1)a[k]=max(a[k],p),k+=k&-k;}
    pr sum(int k){k=n-k+1;pr ans={-inf,0};while(k)ans=max(ans,a[k]),k-=k&-k;return ans;}
}MP;

pr getv(int mid){//sumi-sumj>=mid
	SM.clear();
	SP.clear();
	MN.clear();
	MP.clear();
	MN.add(ls[0],0);
	SM.add(ls[0],1);
	MP.add(0,f[0]);
	f[0]={0,0};
	g[0]={0,1};
	int sums=0,sumd=0;
	for(int i=1;i<=n;i++){
		int np=getpos(s[i]-mid);
		int ns=0,nd=SM.sum(np);
		sums+=nd*(s[i]-mid)+SP.sum(np);
		sumd+=nd;
		int maxp=MN.sum(np);
		pr f0={-inf,0},f1={-inf,0};
		if(maxp==inf)maxp=i;
		if(maxp)f0=g[maxp-1],f0.first+=s[i]-mid;
		f1=MP.sum(maxp);
		f[i]=max(f0,f1);
		MP.add(i,f[i]);
		g[i]=f[i];
		g[i].first-=mins[i];
		g[i].second+=1;
		g[i]=max(g[i],g[i-1]);
		SM.add(ls[i],1);
		SP.add(ls[i],-s[i]);
		MN.add(ls[i],i);
	}
	f[n].first+=sums,f[n].second+=sumd;
	return f[n];
}
void calc(){
	int l=-inf,r=inf,ans=-inf;
	while(l<=r){
		int mid=(l+r)>>1;
		if(getv(mid).second>=k)l=mid+1,ans=mid;
		else r=mid-1;
	}
	auto res=getv(ans);
	cout<<res.first+ans*k<<endl;
}
void input(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]+a[i],mins[i]=min(s[i],mins[i-1]);
	for(int i=1;i<=n;i++)b[i]=s[i];
	sort(b,b+1+n);sb=unique(b,b+1+n)-b;
	for(int i=n;i>=0;i--)
		ls[i]=lower_bound(b,b+sb,s[i])-b+1;
}
main(){
	input();
	calc();
}