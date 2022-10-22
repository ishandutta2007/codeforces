#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
int n,j,d[100004],a[100004];
vector<int>v;
int Mod(ll a){
	return a>=MOD?a%MOD:a;
}
void getdiv(int x){
	v.clear();
	vector<int>w;
	for(int i=1;i*i<=x;i++)if(x%i==0){
		v.push_back(i);
		if(i*i!=x)w.push_back(x/i);
	}
	for(int i=(int)w.size()-1;i>=0;i--)v.push_back(w[i]);
}
int mypow(int x,int t){
	int ans=x,ret=1;
	while(t){
		if(t%2==1)ret=Mod(1ll*ret*ans);
		ans=Mod(1ll*ans*ans),t>>=1;
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);sort(a+1,a+1+n);
	j=1;
	int ret=0;
	for(int i=1;i<=a[n];i++){
		while(j<=n&&a[j]<i)j++;
		d[i]=n-j+1;
		getdiv(i);
		int cur=0;
		int ans=1,ans1=1;
		for(int j=(int)v.size()-1;j>=0;j--){
			int pw=mypow(j+1,d[v[j]]-cur);
			ans=1ll*ans*pw%MOD;
			if(j<(int)v.size()-2)ans1=Mod(1ll*ans1*pw);
			if(j==(int)v.size()-2)ans1=Mod(1ll*ans1*mypow(j+1,d[v[j]]));
			cur=d[v[j]];
		}
		if(i==1)ans1=0;
		ret=Mod(1ll*ret+ans-ans1+MOD);
	}
	cout<<ret;
}