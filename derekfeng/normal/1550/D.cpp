#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
typedef long long ll;
int N,num,fac[300004],inv[300004];
int C(int a,int b){
	if(a<b)return 0;
	return (ll)fac[a]*inv[b]%MOD*inv[a-b]%MOD;
}
void init(){
	fac[0]=1;
	int m=3e5;
	for(int i=1;i<=m;i++)fac[i]=(ll)fac[i-1]*i%MOD;
	inv[1]=1;
	for(int i=2;i<=m;i++)inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	inv[0]=1;
	for(int i=1;i<=m;i++)inv[i]=(ll)inv[i]*inv[i-1]%MOD;
}
int T,n,l,r,num0,num1;
int L[400004],R[400004];
int q1[4000004],q2[400004];
int main(){
	init();
	cin>>T;
	while(T--){
		num0=num1=0;
		vector<int>all;
		cin>>n>>l>>r;
		int mn=1e9;
		for(int i=1;i<=n;i++){
			int LL=i-r,RR=i-l;
			L[i]=-LL;
			R[i]=RR;
			all.push_back(L[i]),all.push_back(R[i]);
			mn=min(mn,max(L[i],R[i]));
		}
		sort(all.begin(),all.end()),all.erase(unique(all.begin(),all.end()),all.end());
		int m=all.size();
		for(int i=0;i<=m;i++)q1[i]=q2[i]=0;
		for(int i=1;i<=n;i++){
			int lb=lower_bound(all.begin(),all.end(),L[i])-all.begin(),rb=lower_bound(all.begin(),all.end(),R[i])-all.begin();
			if(lb<rb)q1[lb+1]++;
			else q2[rb+1]++;
		}
		int lst=0;
		ll ans=0;
		for(int i=0;i<m;i++)if(all[i]<=mn){
			num0+=q1[i],num1+=q2[i];
			int MX=max(num0,num1),MN=min(num0,num1);
			if(MX>(n+1)/2)break;
			ll ceof;
			if(n%2==0){
				ceof=C(n-num0-num1,n/2-MN);
			}else{
				ceof=C(n-num0-num1,n/2-MN);
				ceof+=C(n-num0-num1,(n+1)/2-MN);
			}
			ans+=(ll)(all[i]-lst)*ceof%MOD;
			lst=all[i];
		}
		cout<<ans%MOD<<"\n";
	}
}