#pragma GCC optimize("Ofast")
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
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 444444;
int n,x,prime[N],len,mrk[N];bool ok[N];
void getp(int n){
	rep(i,2,n){
		if(!mrk[i])prime[++len]=i;
		rep(j,1,len){
			if(i*prime[j]>n)break;
			mrk[i*prime[j]]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
	ok[1]=0;rep(i,2,n){
		int v=i,cnt=0;while(mrk[v])v/=mrk[v],cnt++;cnt+=v>1;
		ok[i]=cnt<=2;
	}
}
inline void qaq(int *f){
	int n=2e5;bitset<200200>w[101],a;rep(i,1,n)if(ok[i])a[i]=1;
	rep(i,1,n){
		for(f[i]=0;w[f[i]][i];f[i]++);w[f[i]]|=a<<i;
	}
}
int main() {
	read(n);read(x);getp(N-1);ok[x]=0;
	static int f[N],g[N];int mx=0;
	qaq(g);int v=0;while(n--){int a,b,c;read(a);read(b);read(c);v^=g[b-a]^g[c-b];}
	if(v){puts("Alice");puts("Bob");}
	else{puts("Bob");puts("Alice");}
	return 0;
	
	
	/*rep(i,1,200000){
		bool a[166];memset(a,0,sizeof(a));
		rep(k,1,i-1)if(ok[i-k])a[f[k]]=1;
		for(f[i]=0;a[f[i]];f[i]++);
		mx=max(mx,f[i]);if(i%10000==0)printf("mx[%d]:%d\n",i,mx);
		if(f[i]!=g[i]){printf("now = %d %d %d\n",i,f[i],g[i]);assert(f[i]==g[i]);}
	}*/
	//rep(i,1,70)printf("%d:%d\n",i,f[i]);
	
	/*static int sg[2333][2333];int n=300;rep(i,1,n)rep(j,1,n){
		bool a[999];memset(a,0,sizeof(a));
		rep(k,1,i-1)if(ok[i-k])a[sg[k][j]]=1;
		rep(k,1,j-1)if(ok[j-k])a[sg[i][k]]=1;
		for(sg[i][j]=0;a[sg[i][j]];sg[i][j]++);
	}
	rep(i,1,n)rep(j,1,n)assert(sg[i][j]==(f[i]^f[j]));
	rep(i,1,50){rep(j,1,24)printf("%2d ",sg[i][j]);puts("");}*/
	return 0;
}