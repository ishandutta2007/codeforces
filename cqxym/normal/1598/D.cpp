#include<iostream>
#include<vector> 
using namespace std;
#define R register int
#define L long long
#define N 200001
int a[N],b[N],ct[N];
vector<int>D[N];
L f[N];
inline L Calc(int x){
	return(x-1ll)*(x-2)*x/6;
}
inline void Solve(){
	int n;
	cin>>n;
	for(R i=1;i<=n;i++){
		D[i].clear();
		ct[i]=0;
	}
	L ans=0,sum=0;
	for(R i=0;i!=n;i++){
		cin>>a[i]>>b[i];
		D[a[i]].push_back(b[i]);
	}
	for(R i=1;i<=n;i++){
		int s=D[i].size();
		f[i]=f[i-1]+sum*s;
		ans+=f[i-1]*s+Calc(s)+(sum*s*(s-1)>>1);
		sum+=s;
		for(auto T:D[i]){
			ans-=(s-1ll)*ct[T];
			ct[T]++;
		}
	}
	for(R i=1;i<=n;i++){
		ct[i]=0;
	}
	sum=0;
	for(R i=n;i!=0;i--){
		int s=D[i].size();
		ans+=sum*s*(s-1)>>1;
		sum+=s;
		for(auto T:D[i]){
			ans-=(s-1ll)*ct[T];
			ct[T]++;
		}
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}