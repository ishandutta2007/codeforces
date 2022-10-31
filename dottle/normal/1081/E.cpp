#include<bits/stdc++.h>
#define int long long
const int N=1000500;
using namespace std;

int n,a[N],s,ans[N];

main(){
	ios::sync_with_stdio(false);
	cin>>n,n/=2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=sqrt(a[i]);j;j--)
			if(a[i]%j==0){
				if((j+a[i]/j)%2)continue;
				int q=j+a[i]/j>>1,p=q-j;
				if(p*p>s){
					ans[i]=p*p-s,s=q*q;
					break;
				}
			}
		if(!ans[i])cout<<"No",exit(0);
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' '<<a[i]<<' ';
}