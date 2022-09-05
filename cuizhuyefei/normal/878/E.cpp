#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 303000, mo = 1e9+7;
int n,q,a[N];
struct que{int l,r,index;} Q[N];
bool cmp(que a, que b) {return a.r<b.r;}
int f[N];
ll top,val[N],pos[N],mi[N],sum[N],ans[N],S[N],imi[N];
inline int find(int x) {
	if (f[x]==x) return x;
	f[x]=find(f[x]); return f[x];
}
int main() { //freopen("1.in","r",stdin);
	read(n); read(q);
	rep(i,1,n) read(a[i]),f[i]=i;
	rep(i,1,q) read(Q[i].l),read(Q[i].r),Q[i].index=i;
	sort(Q+1,Q+q+1,cmp); int p=0;
	mi[0]=1; rep(i,1,n) mi[i]=(mi[i-1]<<1)%mo;
	imi[0]=1; imi[1]=500000004; rep(i,2,n) imi[i]=imi[i-1]*imi[1]%mo;
	rep(i,1,n) S[i]=(S[i-1]+a[i]*mi[i-1])%mo,S[i]=S[i]<0?S[i]+mo:S[i];
	rep(i,1,n) {
		if (!top){pos[++top]=i; val[top]=(a[i]<<1); sum[top]=val[top]%mo;}
		else {
			pos[++top]=i; val[top]=(a[i]<<1); sum[top]=sum[top-1]+val[top]; sum[top]%=mo;
			bool Big=0;
			while (top-1>=1&&(val[top]>0||Big)) {
				f[find(pos[top-1])]=find(pos[top]);
			//	ll cnt=0,t=val[top]; while (t>1) {t/=10; cnt++;}
			//	if (pos[top-1]-pos[top-2]>=30) cnt+=30;
			//	else {t=1<<pos[top-1]-pos[top-2]; while (t>1) {t/=10; cnt++;}}
				if (Big||pos[top-1]-pos[top-2]>=31||val[top-1]+val[top]*mi[pos[top-1]-pos[top-2]]>2e9)
					val[top-1]=(val[top-1]+val[top]*mi[pos[top-1]-pos[top-2]])%mo,Big=1;
				else val[top-1]=(val[top-1]+val[top]*mi[pos[top-1]-pos[top-2]]);
				sum[top-1]=(sum[top-2]+val[top-1])%mo; pos[top-1]=pos[top]; top--;
			}
		}
	//	printf("%d : ",top); rep(i,1,top) printf("%d %lld ",pos[i],val[i]); puts("");
	//	rep(i,1,n) printf("%d ",find(i)); puts("");
		while (p+1<=q&&Q[p+1].r==i) {
			p++; int x=Q[p].index;
			int lst=find(Q[p].l),b;
			int l=1,r=top;
			while (l<=r) {
				int mid=(l+r)>>1;
				if (pos[mid]==lst) {b=mid; break;}
				if (pos[mid]<lst) l=mid+1; else r=mid-1;
			}
		//	printf("b lst = %d %d\n",b,lst);
			ans[x]=(sum[top]-sum[b]+(S[lst]-S[Q[p].l-1])*imi[Q[p].l-1])%mo;
		}
	}
	rep(i,1,q) printf("%lld\n",(ans[i]%mo+mo)%mo);
	return 0;
}