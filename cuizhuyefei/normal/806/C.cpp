#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 233333;
ll n,a[N];int cnt1[50],cnt2[50],len=-1;
inline bool ck(int cnt){
	int a[50],b[50],mx[50];memcpy(a,cnt1,200);memcpy(b,cnt2,200);memset(mx,0,200);
	mx[0]=cnt;rep(i,1,len)mx[i]=min(mx[i-1],a[i]);
	rep(i,0,len)b[max(i-1,0)]+=a[i]-mx[i];
	rep(i,0,len)a[i]=mx[i]-mx[i+1];
	cnt=0;per(i,len,0){cnt+=a[i]-b[i];if(cnt<0)return 0;}
	return 1;
//	for(int i=0,mx=cnt;i<=len;i++){mx=min(mx,a[i]);b[i-1]+=a[i]-mx;a[i]=mx;}
}
int main() {
	read(n);rep(i,1,n)read(a[i]);int r=0;
	for(int p=1;1LL<<(len+1)<=a[n];){
		len++;while(p<=n&&a[p]==(1LL<<len))cnt1[len]++,p++;
		while(p<=n&&a[p]<(1LL<<(len+1)))cnt2[len]++,p++;
	//	printf("%d:%d %d\n",len,cnt1[len],cnt2[len]);
	}
	rep(i,1,n)r+=a[i]==1;if(!ck(r)){puts("-1");return 0;}
	int L=1,R=r,res=r;
	while(L<=R){
		int mid=(L+R)>>1;
		if(ck(mid))res=mid,R=mid-1;else L=mid+1;
	}
	rep(i,res,r)printf("%d ",i);
	return 0;
}