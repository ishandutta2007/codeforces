#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
int ans[20],ad[20];
void write(){
	if (ans[0]==0)putchar('-');
	short no0=0,go=0;
	for (int i=1;i<=19;i++){
		if (ans[i]!=0) no0=1;
		if (no0 && ans[i]==0) putchar(ans[i]+'0'),go=1;
		if (ans[i]!=0) putchar(ans[i]+'0'),go=1;
	}
	if (!go) putchar('0'); 
}
int n;
map<int,int> mp;
ll pr=0;
void got(ll add){
	ll addd=add;
	if (addd<0) addd*=-1;
	for (int i=19;i>=1;i--){
		ad[i]=addd%10;
		addd/=10;
	}
}
void add_(){
	for (int i=19;i>=1;i--) ans[i]+=ad[i];
	int ok=0;
	for (int i=19;i>=1;i--){
		if (ans[i]+ok>=10) ans[i]=(ans[i]+ok)%10,ok=1;
		else ans[i]+=ok,ok=0;
	}
}
int goswap(){
	for (int i=1;i<20;i++){
		if (ad[i]>ans[i]) return 1;
		if (ad[i]<ans[i]) return 0;
	}
	return 2;
}
void doit(){
	int get_=goswap();
	if (get_==1 || (get_==2 && ans[0]==0)) swap(ans,ad);
	int ok=0;
	for (int i=19;i>=1;i--){
		if (ans[i]>=ad[i]+ok){
			ans[i]-=ad[i]+ok;
			ok=0;
		}else{
			ans[i]-=ad[i]+ok-10;
			ok=1;
		}
	}
}
int main(){
	ans[0]=1;
	read(n);
	for (int i=1;i<=n;i++){
		int x;read(x);
		int lst=i-1-mp[x-1]-mp[x]-mp[x+1];
		ll add=1ll*x*lst-(pr-1ll*mp[x-1]*(x-1)-1ll*mp[x]*x-1ll*mp[x+1]*(x+1)); 
		if (add<0) ad[0]=0;else ad[0]=1;
		got(add);
		mp[x]++;
		if (ad[0]==ans[0]) add_();
		else doit();
		pr+=x;
	}
	write();
}