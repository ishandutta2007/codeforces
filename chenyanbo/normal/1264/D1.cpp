#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll MOD = 998244353;
 
char s[2005];
 
ll dmod(ll x){
	return x%MOD;
}
 
ll fe(ll x, ll p){
	if(p==0) return 1ll;
	if(p==1) return x;
	ll ret = fe(x,p/2);
	ret = dmod(ret*ret);
	if(p&1) ret = dmod(ret*x);
	return ret;
}
 
int ps[2005];
ll memo[2005][2005];
 
ll dp(int l, int r){
	if(l >= r) return 0;
	ll &ret = memo[l][r];
	if(ret!=-1) return ret;
	
	ret = 0;
	if(s[l] == '(' && s[r] == ')'){
		ret = dmod(dp(l+1,r-1) + fe(2ll,ps[r-1] - ps[l]));
	} else if(s[l] == ')'){
		ret = dp(l+1,r);
	} else if(s[r] == '('){
		ret = dp(l,r-1);
	} else if(s[l] == '?' && s[r] == '?'){
		ret = dmod(dp(l+1,r-1) + fe(2ll,ps[r-1] - ps[l])); //()
		ret = dmod(ret+dp(l+1,r));//)?
		ret = dmod(ret+dp(l,r-1));//?(
		ret = dmod(ret-dp(l+1,r-1)+MOD);
	} else if(s[l] == '?'){
		ret = (dp(l+1,r-1) + fe(2ll,ps[r-1] - ps[l]))%MOD; //()
		ret = (ret+dp(l+1,r))%MOD;//))
	} else {
		ret = (dp(l+1,r-1) + fe(2ll,ps[r-1] - ps[l]))%MOD; //()
		ret = (ret+dp(l,r-1))%MOD;//((
	}
	return ret;
}
 
 
int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%s",&s);
	int pan = strlen(s);
	for(int i=0;i<pan;i++){
		if(i!=0) ps[i] = ps[i-1];
		if(s[i] == '?') ps[i]++;
	}
	ll ans = dp(0,pan-1);
	printf("%lld\n",ans);
	return 0;
}