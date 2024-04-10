#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
LL read(){
	char ch=getchar(); LL x=0,fl=1;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') fl=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch-'0');
	return x*fl;
}
const LL mod=1e9+7;

int main(){
	int T=read();
	while(T--){
		LL n=read();
		LL r=1LL,i=1LL,ans=0LL;
		while(r<=n){
			ans=(ans+n/r)%mod;
			LL g=__gcd(r,i);
			r=r/g*i;
			i++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}