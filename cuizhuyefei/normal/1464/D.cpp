#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
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
template<class T> inline T Abs(const T &x){return x>0?x:-x;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1e6+11,mo=1e9+7;
int n,p[N],vis[N],cnt[N],ans[N];
int calc(Vi a){
	int res=0;per(i,8,4)res+=a[i],a[i-3]+=a[i];
	int tmp=min(a[1],a[2]);res+=tmp;a[1]-=tmp;a[2]-=tmp;
	res+=(a[1]+a[2])/3*2+a[2]/3;
	return res;
}
int main() {
	ans[3]=3;ans[4]=4;ans[5]=6;
	rep(i,6,N-1)ans[i]=3ll*ans[i-3]%mo;
	int T;read(T);while(T--){
		read(n);rep(i,1,n)read(p[i]),vis[i]=0,cnt[i]=0;
		rep(i,1,8)cnt[i]=0;
		rep(i,1,n)if(!vis[i]){
			int sz=0;
			for(int j=i;!vis[j];j=p[j])vis[j]=1,sz++;
			cnt[sz]++;
		}
		int cur=0,res=1e9;
		per(i,n,9)cur+=cnt[i],cnt[i-3]+=cnt[i],cnt[i]=0;
		if(n%3==0){res=calc(Vi(cnt,cnt+9));}
		else if(n%3==2){
			rep(i,2,8)if(cnt[i]){
				cnt[i]--;cnt[i-2]++;
				umin(res,(i!=2)+calc(Vi(cnt,cnt+9)));
				cnt[i]++;cnt[i-2]--;
			}
			if(cnt[1]>=2){
				cnt[1]-=2;umin(res,1+calc(Vi(cnt,cnt+9)));
			}
		}
		else{
			rep(i,4,8)if(cnt[i]){
				cnt[i]--;cnt[i-4]++;
				umin(res,(i!=4)+calc(Vi(cnt,cnt+9)));
				cnt[i]++;cnt[i-4]--;
			}
			if(cnt[1]&&cnt[3]){
				cnt[1]--;cnt[3]--;
				umin(res,1+calc(Vi(cnt,cnt+9)));
				cnt[1]++;cnt[3]++;
			}
			int cs=0;
			for(int t=0;t<=2;t++){
				rep(i,2,8)rep(j,i,8)if(cnt[i]&&cnt[j]&&(i!=j||cnt[i]>=2)){
					cnt[i]--;cnt[i-2]++;
					cnt[j]--;cnt[j-2]++;
					umin(res,cs+(i!=2)+(j!=2)+calc(Vi(cnt,cnt+9)));
					cnt[i]++;cnt[i-2]--;
					cnt[j]++;cnt[j-2]--;
				}
				if(cnt[1]>=2){
					cs++;cnt[1]-=2;cnt[2]++;
				}
			}
		//	while(cs--)cnt[1]+=2,cnt[2]--;
		}
		printf("%d %d\n",ans[n],res+cur);
	}
	return 0;
}