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
const int N = 202000;
int n=7,p[N],ans[N];bool vis[N],fd;
void dfs(int dep){
	if(dep>n){
	//	rep(i,1,n)if(p[i]==i)return;
	//	rep(i,1,n)if(!((i&p[i])==0))return;
		fd=1;rep(i,1,n)ans[i]=p[i];
	//	printf("%d:",n);rep(i,1,n)printf("%d ",p[i]);puts("");
		return;
	}
	rep(i,1,n)if(!vis[i]&&dep!=i&&((dep&i)!=0)){
		vis[i]=1;p[dep]=i;
		dfs(dep+1);
		vis[i]=0;
	}
}
int main() {
	read(n);
	if(n&1)puts("NO");
	else{
		puts("YES");
		for(int i=n;i>=1;){
			int bit=0;rep(j,0,20)if(i>>j&1)bit=j;
			int j=(1<<bit+1)-1-i;
			rep(k,j,i)p[k]=i+j-k;
			i=j-1;
		}
		rep(i,1,n)printf("%d ",p[i]);puts("");
	}
	/*for(n=1;n<=15;n++){
		fd=0;dfs(1);printf("%d:%d\n",n,fd);
	}*/
	if(n<=7){
		dfs(1);
		if(!fd)puts("NO");
		else{
			puts("YES");rep(i,1,n)printf("%d ",ans[i]);puts("");
		}
	}
	else if((n&-n)==n)puts("NO");
	else{
		p[1]=3;p[3]=1;
		p[2]=6;p[6]=7;p[7]=2;
		p[4]=5;p[5]=4;
		for(int i=8;i<=n;i*=2){
			int j=min(2*i-1,n);
			rep(k,i,j-1)p[k]=k+1;p[j]=i;
		}
		puts("YES");rep(i,1,n)printf("%d ",p[i]);puts("");
	}
	return 0;
}