#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,n,T;
void rd(ll &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=fl;
}
void wr(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(T);
	while(T--){
		rd(n);
		rd(a);rd(b);
		for(ll i=3;i<=n;i++) rd(c);
		if(a+b>c) cout<<"-1",puts("");
		else cout<<"1 2 ",wr(n),puts("");
	}
	return 0;
}