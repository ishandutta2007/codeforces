#include<iostream>
using namespace std;
#define R register int
#define INF 1000000001
int a[5001],f[5001];
inline int GetF(int x){
	if(f[x]==x){
		return x;
	}
	f[x]=GetF(f[x]);
	return f[x];
}
inline void Solve(){
	int n,st=1;
	long long ans=0;
	cin>>n;
	for(R i=1;i<=n;i++){
		cin>>a[i];
		f[i]=i;
	}
	while(true){
		if(st+a[st]>n){
			if(st==n){
				ans+=a[st]-1;
				cout<<ans<<endl;
				return; 
			}
			ans+=a[st]+st-n;
			a[st]=n-st; 
		}
		while(st<=n&&a[st]==1){
			st++;
		}
		if(st>n){
			cout<<ans<<endl;
			return;
		}
		int lt=st;
		while(lt<=n){
			lt=GetF(lt);
			int tem=lt+a[lt];
			if(a[lt]>1){
				a[lt]--;
			}
			if(a[lt]==1&&lt<n){
				f[GetF(lt)]=lt+1;
			}
			lt=tem;
		}
		ans++;
	}
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}