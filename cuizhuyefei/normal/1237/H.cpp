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
const int N = 4444;
int n,a[N],b[N];Vi ans;
int Abs(int x){return x>0?x:-x;}
bool ck(){
	int x=0,y=0;
	for(int i=1;i<=n;i+=2)if(a[i]+a[i+1]==1)x+=a[i]?1:-1;
	for(int i=1;i<=n;i+=2)if(b[i]+b[i+1]==1)y+=b[i]?1:-1;
	return x+y==0;
}
void print(int x){
	if(x){ans.pb(x);reverse(a+1,a+x+1);}
}
void solve(){
	for(int i=0;i+1<n;i+=2){
		for(int j=i+2;j<=n;j+=2)if(a[j]==b[n-i-1]&&a[j-1]==b[n-i]){
			print(j-2);print(j);assert(a[1]==b[n-i-1]&&a[2]==b[n-i]);
			break;
		}
	}
}
int main() {
	int TT;read(TT);while(TT--){
		char S[N],T[N];
		scanf("%s%s",S+1,T+1);n=strlen(S+1);
		rep(i,1,n)a[i]=S[i]=='1',b[i]=T[i]=='1';
		int cnt[3]={0};
		for(int i=1;i<=n;i+=2){
			cnt[a[i]+a[i+1]]++,cnt[b[i]+b[i+1]]--;
		}
		if(cnt[0]||cnt[1]||cnt[2]){puts("-1");continue;}
		ans.clear();
		int x=0,y=0;
		for(int i=1;i<=n;i+=2)if(a[i]+a[i+1]==1)x+=a[i]?1:-1;
		for(int i=1;i<=n;i+=2)if(b[i]+b[i+1]==1)y+=b[i]?1:-1;
		if(Abs(x)>=Abs(y)){
			int p=0;
			if(!ck())for(int i=2;i<=n;i+=2){
				reverse(a+1,a+i+1);
				if(ck()){p=i;break;}
				reverse(a+1,a+i+1);
			}
			if(p)ans.pb(p);solve();
		}
		else{
			int p=0;
			if(!ck())for(int i=2;i<=n;i+=2){
				reverse(b+1,b+i+1);
				if(ck()){p=i;break;}
				reverse(b+1,b+i+1);
			}
			solve();if(p)ans.pb(p);
		}
		printf("%d\n",SZ(ans));rep(i,0,SZ(ans)-1)printf("%d ",ans[i]);puts("");
	}
	return 0;
}