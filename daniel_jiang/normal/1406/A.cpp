// wish to get better qwq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=105;
ll T,n,cnt[N];
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
	rd(T);
	while(T--){
		rd(n);
		memset(cnt,0,sizeof(cnt));
		for(ll i=0,x;i<n;i++) rd(x),cnt[x]++;
		ll ans=0,op=0;
		for(ll i=0;i<N;i++){
			if(op==1&&cnt[i]==0){
				ans+=i;break;
			}
			if(op==0&&cnt[i]==0){
				ans+=i*2;break;
			}
			if(op==0&&cnt[i]==1){
				ans+=i;op=1;
			}
		}
		wr(ans);puts("");
	}
	return 0;
}