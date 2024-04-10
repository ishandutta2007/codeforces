#include<bits/stdc++.h>
using namespace std;
long long a[200003],n,k,last,ans;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(last+a[i]<k&&last!=0){
			ans++;
			last=0;
			continue;
		}
		ans+=(last+a[i])/k;
		last=(last+a[i])%k;
		//cout<<ans<<' '<<last<<endl;
	}
	if(last)cout<<ans+1;else cout<<ans;
}