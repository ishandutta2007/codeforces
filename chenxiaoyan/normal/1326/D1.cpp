/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
const int N=1000000;
int n;
string a;
const int hbase1=131,hmod1=998244353,hbase2=13331,hmod2=1000000007;
int Hsh1[N+1],Rhsh1[N+2],hpw1[N+1],Hsh2[N+1],Rhsh2[N+2],hpw2[N+1];
void hsh_init(){
	hpw1[0]=hpw2[0]=1;
	for(int i=1;i<=n;i++)
		Hsh1[i]=(1ll*Hsh1[i-1]*hbase1+a[i])%hmod1,
		hpw1[i]=1ll*hpw1[i-1]*hbase1%hmod1,
		Hsh2[i]=(1ll*Hsh2[i-1]*hbase2+a[i])%hmod2,
		hpw2[i]=1ll*hpw2[i-1]*hbase2%hmod2;
	for(int i=n;i;i--)
		Rhsh1[i]=(1ll*Rhsh1[i+1]*hbase1+a[i])%hmod1,
		Rhsh2[i]=(1ll*Rhsh2[i+1]*hbase2+a[i])%hmod2;
}
pair<int,int> hsh(int l,int r){
	return mp(((Hsh1[r]-1ll*Hsh1[l-1]*hpw1[r-l+1]%hmod1)+hmod1)%hmod1,
			  ((Hsh2[r]-1ll*Hsh2[l-1]*hpw2[r-l+1]%hmod2)+hmod2)%hmod2);
}
pair<int,int> rhsh(int l,int r){
	return mp(((Rhsh1[l]-1ll*Rhsh1[r+1]*hpw1[r-l+1]%hmod1)+hmod1)%hmod1,
			  ((Rhsh2[l]-1ll*Rhsh2[r+1]*hpw2[r-l+1]%hmod2)+hmod2)%hmod2);
}
void mian(){
	cin>>a;
	n=a.size();
	a=" "+a;
	int now=0;
	while(now+1<=n/2&&a[now+1]==a[n-(now+1)+1])now++;
	if(n%2==0&&now==n/2){cout<<a.substr(1,n)<<"\n";return;}
	hsh_init();
	pair<int,int> ans;
	for(int i=n-now;i>now;i--){
		if(hsh(now+1,i)==rhsh(now+1,i))ans=max(ans,mp(i-now,1));
		if(hsh(i,n-now)==rhsh(i,n-now))ans=max(ans,mp(n-now-i+1,2));
	}
	for(int i=1;i<=now;i++)cout<<a[i];
	if(ans.Y==1){
		for(int i=now+1;i<=now+ans.X;i++)cout<<a[i];
	}
	else{
		for(int i=n-now-ans.X+1;i<=n-now;i++)cout<<a[i];
	}
	for(int i=now;i;i--)cout<<a[i];
	puts("");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}