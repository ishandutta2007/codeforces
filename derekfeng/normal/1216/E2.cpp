#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int q;
ll pw[19];
ll k;
string LtoS(ll x){
	string ret="";
	while(x){
		ret+=(char)(x%10+'0');
		x/=10;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
void solve(){
	scanf("%I64d",&k);
	ll cur=0;
	for(int i=1;;i++){
		ll num=pw[i]-pw[i-1];
		ll all=num*cur+(num*(num+1)/2)*i;
		if(all<k){
			k-=all;
			cur+=num*i;
		}else{
			ll l=0,r=pw[i]+1;
			while(r>l+1){
				ll mid=(l+r)>>1;
				ll cnt=mid*cur+(mid*(mid+1)/2)*i;
				if(cnt>=k)r=mid;
				else l=mid;
			}
			ll p=r-1;
			k-=p*cur+(p*(p+1)/2)*i;
			for(int j=1;;j++){
				ll pz=(pw[j]-pw[j-1])*j;
				if(pz<k)k-=pz;
				else{
					ll x=(k+j-1)/j;
					k-=(x-1)*j;
					x+=pw[j-1]-1;
					string S=LtoS(x);
					putchar(S[k-1]),puts("");
					return;
				}
			}
		}
	}
}
int main(){
	pw[0]=1;
	for(int i=1;i<19;i++)pw[i]=pw[i-1]*10;
	scanf("%d",&q);
	while(q--)solve();
}