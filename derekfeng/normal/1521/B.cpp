#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,x,a[100004];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int M=min_element(a+1,a+1+n)-a;
		cout<<n-1<<"\n";
		for(int i=1;i<=n;i++)if(i!=M)
			cout<<i<<" "<<M<<" "<<a[M]+abs(i-M)<<" "<<a[M]<<"\n"; 
	}
}