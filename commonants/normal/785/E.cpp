#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define bel(i) ((i)>>10)
#define lbt(i) ((i)&-(i))
using namespace std;
typedef long long LL;
int n,q;
const int MX=200011,B=1024;
int cnt[MX/B+2][MX],cntblk[MX/B+2][MX],a[MX];
inline void add(int *c,int *s,int x,int d){
	for(int i=x;bel(i)==bel(x)&&i<=n;i++)c[i]+=d;
	for(int i=bel(x);i<=bel(n);i++)s[i]+=d;
}
inline int que(int *c,int *s,int x){
	return bel(x)?s[bel(x)-1]+c[x]:c[x];
}
LL ans=0LL;
inline int rd(){
	int x=0;char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int main(){
	n=rd(),q=rd();
	for(int i=1;i<=n;i++)a[i]=i;
	for(int i=1;i<=n;i++)add(cnt[bel(i)],cntblk[bel(i)],a[i],1);
	for(int i=1;i<=q;i++){
		int l=rd(),r=rd();
		if(l==r)goto E;
		if(l>r)swap(l,r);
		if(a[l]<a[r]){
			ans++;
			if(bel(l+1)==bel(r-1))for(int j=l+1;j<r;j++)ans+=2*(a[j]>a[l]&&a[j]<a[r]);
			else {
				for(int j=l+1;bel(j)==bel(l+1);j++)ans+=2*(a[j]>a[l]&&a[j]<a[r]);
				for(int j=r-1;bel(j)==bel(r-1);j--)ans+=2*(a[j]>a[l]&&a[j]<a[r]);
				for(int j=bel(l+1)+1;j<bel(r-1);j++)ans+=2*(que(cnt[j],cntblk[j],a[r])-que(cnt[j],cntblk[j],a[l]));
			}
		}else{
			ans--;
			if(bel(l+1)==bel(r-1))for(int j=l+1;j<r;j++)ans-=2*(a[j]>a[r]&&a[j]<a[l]);
			else {
				for(int j=l+1;bel(j)==bel(l+1);j++)ans-=2*(a[j]>a[r]&&a[j]<a[l]);
				for(int j=r-1;bel(j)==bel(r-1);j--)ans-=2*(a[j]>a[r]&&a[j]<a[l]);
				for(int j=bel(l+1)+1;j<bel(r-1);j++)ans-=2*(que(cnt[j],cntblk[j],a[l])-que(cnt[j],cntblk[j],a[r]));
			}
		}
		add(cnt[bel(l)],cntblk[bel(l)],a[l],-1);
		add(cnt[bel(r)],cntblk[bel(r)],a[r],-1);
		swap(a[l],a[r]);
		add(cnt[bel(l)],cntblk[bel(l)],a[l],1);
		add(cnt[bel(r)],cntblk[bel(r)],a[r],1);
E:		printf("%lld\n",ans);
	}
	return 0;
}