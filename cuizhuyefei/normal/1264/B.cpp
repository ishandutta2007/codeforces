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
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666;
int n,c[N],a[N];
int ans[N],len;
void solve(int s, int t){
//	rep(i,0,3){if(a[i]&1)return;a[i]/=2;}
	rep(i,0,3)a[i]*=2;a[s]--;a[t]--;
	a[1]-=a[0];a[2]-=a[1];
	if(a[2]!=a[3])return;
	rep(i,0,2)if(a[i]<0)return;
	rep(i,s,t-1)if(a[i]%2==0)return;
	rep(i,0,2)if(i<s||i>t-1)if(a[i]%2)return;
	rep(i,0,s-1)if(a[i])rep(j,i+1,s-1)if(!a[j])return;
	rep(i,t,2)if(a[i])rep(j,t,i-1)if(!a[j])return;
	
	cerr<<"OwO "<<s<<' '<<t<<endl;
	
	len=0;
	while(s>0&&a[s-1])a[s-1]--,ans[++len]=s,s--;
	int lst=n+1;while(t<3&&a[t])a[t]--,ans[--lst]=t,t++;
	rep(i,s,t-1)assert(a[i]%2);
	rep(i,s,t-1){
		ans[++len]=i;
		rep(j,1,a[i]/2)ans[++len]=i+1,ans[++len]=i;
	}
	ans[++len]=t;//assert(ans[])
	
//	assert(len==c[0]+c[1]+c[2]+c[3]);
	printf("YES\n");
	rep(i,1,n)printf("%d ",ans[i]);exit(0);
}
int main() {
	rep(i,0,3)read(c[i]);n=c[0]+c[1]+c[2]+c[3];
	rep(s,0,3)rep(t,s,3){
		rep(i,0,3)a[i]=c[i];//a[s]++;a[t]++;
		solve(s,t);
	}
	puts("NO");
	return 0;
}