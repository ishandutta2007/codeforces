#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int t,d,m,f[100],ans;
void solve(){
	scanf("%d%d",&d,&m);ans=f[0]=1;
	for(int i=1;(1<<i)<=d;i++){
		int k=(1<<i+1)<=d?1<<i:d-(1<<i)+1;
		int nn=1;
		for(int j=0;j<i;j++)(nn+=f[j])%=m;
		f[i]=1ll*nn*k%m;(ans+=f[i])%=m;
	}
	cout<<ans%m<<endl;
}
int main(){
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}