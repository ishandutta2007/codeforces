#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);++(i))
#define fd1(i,n) for ((i)=(n);(i)>=1;--(i))
#define fz0g(i,n) for ((i)=0;(i)<=(n);++(i))
#define fd0g(i,n) for ((i)=(n);(i)>=0;--(i))
#define fz0k(i,n) for ((i)=0;(i)<(n);++(i))
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;--(i))
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
long long k,qzh[100005],val[100005],l,r,mid,ans;
long long n,i,j,a[100005],seq[100005],rk[100005],rt[100005],lc[5000005],rc[5000005];
long long mx[100005][19],mi[100005][19];
long long lg[100005],cnt,pr[100005],cov[100005];
bool cmp(long long x,long long y)
{
	return qzh[x]<qzh[y];
}
long long querymx(long long l,long long r)
{
	long long ans=-0x3f3f3f3f3f3f3f3fll;
	if(l<1){
		ans=0;
		l++;
	}
	if(l<=r){
		long long t=lg[r-l+1];
		return max(ans,max(mx[l][t],mx[r-(1<<t)+1][t]));
	}
	return ans;
}
long long querymi(long long l,long long r)
{
	long long ans=0x3f3f3f3f3f3f3f3fll;
	if(l<1){
		ans=0;
		l++;
	}
	if(l<=r){
		long long t=lg[r-l+1];
		return min(ans,min(mi[l][t],mi[r-(1<<t)+1][t]));
	}
	return ans;
}
struct seg
{
	long long sum;
	long long sz,mx;
}s[5000005];
void update(long long &x,long long l,long long r,long long y)
{
	cnt++;s[cnt]=s[x];lc[cnt]=lc[x];rc[cnt]=rc[x];x=cnt;
	s[x].sz++;s[x].mx=max(s[x].mx,seq[y]);s[x].sum+=val[y];
	if(l==r) return;
	long long mid=(l+r)/2;
	if(y<=mid) update(lc[x],l,mid,y); else update(rc[x],mid+1,r,y);
}
seg tmp;
void query(long long x,long long l,long long r,long long v)
{
	if(!x)return;
	if(val[l]>v){
		tmp.mx=max(tmp.mx,s[x].mx);
		tmp.sz+=s[x].sz;
		tmp.sum+=s[x].sum;
		return;
	}
	if(l==r) return;
	long long mid=(l+r)/2;
	if(v<val[mid]) query(lc[x],l,mid,v);
	query(rc[x],mid+1,r,v);
}
struct ii
{
	long long ans;
	long long cnt;
}dp[100005];
struct itv
{
	long long l,r;
}ss[100005];
ii solve(long long d)
{
	ii ans=(ii){0,0};long long i;
	memset(pr,0,sizeof(pr));
	fd1(i,n){
		tmp=(seg){0,0,0};
		query(rt[i],1,n,qzh[i-1]-d);
		pr[i]=tmp.mx;
		ans.ans+=tmp.sum-(qzh[i-1]-d)*tmp.sz;
		ans.cnt+=tmp.sz;
	}
	memset(cov,0,sizeof(cov));
	long long lst=0;
	fz1(i,n){
		if(pr[i]>lst){
			lst=max(lst,i-1);
			while(lst<pr[i]){
				cov[++lst]=1;
			}
		}
	}
	long long cc=0;
	if(!cov[1]) ss[++cc]=(itv){1,0};
	fz1(i,n){
		if(cov[i]){
			if(i==1||!cov[i-1]) ss[++cc]=(itv){i,0};
			if(i==n||!cov[i+1]) ss[cc].r=i;
		}
		else{
			if(i>1&&!cov[i-1]){
				ss[++cc]=(itv){i+1,i};
			}
		}
	}
	if(!cov[n]) ss[++cc]=(itv){n+1,n};
	if(cc==1) return ans;
	ii mx=(ii){-0x3f3f3f3f3f3f3f3fll,0};
	fz1(i,cc){
		if(i==1) dp[i]=(ii){0,0};
		else{
			dp[i].ans=mx.ans+querymx(ss[i].l-1,ss[i].r)+d;
			dp[i].cnt=mx.cnt+1;
		}
		ii t;
		t.ans=dp[i].ans-querymi(ss[i].l-1,ss[i].r);
		t.cnt=dp[i].cnt;
		if(t.ans>mx.ans||t.ans==mx.ans&&t.cnt<mx.cnt){
			mx=t;
		}
	}
	return (ii){ans.ans+dp[cc].ans,ans.cnt+dp[cc].cnt};
}
signed main()
{
	fz(i,2,100000) lg[i]=lg[i/2]+1;
	scanf("%lld%lld",&n,&k);
	fz1(i,n){
		scanf("%lld",&a[i]);
//		a[i]=-50000;
		qzh[i]=qzh[i-1]+a[i];
		seq[i]=i;
	}
	sort(seq+1,seq+n+1,cmp);
	fz1(i,n){
		rk[seq[i]]=i;
		val[i]=qzh[seq[i]];
	}
	fd1(i,n){
		rt[i]=rt[i+1];
		update(rt[i],1,n,rk[i]);
	}
	fz1(i,n) mi[i][0]=mx[i][0]=qzh[i];
	fz1(j,18)fz1(i,n-(1<<j)+1){
		mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
		mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
	}
	solve(3);
	l=-1e15;r=1e15;
	while(l<r){
		mid=(l+r)>>1;
		ii s=solve(mid);
		if(s.cnt<=k){
			l=mid+1;
			ans=s.ans-1ll*k*mid;
		}
		else{
			r=mid;
		}
	}
	printf("%lld\n",ans);
	return 0;
}