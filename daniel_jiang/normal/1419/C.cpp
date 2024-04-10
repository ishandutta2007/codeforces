// wish to get better qwq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e3+5;
ll t,n,a[N],x,sum,qaq,cnt;
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
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(t);
	while(t--){
		rd(n);rd(x);sum=qaq=cnt=0;
		for(ll i=0;i<n;i++) rd(a[i]),a[i]-=x,sum+=a[i],qaq=max(qaq,max(a[i],-a[i])),cnt+=(bool)(a[i]==0);
		if(qaq==0){
			cout<<0<<endl;
		}
		else if(sum==0||cnt){
			cout<<1<<endl;
		}
		else cout<<2<<endl;
	}
	return 0;
}