#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=613;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666,mo1=1e9+7,mo2=1e9+9,b1=10007,b2=19260817;
int a[N],n,q;char S[N];
int nxt[N],pre[N],nxt1[N],pre1[N],qz0[N];
int b[N],len,val[N];
Pii dp[N],mi[N];
void ini(int len){
	mi[0]=mp(1,1);
	rep(i,1,len)mi[i].fi=1ll*mi[i-1].fi*b1%mo1,mi[i].se=1ll*mi[i-1].se*b2%mo2;
	rep(i,1,len)
		dp[i].fi=(1ll*dp[i-1].fi*b1+val[i])%mo1,
		dp[i].se=(1ll*dp[i-1].se*b2+val[i])%mo2;
}
Pii calc(int l, int r){
	return mp((dp[r].fi-1ll*dp[l-1].fi*mi[r-l+1].fi+1ll*mo1*mo1)%mo1,(dp[r].se-1ll*dp[l-1].se*mi[r-l+1].se+1ll*mo2*mo2)%mo2);
}
bool ck(int l1, int r1, int l2, int r2){
	if(qz0[r1]-qz0[l1-1]!=qz0[r2]-qz0[l2-1])return 0;
	if(a[l1]&&nxt[l1]>r1||a[l2]&&nxt[l2]>r2){
		return (a[l1]&&nxt[l1]>r1)==(a[l2]&&nxt[l2]>r2);
	}
//	printf("q %d %d %d %d\n",l1,r1,l2,r2);
	bool flag=0;
	if(a[l1]){
		if((nxt[l1]-l1)%2){
			flag^=1;
		}
		l1=nxt[l1];
	}
	if(a[l2]){
		if((nxt[l2]-l2)%2)flag^=1;l2=nxt[l2];
	}
//	printf("q %d %d %d %d\n",l1,r1,l2,r2);
	if(flag)return 0;
	if(a[r1]){
		if((r1-pre[r1])%2)flag^=1;r1=pre[r1];
	}
	if(a[r2]){
		if((r2-pre[r2])%2)flag^=1;r2=pre[r2];
	}
//	printf("q %d %d %d %d\n",l1,r1,l2,r2);
	if(flag)return 0;
//	if(nxt1[l1]>r1||nxt1[l2]>r2)return (nxt1[l1]>r1)==(nxt1[l2]>r2);
//	if(nxt1[l1]-l1!=nxt1[l2]-l2)return 0;
//	if(r1-pre1[r1]!=r2-pre1[r2])return 0;
	int L1=lower_bound(b+1,b+len+1,l1)-b;
	int L2=lower_bound(b+1,b+len+1,l2)-b;
	int R1=lower_bound(b+1,b+len+1,r1)-b-1;
	int R2=lower_bound(b+1,b+len+1,r2)-b-1;
	if(L1>R1||L2>R2)return (L1>R1)==(L2>R2);
	if(R1-L1!=R2-L2)return 0;
	if(qz0[b[L1]]-qz0[l1]!=qz0[b[L2]]-qz0[l2])return 0;
	if(qz0[r1]-qz0[b[R1]]!=qz0[r2]-qz0[b[R2]])return 0;
	return calc(L1,R1-1)==calc(L2,R2-1);
}
int main() {
	read(n);scanf("%s",S+1);
	rep(i,1,n)a[i]=S[i]=='1';
	rep(i,1,n){pre[i]=pre[i-1];if(!a[i-1])pre[i]=i-1;}
	nxt[n+1]=n+1;per(i,n,1){nxt[i]=nxt[i+1];if(!a[i+1])nxt[i]=i+1;}
	rep(i,1,n){pre1[i]=pre1[i-1];if(a[i-1])pre1[i]=i-1;}
	nxt1[n+1]=n+1;per(i,n,1){nxt1[i]=nxt1[i+1];if(a[i+1])nxt1[i]=i+1;}
	rep(i,1,n)if(a[i]){
		int j=i;while(j+1<=n&&a[j+1])j++;
		//[i,j]
		if(j-i+1&1)b[++len]=i;
		i=j;
	}
	rep(i,1,len-1)rep(j,b[i],b[i+1]-1){
		val[i]+=a[j]==0;
	}
	ini(len-1);
	rep(i,1,n)qz0[i]=qz0[i-1]+(a[i]==0);
	int q;read(q);while(q--){
		int l1,l2,r1,r2,L;
		read(l1);read(l2);read(L);
		r1=l1+L-1;r2=l2+L-1;
		printf("%s\n",ck(l1,r1,l2,r2)?"Yes":"No");
	}
	return 0;
}