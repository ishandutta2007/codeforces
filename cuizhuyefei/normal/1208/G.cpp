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
const int N = 1020000;
int n,k,f[N],prime[N],len,mrk[N],phi[N];
void getp(int n){
	mrk[1]=1;phi[1]=1;
	rep(i,2,n){
		if(!mrk[i])prime[++len]=i,phi[i]=i-1;
		rep(j,1,len){
			if(i*prime[j]>n)break;
			mrk[i*prime[j]]=prime[j];
			phi[i*prime[j]]=prime[j]*phi[i];
			if(i%prime[j]==0)break;
			phi[i*prime[j]]=(prime[j]-1)*phi[i];
		}
	}
}
int main() {
	read(n);read(k);getp(n);
	if(k==1){printf("%d\n",3);return 0;}
//	if(k==2){printf("%d\n",6);return 0;}
	rep(i,3,n){
		f[i]=phi[i];
	//	if(i%2==0&&!mrk[i/2])f[i]++;
	}
//	rep(i,1,30)cerr<<i<<' '<<phi[i]<<' '<<f[i]<<endl;
	sort(f+3,f+n+1);
	ll res=0;rep(i,3,3+k-1)res+=f[i];
	cout<<res+2;
	return 0;
}