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
const int N = 1e6+3;
int mrk[N],prime[N],len;
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
void solve(int n){
	rep(del,0,n/3)if(!mrk[n+del]){
		printf("%d\n",n+del);
		rep(i,1,n)printf("%d %d\n",i,i+1<=n?i+1:1);
		rep(k,1,del)printf("%d %d\n",3*k,3*k-2);
		return;
	}
//	cerr<<n<<endl;
	for(int i=0;i*3<=n;i++)if((n-i*3)%4==0){
		int j=(n-i*3)/4;
		rep(del,0,j*2)if(!mrk[n+del]){
			vector<Pii>ans;
			int cur=0;
			rep(k,1,i){
				ans.pb(Pii(cur+1,cur+2));
				ans.pb(Pii(cur+2,cur+3));
				ans.pb(Pii(cur+1,cur+3));
				cur+=3;
			}
			rep(k,1,j){
				ans.pb(Pii(cur+1,cur+2));
				ans.pb(Pii(cur+2,cur+3));
				ans.pb(Pii(cur+3,cur+4));
				ans.pb(Pii(cur+1,cur+4));
				if(del)del--,ans.pb(Pii(cur+1,cur+3));
				if(del)del--,ans.pb(Pii(cur+2,cur+4));
				cur+=4;
			}
			printf("%d\n",SZ(ans));
			rep(i,0,SZ(ans)-1)printf("%d %d\n",ans[i].fi,ans[i].se);
			return;
		}
	}
}
int main() {
	getp(N-1);
	int n;read(n);solve(n);
	
	return 0;
}