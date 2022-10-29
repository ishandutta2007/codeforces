// wish to get better qwq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,a,b,c,d,x,n;
string s;
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
		rd(n);a=b=c=d=0;
		cin>>s;
		for(ll i=0;i<n;i++){
			if(i%2==0&&s[i]%2==1) a=1;
			if(i%2==1&&s[i]%2==0) b=1;
		}
		if(n%2==1) puts(a?"1":"2");
		else puts(b?"2":"1");
	}
	return 0;
}