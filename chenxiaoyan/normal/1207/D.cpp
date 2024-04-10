/*








 l l
*/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int inf=0x3f3f3f3f,mod=998244353;
const int N=300000;
int fact[N+1];
void fact_init(){
	fact[0]=1;
	for(int i=1;i<=300000;i++)fact[i]=1ll*fact[i-1]*i%mod;
}
int n;
pair<int,int> a[N+1];
bool cmp(pair<int,int> &x,pair<int,int> &y){return x.Y<y.Y;}
int main(){
	fact_init();
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].X>>a[i].Y;
	int ans1=1,ans2=1,ans3=1;
	sort(a+1,a+n+1);
	for(int i=1,ie;i<=n;i=ie+1){
		ie=i;while(a[i].X==a[ie].X)ie++;ie--;
		ans1=1ll*ans1*fact[ie-i+1]%mod;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1,ie;i<=n;i=ie+1){
		ie=i;while(a[i].Y==a[ie].Y)ie++;ie--;
		ans2=1ll*ans2*fact[ie-i+1]%mod;
	}
	sort(a+1,a+n+1);
	int mx=0;
	bool ok=false;
	for(int i=1,ie;i<=n;i=ie+1){
		int mn=inf;
		ie=i;while(a[i].X==a[ie].X)mn=min(mn,a[i].Y),ie++;ie--;
		if(mx>mn){ans3=ok=0;break;}
		for(int j=i;j<=ie;j++)mx=max(mx,a[j].Y);
	}
	for(int i=1,ie;i<=n;i=ie+1){
		ie=i;while(a[i]==a[ie])ie++;ie--;
		ans3=1ll*ans3*fact[ie-i+1]%mod;
	}
//	cout<<ans1<<" "<<ans2<<" "<<ans3<<"\n";
	cout<<(fact[n]-(ans1+ans2-ans3)%mod+mod)%mod;
	return 0;
}