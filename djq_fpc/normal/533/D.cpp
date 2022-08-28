/*
#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int l,r,mid,ans;
int n,m,i,j,a[100005],d[100005],f[100005],g[100005],s[100005];
int rt,lc[40000005],rc[40000005],mx[40000005],tot,typ;
vector<int> v[100005];
void init(int typ)
{
	tot=rt=0;::typ=typ;
}
void upd(int x,int c)
{
	if(typ) mx[x]=min(mx[x],c);
	else mx[x]=max(mx[x],c);
}
void pushup(int x)
{
	if(typ){
		mx[x]=n+1;
		if(lc[x]) mx[x]=min(mx[x],mx[lc[x]]);
		if(rc[x]) mx[x]=min(mx[x],mx[rc[x]]);
	}
	else{
		mx[x]=0;
		if(lc[x]) mx[x]=max(mx[x],mx[lc[x]]);
		if(rc[x]) mx[x]=max(mx[x],mx[rc[x]]);
	}
}
void update(int &x,int l,int r,int y,int c)
{
	if(!x){
		x=++tot;
		lc[x]=rc[x]=0;
		mx[x]=(typ?n+1:0);
	}
	if(l==r){
		upd(x,c);return;
	}
	int mid=(l+r)/2;
	if(y<=mid)update(lc[x],l,mid,y,c); else update(rc[x],mid+1,r,y,c);
	pushup(x);
}
int query(int x,int l,int r,int ql,int qr)
{
	if(!x) return (typ?n+1:0);
	if(ql<=qr) return mx[x];
	int mid=(l+r)/2;
	if(qr<=mid)return query(lc[x],l,mid,ql,qr);
	if(ql>mid) return query(rc[x],mid+1,r,ql,qr);
	int a=query(lc[x],l,mid,ql,qr),b=query(rc[x],mid+1,r,ql,qr);
	if(typ) return min(a,b);return max(a,b);
}
int d1[100005],d2[100005];
int gd(int x)
{
	if(x<0) return d1[-x];
	return d2[x];
} 
bool solve(vector<int> v,int l,int r)
{
	if(l==r||v.empty()) return 0;
	int mid=(l+r)/2,mi=0x7fffffff;
	vector<int> vl,vr;
	ff(v,it){
		if(gd(*it)<=mid){
			vl.push_back(*it);
			if(*it>0) mi=min(mi,a[*it]-g[*it]);
		}
		else{
			vr.push_back(*it);
			if(*it<0&&mi<=a[-*it]+f[-*it]){
				return 1;
			}
		}
	}
	return solve(vl,l,mid)||solve(vr,mid+1,r);
}
bool check()
{
	int i;
	vector<int> v,ally;
	fz0g(i,n+1){
		if(i!=0&&g[i]!=-1){
			d2[i]=a[i]-mid;
			v.push_back(i);
			ally.push_back(d2[i]);
		}
		if(i!=n+1&&f[i]!=-1){
			d1[i]=a[i]+1;
			v.push_back(-i);
			ally.push_back(d1[i]);
		}
	}
	sort(ally.begin(),ally.end());ally.resize(unique(ally.begin(),ally.end())-ally.begin());
	ff(v,it){
		if(*it<0) d1[-*it]=upper_bound(ally.begin(),ally.end(),d1[-*it])-ally.begin();
		else d2[*it]=upper_bound(ally.begin(),ally.end(),d2[*it])-ally.begin();
	}
	return solve(v,1,ally.size());
}
int main()
{
	read(n);
	fz0g(i,n+1) read(a[i]);
	fz1(i,n) {read(d[i]);d[i]*=2;}
	init(0);
	fz1(i,n){
		int t=upper_bound(a+1,a+n+1,a[i]-d[i])-a-1;
		v[t].push_back(i); 
	}
	fz1(i,n){
		if(a[i]-a[s[i]]<=d[i]&&(s[i]==0||a[i]<=a[s[i]]+f[i])){
			f[i]=d[i]-(a[i]-a[s[i]]);
			update(rt,0,1000000001,min(a[i]+f[i],1000000001),i);
		}
		else{
			f[i]=-1;
		}
		ff(v[i],it){
			s[*it]=query(rt,0,1000000001,a[*it],1000000001);
		}
	}
	init(1);
	fz1(i,n) v[i].clear();
	fz1(i,n){
		int t=lower_bound(a+1,a+n+1,a[i]+d[i])-a;
		v[t].push_back(i);
	}
	fz0g(i,n+1) s[i]=n+1;
	fd1(i,n){
		if(a[s[i]]-a[i]<=d[i]&&(s[i]==n+1||a[i]>=a[s[i]]-g[i])){
			g[i]=d[i]-(a[s[i]]-a[i]);
			update(rt,0,1000000001,max(a[i]-g[i],0),i);
		}
		else{
			g[i]=-1;
		}
		ff(v[i],it){
			s[*it]=query(rt,0,1000000001,0,a[*it]);
		}
	}
	f[0]=g[n+1]=1000000001;
	fz1(i,n){
		if(f[i]!=-1&&g[i]!=-1&&(d[i]-f[i])+(d[i]-g[i])<=d[i]){
			puts("0");
			return 0;
		}
	}
	l=0;r=ans=1000000005;
	while(l<r){
		mid=(l+r+1)/2;
		if(check()){
			r=mid-1;
			ans=mid;
		}
		else l=mid;
	}
	printf("%d.%d\n",ans/2,ans%2*5);
	return 0;
} 
*/
#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int ans=0x7fffffff;
int n,m,i,j,a[100005],d[100005],f[100005],g[100005],stk[100005],tp;
int main()
{
	read(n);
	fz0g(i,n+1) read(a[i]);
	fz1(i,n) {read(d[i]);d[i]*=2;d[i]=min(d[i],a[n+1]+1);}
	d[0]=d[n+1]=a[n+1]+1;
	f[0]=g[n+1]=a[n+1]+1;
	f[n+1]=g[0]=-1;
	stk[tp=1]=0;
	fz1(i,n){
		while(tp&&a[stk[tp]]+f[stk[tp]]<a[i]) tp--;
		f[i]=d[i]-(a[i]-a[stk[tp]]);
		if(f[i]<=0){f[i]=-1;continue;}
		while(tp&&a[stk[tp]]+f[stk[tp]]<=a[i]+f[i]) tp--;
		stk[++tp]=i;
	}
	stk[tp=1]=n+1;
	fd1(i,n){
		while(tp&&a[stk[tp]]-g[stk[tp]]>a[i]) tp--;
		g[i]=d[i]-(a[stk[tp]]-a[i]);
		if(g[i]<=0){g[i]=-1;continue;}
		while(tp&&a[stk[tp]]-g[stk[tp]]>=a[i]-g[i]) tp--;
		stk[++tp]=i;
	}
	fz1(i,n){
		if(f[i]>=0&&g[i]>=0&&(d[i]-f[i])+(d[i]-g[i])<=d[i]){
			puts("0");return 0;
		}
	}
	tp=0;
	fz0g(i,n+1){
		if(g[i]>0){
			int l=1,r=tp+1,mid,res=0;
			while(l<r){
				mid=(l+r)/2;
				if(a[stk[mid]]+f[stk[mid]]>=a[i]-g[i]){
					l=mid+1;res=mid;
				}
				else r=mid;
			}
			if(res) ans=min(ans,a[i]-a[stk[res]]);
		}
		if(f[i]>0){
			while(tp&&a[stk[tp]]+f[stk[tp]]<=a[i]+f[i]) tp--;
			stk[++tp]=i;
		} 
	}
	printf("%d.%d\n",ans/2,ans%2*5);
	return 0;
}