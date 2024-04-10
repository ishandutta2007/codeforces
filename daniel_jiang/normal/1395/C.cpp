/*
***


***
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=205;
ll n,m,a[N],b[N],ans,v[N][N];
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
	rd(n);rd(m);
	for(ll i=1;i<=n;i++) rd(a[i]);
	for(ll i=1;i<=m;i++) rd(b[i]);
	for(ll s=8;s>=0;s--){
		ll qaq=1;
		for(ll i=1;i<=n;i++){
			ll ok=0;
			for(ll j=1;j<=m;j++)
				if(v[i][j]==0&&(a[i]&b[j]&(1<<s))==0) ok=1;
			if(ok==0){
				qaq=0;
				break;
			}
		}
		if(qaq==0){
			ans+=(1<<s);
			continue;
		}
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=m;j++)
				if((a[i]&b[j]&(1<<s))!=0) v[i][j]=1;
	}
	wr(ans);puts("");
	return 0;
}