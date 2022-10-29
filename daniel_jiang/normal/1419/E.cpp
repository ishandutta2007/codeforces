// wish to get better qwq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+5;
ll t,n,p[N],cnt,sum,a[(N<<1)],qaq[N],qwq[N],cc,maxn;
bool pri[N];
template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
void wr(ll x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}
void prime(ll x){
	pri[1]=1;
	for(ll i=2;i<=x;i++){
		if(!pri[i]) p[cnt++]=i;
		for(ll j=0;j<cnt&&i*p[j]<=x;j++){
			pri[i*p[j]]=1;
			if(!(i%p[j])) break;
		}
	}
}
void dfs(ll nw,ll x,ll sum){
	if(x==cc){
//		cout<<endl;
//		cout<<sum<<' '<<p[qwq[0]]<<' '<<maxn<<' '<<p[qwq[nw]]<<' '<<p[qwq[nw+1]]<<endl;
		if(sum!=p[qwq[0]]*maxn&&sum!=p[qwq[nw]]*p[qwq[nw+1]]) wr(sum),putchar(' ');
		return ;
	}
	ll awa=1;
	for(ll i=0;i<=qaq[qwq[x]];i++) dfs(nw,x+1,sum*awa),awa*=p[qwq[x]];
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(t);
	prime(N-5);
	while(t--){
		rd(n);sum=cc=maxn=0;
		a[sum++]=n;ll i=2;
		for(i=2;i*i<n;i++) if(n%i==0) a[sum++]=i,a[sum++]=n/i;
		if(i*i==n) a[sum++]=i;
		for(i=0;i<cnt;i++){
			qaq[i]=0;
			if(n%p[i]==0) qwq[cc++]=i,maxn=max(maxn,p[i]);
			while(n%p[i]==0) qaq[i]++,n/=p[i];
			if(n==1||p[i]*p[i]>n) break;
		}
		qaq[cnt]=0;
		if(n>1) qwq[cc++]=cnt,qaq[cnt]++,p[cnt]=n,maxn=max(maxn,n);
		if(sum==2){
			wr(a[0]),putchar(' '),wr(a[1]),puts("");
			wr(0);puts("");
			continue;
		}
		if(sum==3){
			if(a[1]*a[1]*a[1]==a[0]){
				wr(a[1]),putchar(' '),wr(a[2]),putchar(' '),wr(a[0]),puts("");
				wr(0);puts("");
			}
			else{
				wr(a[0]),putchar(' '),wr(a[1]),putchar(' '),wr(a[2]),puts("");
				wr(1);puts("");
			}
			continue;
		}
		if(cc==1){
			ll awa=1;
			for(ll i=1;i<=qaq[qwq[0]];i++) awa*=p[qwq[0]],wr(awa),putchar(' ');puts("");
			wr(0);puts("");
			continue;
		}
		ll awa=1;
		for(i=0;i<cc-1;i++){
			awa=1;
			for(ll j=1;j<=qaq[qwq[i]];j++) awa*=p[qwq[i]],dfs(i,i+1,awa);
			if(cc!=2) wr(p[qwq[i]]*p[qwq[i+1]]),putchar(' ');
		}
	//	cout<<"qwq"<<endl;
		for(i=1,awa=1;i<=qaq[qwq[cc-1]];i++) awa*=p[qwq[cc-1]],wr(awa),putchar(' ');
		wr(p[qwq[cc-1]]*p[qwq[0]]);puts("");
		wr(0);puts("");
	}
	return 0;
}