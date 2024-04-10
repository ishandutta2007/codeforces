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
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,a1[500005],a2[500005],a3[500005];
long long pre1[500005],pre2[500005],suf3[500005];
long long ans=-0x1f1f3f3f3f3f3f3fll,f[500005],tmp[500005];
struct ii{int l,r,v;};vector<ii> v;
void solve(int l,int r,vector<ii> v,long long cov)
{
	if(l==r){
		ff(v,it)if(it->l<=l&&r<=it->r) cov=min(cov,1ll*it->v);
		if(l!=1) f[l]=max(f[l],f[l-1]+a2[l]-cov);
		f[l]=max(f[l],pre1[l]+a2[l]-cov);
		ans=max(ans,f[l]+suf3[l]);
		return;
	}
	int mid=(l+r)/2,i;vector<ii> vl,vr;long long covl=cov,covr=cov;
	ff(v,it){
		if(it->l<=l&&r<=it->r){
			cov=min(cov,1ll*it->v);
			continue;
		}
		it->l=max(it->l,l);
		it->r=min(it->r,r);
		if(it->l<=mid){
			if(it->l<=l&&mid<=it->r) covl=min(covl,1ll*it->v); else vl.push_back(*it);
		}
		if(it->r>mid){
			if(it->l<=mid+1&&r<=it->r) covr=min(covr,1ll*it->v); else vr.push_back(*it);
		}
	}
	covl=min(covl,cov);covr=min(covr,cov);
	solve(l,mid,vl,covl);
	
	fz(i,l,r) tmp[i]=-0x1f1f3f3f3f3f3f3fll;
	fz(i,l,mid) tmp[i]=pre1[i]-pre2[i-1];
	fd(i,mid-1,l) tmp[i]=max(tmp[i],tmp[i+1]);
	ff(v,it){
		if(it->l<=l&&r<=it->r) continue;
		if(it->l<=mid&&it->r>mid) tmp[it->r]=max(tmp[it->r],tmp[it->l]-it->v);
	}
	tmp[r]=max(tmp[r],tmp[l]-cov);
	fd(i,r-1,mid+1) tmp[i]=max(tmp[i],tmp[i+1]);
	fz(i,mid+1,r){
		ans=max(ans,tmp[i]+pre2[i]+suf3[i]);
		f[i]=max(f[i],tmp[i]+pre2[i]);
	}
	
	fz(i,l,r) tmp[i]=-0x1f1f3f3f3f3f3f3fll;
	fz(i,l,mid) tmp[i]=f[i-1]-pre2[i-1];
	tmp[r]=max(tmp[r],tmp[l]-cov);
	fd(i,mid-1,l) tmp[i]=max(tmp[i],tmp[i+1]);
	ff(v,it){
		if(it->l<=l&&r<=it->r) continue;
		if(it->l<=mid&&it->r>mid) tmp[it->r]=max(tmp[it->r],tmp[it->l]-it->v);
	}
	fd(i,r-1,mid+1) tmp[i]=max(tmp[i],tmp[i+1]);
	fz(i,mid+1,r){
		ans=max(ans,tmp[i]+pre2[i]+suf3[i]);
		f[i]=max(f[i],tmp[i]+pre2[i]);
	}
	
	solve(mid+1,r,vr,covr);
}
int main()
{
	read(n);read(m);fz1(i,n)read(a1[i]);fz1(i,n)read(a2[i]);fz1(i,n)read(a3[i]);
	fz1(i,n)pre1[i]=pre1[i-1]+a1[i],pre2[i]=pre2[i-1]+a2[i];fd1(i,n)suf3[i]=suf3[i+1]+a3[i];
	fz1(i,m){int l,r,c;read(l);read(r);read(c);v.push_back((ii){l,r,c});}
	memset(f,-0x1f,sizeof(f));
	solve(1,n,v,0x1f1f3f3f3f3f3f3fll);cout<<ans<<endl;
	return 0;
}