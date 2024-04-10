/*
***


***
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a,b,cnt;
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
	rd(n);rd(m);rd(a);rd(b);
	wr(a);putchar(' ');wr(b);puts("");
	if(b!=m){
		for(ll i=1;i<=m;i++)
			if(i!=b) wr(a),putchar(' '),wr(i),puts("");
	}
	else{
		for(ll i=m-1;i>0;i--) wr(a),putchar(' '),wr(i),puts("");
		cnt++;
	}
	for(ll i=1;i<=n;i++)
		if(i!=a){
			cnt++;
			if(cnt&1){
				for(ll j=m;j>0;j--) wr(i),putchar(' '),wr(j),puts("");
			}
			else{
				for(ll j=1;j<=m;j++) wr(i),putchar(' '),wr(j),puts("");
			}
		}
	return 0;
}