/*
***


***
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3e3+5;
ll a[N],sum[N][N],n,T,ans;
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
		rd(n);ans=0;
		for(ll i=1;i<=n;i++) rd(a[i]);
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++){
				if(a[i]==a[j]) sum[i][j]++;
				sum[i][j]=sum[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			}
		for(ll i=1;i<=n;i++)
			for(ll j=i+1;j<=n;j++)
				if(a[i]==a[j]) ans+=sum[j-1][n]-sum[i][n]-sum[j-1][j]+sum[i][j];
		wr(ans);puts("");
		if(T){
			for(ll i=0;i<=n;i++)
				for(ll j=0;j<=n;j++) sum[i][j]=0;
		}
	}
	return 0;
}