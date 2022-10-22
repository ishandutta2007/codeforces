#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
ll k;
int a[N];
int main(){
	int i,j,p;
	int _;cin>>_;
	while(_--){
		cin>>n>>k;
		if(n<=60&&(1ll<<n-1)<k){
			cout<<-1<<endl;
			continue;
		}
		for(i=1;i<n-60;i++) a[i]=i;
		for(i=max(n-60,1);i<=n;i++){
			for(j=i;j<=n;j++){
				ll w=(1ll<<n-j-1);
				if(j==n) w=1;
				if(w>=k){
					for(p=j;p>=i;p--)
						a[i+j-p]=p;
					i=i+j-p-1;
					break;
				}
				else k-=w;
			}
		}
		for(i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}