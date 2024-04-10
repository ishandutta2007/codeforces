#include<iostream>
#include<algorithm>
using namespace std;
#define R register int
int a[70];
inline void Solve(){
	int n,ans=69,cur;
	cin>>n;
	for(R i=0;i!=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<0<<endl;
		return;
	}
	for(R i=1;i!=n;i++){
		for(R j=0;j!=i;j++){
			cur=n;
			double d=(double)(a[i]-a[j])/(i-j);
			for(R k=0;k!=n;k++){
				double p=d*(k-i)+a[i]-a[k];
				if(p>-1e-8&&p<1e-8){
					cur--;
				}
			}
			if(cur<ans){
				ans=cur;
			}
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