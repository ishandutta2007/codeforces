#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
const int mod=1e9+7;
int n,m,i,j,dp[1000005],sum,lst,mx;
char ss[1000005];
string st;
void upd(int x){
	int tmp=sum,i;
	for(i=0;i<=x;i++){
		sum=(sum-dp[i]+mod)%mod;
		dp[i]=tmp;
		sum=(sum+dp[i])%mod;
	}
}
int main(){
	scanf("%s",ss);
	st=ss;
	int c0=0,c1=0;
	while(!st.empty()&&st[st.size()-1]=='0'){
		c0++;st.erase(st.size()-1);
	}
	if(st.empty()){
		printf("%d\n",c0);
		return 0;
	}
	else{
		st.erase(st.size()-1);
	}
	reverse(st.begin(),st.end());
	while(!st.empty()&&st[st.size()-1]=='0'){
		c1++;st.erase(st.size()-1);
	}
	if(st.empty()){
		printf("%d\n",1ll*(c0+1)*(c1+1)%mod);
		return 0;
	}
	else{
		st.erase(st.size()-1);
	}
	reverse(st.begin(),st.end());
	sum=1;lst=0;
	for(i=0;i<st.size();i++){
		if(st[i]=='1'){
			mx=max(mx,lst);
			upd(lst);lst=0;
		}
		else{
			lst++;
		}
	}
	upd(lst);
	printf("%d\n",1ll*(c0+1)*(c1+1)%mod*sum%mod);
	return 0;
}