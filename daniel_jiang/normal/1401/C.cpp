/*
***


***
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll t,n,a[N],minn,fix[N],b[N];
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
ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(t);
	while(t--){
		rd(n);minn=1e9+5;
		for(ll i=1;i<=n;i++) rd(a[i]),b[i]=a[i],minn=min(minn,a[i]),fix[i]=0;
		sort(b+1,b+n+1);
		for(ll i=1;i<=n;i++)
			if(a[i]%minn) fix[i]=1;
		bool ans=1;
		for(ll i=1;i<=n;i++)
			if(fix[i]&&b[i]!=a[i]){
				cout<<"NO";ans=0;
				puts("");break;
			}
		if(ans) cout<<"YES";puts("");
	}
	return 0;
}