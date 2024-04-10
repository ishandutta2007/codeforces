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
const int N = 402000;
int n,prime[N],len,mrk[N],c1,c2,a[N],ans[N];
void getp(int n){
	rep(i,2,n){
		if(!mrk[i])prime[++len]=i;
		rep(j,1,len){
			if(i*prime[j]>n)break;
			mrk[i*prime[j]]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
	mrk[1]=1;
}
int main() {
	read(n);getp(N-1);
	rep(i,1,n){
		int x;read(x);a[i]=x;
		if(x==1)c1++;else c2++;
	}
	int res=0;
	if(c1==0||c2==0){
	//	rep(i,1,n)a[i]+=a[i-1],res+=!mrk[a[i]];
		memcpy(ans,a,sizeof(a));
	}
	else{
		/*int now=3;res=2;c1--;c2--;
		while(c1>=2)c1-=2,c2++;
		while(c2--)now+=2,res+=!mrk[now];*/
		int len=0;c1--;c2--;ans[++len]=2;ans[++len]=1;
		while(c2--)ans[++len]=2;
		while(c1--)ans[++len]=1;
	}
	rep(i,1,n)printf("%d ",ans[i]);
	return 0;
}